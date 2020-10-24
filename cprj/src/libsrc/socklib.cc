#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#ifndef FreeBSD
#include <malloc.h>
#endif
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>

#ifdef SOLARIS
#include <sys/filio.h>
#include <sys/sockio.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>

#include <stdarg.h>
#ifdef GCC
#include <varargs.h>
#endif
#include <time.h>

#ifdef AIX
#include <sys/select.h>
#include <time.h>
#elsif AIX5
#include <sys/select.h>
#include <time.h>
else
#include <sys/time.h>
#endif

#include "socklib.h"
#include "log.h"

extern "C"
{
void *MsgLoop(void *);
void *AcceptLoop(void *);
}

SockLib::SockLib()
{
	memset(m_Name, 0, sizeof(m_Name));
	m_SocketType	= SOCK_STREAM;
	m_SocketFamily  = AF_INET;;

	m_tid       = 0;
	m_Port 		= 0;
	m_id 		= 0;
	m_Connect	= FALSE;
	m_rfd 	  	= -1;
	m_wfd 	  	= -1;
	m_plen		= DEF_PACKET_LEN;

	m_front   	= 0;
	m_tail    	= 0;

	m_filler    = NULL;
	m_BlockPos  = 0;
	m_DataBlock = NULL;
	m_ErrorCode = 0;
	m_SocketBlock = 1;
	m_STX = 0;
	m_plenAdd = 0;
	m_TimeOut = SL_TOUT;
	memset(m_ErrorMsg, 0, sizeof(m_ErrorMsg));

	pthread_mutex_init(&m_mutex, NULL);
}

SockLib::~SockLib()
{
	Close();
	if(m_DataBlock) free(m_DataBlock);

	pthread_mutex_destroy(&m_mutex);
}

int SockLib::Start()
{
    int rc;
    if((rc = pthread_create(&m_tid, NULL, MsgLoop, this)) != 0)
    {
        sprintf(m_ErrorMsg, "[%d:%s] Thread Create Error [%d][%d]",
            getpid(), __FILE__, m_tid, rc,errno);
        return -1;
    }
    return 1;
}

int SockLib::StartDm()
{
    int rc;
    if((rc = pthread_create(&m_tid, NULL, AcceptLoop, this)) != 0)
    {
        sprintf(m_ErrorMsg, "[%d:%s] Thread Create Error [%d][%d]",
            getpid(), __FILE__, m_tid, rc,errno);
        return -1;
    }
    return 1;
}

int SockLib::SetHandler(int (*handler)(SockLib *, int, int, char *, void *))
{
    m_handler = handler;
    if(m_handler == NULL) return -1;
    return 1;
}

void SockLib::SetBlockSocket(int i)
{
    m_SocketBlock = i;
}

//use STX  -> setting 
void SockLib::SetSTX(int i)
{
    m_STX = i;
}

void SockLib::Initial()
{
	m_front = m_tail = 0;
}

int SockLib::SetBlockSize(int size)
{
    if(m_DataBlock) return -1;
    if(size > 0) m_DataBlock = (char *)malloc(size);
    return size;
}

int SockLib::SetBroadCast()
{
    int on = 1;
    if(setsockopt(m_rfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0)
	{
        return -1;
	}
    return 1;
}

int SockLib::Create(unsigned int nSocketPort/* = 0*/, 
			char *szSocketAddress/*= NULL*/, 
			int nSocketType/*= SOCK_STREAM*/, int nNewFd/*= -1*/)
{
	struct  hostent		*hp;
	char	addr[30];
	int		on = 1;
	union	tagAddr
	{
		ulong	i_addr;
		uchar	c_addr[4];
	} strAddr;

	m_Port = nSocketPort;
	if(nNewFd >= 0)
	{
		m_rfd = m_wfd = nNewFd;
		int clilen = sizeof(m_cliaddr);
#ifdef SOLARIS
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr, &clilen) >= 0)
#elif HPUX
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr, &clilen) >= 0)
#elif AIX5
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr,
			(socklen_t *)&clilen) >= 0)
#elif FreeBSD
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr, &clilen) >= 0)
#elif OSF1
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr,
			(int *)&clilen) >= 0) 
#elif LINUX
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr,
			(socklen_t *)&clilen) >= 0) 
#else
		if(getpeername(m_rfd, (struct sockaddr *)&m_cliaddr,
			(size_t *)&clilen) >= 0) 
#endif
		{
#ifndef AIX_4_2
			strAddr.i_addr = (ulong) m_cliaddr.sin_addr.s_addr;
			sprintf(m_Name, "%03d.%03d.%03d.%03d",
				strAddr.c_addr[0],
				strAddr.c_addr[1],
				strAddr.c_addr[2],
				strAddr.c_addr[3]);
#else 
			sprintf(m_Name, "%s", inet_ntoa(m_cliaddr.sin_addr));
#endif
		}
		else 
		{
			strcpy(m_Name, "unknown");
		}
		SetSocketSize(MAX_PACKET_LEN);
		setsockopt(m_rfd,SOL_SOCKET,SO_KEEPALIVE,(char *)&on,sizeof(on));
		if(m_SocketBlock)
			ioctl(m_rfd, FIONBIO, (char *)&on); // Set Non Blocking I/O for Socket 
		m_Connect = TRUE;
	}
	else 
	{
		struct	servent		*sp;
		int		sockfd;

		memset((char *)&m_servaddr, 0, sizeof(m_servaddr));

		m_servaddr.sin_family		= AF_INET;
		m_servaddr.sin_port			= htons(nSocketPort);
		if(szSocketAddress == NULL)
		{
			m_servaddr.sin_addr.s_addr	= htonl(INADDR_ANY);
			strcpy(m_Name, "localhost");
		}
		else
		{
			strcpy(m_Name, szSocketAddress);
			if(m_Name[0] >= '0' && m_Name[0] <= '9') 
				strcpy(addr, m_Name);
			else {
				hp = gethostbyname(m_Name);
				if(hp == NULL)
				{
					sprintf(m_ErrorMsg, 
						"%s서버의 정보를 얻을 수 없어 접근이 불가능 합니다.", 
						m_Name);
					return ERROR;
				}
				sprintf(addr, "%d.%d.%d.%d",
					(uchar)hp->h_addr[0],(uchar)hp->h_addr[1],
					(uchar)hp->h_addr[2],(uchar)hp->h_addr[3]);
			}
			m_servaddr.sin_addr.s_addr = inet_addr(addr);
		}

		/* Open a TCP Socket */
		if((sockfd = socket(AF_INET, nSocketType, 0)) < 0) 
		{
			sprintf(m_ErrorMsg, "%s서버의 소켓 열기가  불가능 합니다. [%d]", 
				m_Name, errno);
			m_ErrorCode = errno;	
			return ERROR;
		}
		if(nSocketType == SOCK_DGRAM)
			m_servlen = sizeof(m_sourceaddr);
		m_rfd = m_wfd = sockfd;
	}
	m_SocketType = nSocketType;
	m_SocketFamily  = AF_INET;

	return m_rfd;
}

int SockLib::Bind()
{
	int on = 1;

	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
#ifdef AIX
	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#elif AIX_4_2
	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#endif

	if(m_SocketFamily == AF_INET)
	{
		if(bind(m_rfd,(struct sockaddr *)&m_servaddr,
					sizeof(struct sockaddr)) < 0) 
		{
			m_ErrorCode = errno;	
			return ERROR;
		}
	}
	else
	{
		if(bind(m_rfd,(struct sockaddr *)&m_servaddr_un,m_servlen) < 0) {
			m_ErrorCode = errno;	
			return ERROR;
		}
	}
	m_Connect = TRUE;

	if(m_SocketFamily == AF_INET && m_SocketType == SOCK_DGRAM)
		return TRUE;

	setsockopt(m_rfd,SOL_SOCKET,SO_KEEPALIVE,(char *)&on,sizeof(on));
	if(m_SocketBlock)
	{
		ioctl(m_rfd, FIONBIO, (char *)&on); // Set Non Blocking I/O for Socket 

#ifdef NON_BLOCK_FCNTL
{
	/* 4Set socket nonblocking */
	int flags = fcntl(m_rfd, F_GETFL, 0);
	fcntl(m_rfd, F_SETFL, flags | O_NONBLOCK);
}
#endif
	}

	return TRUE;
}

int SockLib::Listen()
{
	listen(m_rfd, 64);
	m_Connect = TRUE;
	return TRUE;
}

int SockLib::Accept()
{
	int		clilen, newfd;
	int		n, rc;

	if(m_SocketFamily == AF_INET)
	{
		clilen = sizeof(m_cliaddr);
#ifdef SOLARIS
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,&clilen);
#elif HPUX
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,&clilen);
#elif FreeBSD
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,&clilen);
#elif LINUX
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,
							(socklen_t *)&clilen);
#elif AIX_4_2
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,
							(size_t *)&clilen);
#elif OSF1
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,
							(int *)&clilen);
#else
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr,
							(socklen_t *)&clilen);
#endif
	}
	else
	{
		clilen = sizeof(m_cliaddr_un);
#ifdef SOLARIS
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,&clilen);
#elif HPUX
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,&clilen);
#elif FreeBSD
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,&clilen);
#elif LINUX
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,
						(socklen_t *)&clilen);
#elif AIX_4_2
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,
						(size_t *)&clilen);
#elif OSF1
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,
						(int *)&clilen);
#else 
		newfd = accept(m_rfd,(struct sockaddr *)&m_cliaddr_un,
						(socklen_t *)&clilen);
#endif
	}
	return newfd;
}

int SockLib::Connect()
{
	int on = 1;

	if(m_SocketFamily == AF_INET)
	{
		if (connect(m_rfd,(struct sockaddr *)&m_servaddr,sizeof(m_servaddr))<0)
		{
			sprintf(m_ErrorMsg,"%s서버의 접속이 불가능 합니다.[%d](Connect)", 
					m_Name, errno);
			close(m_rfd);
			m_rfd = m_wfd = -1;
			return FALSE;
		}
	}
	else
	{
		if(connect(m_rfd, (struct sockaddr *) &m_servaddr_un, m_servlen) < 0) 
		{
			sprintf(m_ErrorMsg,"%s서버의 접속이 불가능 합니다.[%d](Connect)", 
					m_Name, errno);
			close(m_rfd);
			m_rfd = m_wfd = -1;
			return FALSE;
		}

	}
	SetSocketSize(MAX_PACKET_LEN);
	setsockopt(m_rfd,SOL_SOCKET,SO_KEEPALIVE,(char *)&on,sizeof(on));
	if(m_SocketBlock)
		ioctl(m_rfd, FIONBIO, (char *)&on); // Set Non Blocking I/O for Socket 
	m_Connect = TRUE;
	return TRUE;
}

int SockLib::Connect(int Time)
{
	int on = 1;
	
	// 4Set socket nonblocking 
	int flags = fcntl(m_rfd, F_GETFL, 0);
	fcntl(m_rfd, F_SETFL, flags | O_NONBLOCK);

	if(m_SocketFamily == AF_INET)
	{
		connect(m_rfd,(struct sockaddr *)&m_servaddr,sizeof(m_servaddr));
	}
	else
		connect(m_rfd, (struct sockaddr *) &m_servaddr_un, m_servlen);

	struct  timeval     timeout;
	fd_set  event;
	int     maxfd, rc, cnt = 0;

	while(cnt < (Time*100))
	{
		if(errno == 0)
		{
			m_Connect = TRUE;
			return 1;
		}

		timeout.tv_sec = 0;     /* Second */
		timeout.tv_usec = 1000;        /* micro Second */
		maxfd = m_rfd + 1;

		FD_ZERO(&event);
		FD_SET(m_rfd, &event);
		rc = select(maxfd, &event, (fd_set *)0, (fd_set *)0,
				(struct timeval *)&timeout);
		switch(errno)
		{
		case ETIMEDOUT   	: return 0; /* Connection timed out */
		case ECONNREFUSED   : return 0; /* Connection refused */
		case EHOSTDOWN   	: return 0; /* Host is down */
		case EHOSTUNREACH   : return 0; /* No route to host */
		case EWOULDBLOCK 	: break;
		case EALREADY    	: return 0; /* operation already in progress */
		case EINPROGRESS 	: break; /* operation now in progress */
		}
		cnt++;
	}

	errno = ETIMEDOUT;
	return FALSE;
}

int SockLib::Select(int sec, int usec)
{
	struct  timeval     timeout;
	fd_set  event;
	int     maxfd, rc;

	if(m_rfd < 0) return ERROR;

	timeout.tv_sec = sec;     /* Second */
	timeout.tv_usec = usec;        /* micro Second */
	maxfd = m_rfd + 1;
	FD_ZERO(&event);
	FD_SET(m_rfd, &event);
	rc = select(maxfd, &event, (fd_set *)0, (fd_set *)0,
			(struct timeval *)&timeout);
	if(rc > 0)
	{
		if(FD_ISSET(m_rfd, &event)) 
			return TRUE;
		else
			return ERROR;
	}
	return rc;
}

int SockLib::Close()
{
	if(m_rfd >= 0)
	{
		if(m_SocketType == SOCK_STREAM) shutdown(m_rfd, 2);
		close(m_rfd);
	}
	m_rfd = m_wfd = -1;
	m_Connect = FALSE;
	return TRUE;
}

int	SockLib::SetSocketSize(int nsize)
{
	int		blen;

	blen = nsize;
	setsockopt(m_rfd,SOL_SOCKET,SO_SNDBUF,(char *)&blen,sizeof(blen));
	setsockopt(m_rfd,SOL_SOCKET,SO_RCVBUF,(char *)&blen,sizeof(blen));
	return TRUE;
}

int	SockLib::SetSocketReuse()
{
	int on = 1;
	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
#ifdef AIX
	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#elif AIX_4_2
	setsockopt(m_rfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#endif
	return TRUE;
}

int SockLib::ClearTcpBuffer()
{
#ifdef BIT64
    int count;
#else
    long count;
#endif
	int rc = ioctl(m_rfd, FIONREAD, &count);
	if(rc > 0)
	{
		char buff[1024];
		int n = 0, nRead;
		while(n < count)
		{
			nRead = read(m_rfd, buff, 1024);
			n += nRead;
			if(nRead <= 0) break;
		}
	}
	return count;
}

int SockLib::CheckFd()
{
	char   tmpbuff[MAX_PACKET_LEN];
   	int    	n, rlen, pos;

   	if ((n = read(m_rfd, tmpbuff, MAX_PACKET_LEN)) > 0) 
	{
   		rlen = 0;
		pos = m_front;
   		while(rlen < n) 
		{
   	    	m_RingBuff[pos] = tmpbuff[rlen];
   		 	pos++;
   			pos %= RING_BUFFER_SIZE;
			if (pos == m_tail) 
			{
				m_tail = m_front;
			}
			rlen++;
		}
		m_front = pos;
		return n;
   	}
	return 0;
}

int SockLib::Read(char *buff, int len)
{
    int    	n;
	if(m_rfd < 0) return -1;
   	n = read(m_rfd, buff, len);
	return n;
}

int SockLib::Write(char *ptr, int nbyte)
{
	int	nleft, nwritten, errcnt = 0;

	if(m_Connect == FALSE)  return -1;
	if(m_wfd < 0)           return -1;

	nleft = nbyte;

	while(nleft > 0)
	{
		nwritten = write(m_wfd, ptr, nleft);
		if(nwritten <= 0)
		{
			/* 왠지 모르지만 EP3500에서 EWOUKDBLOCK Error가 아니고 
							errno==0이 발생*/
#ifdef AIX
			if (errcnt > 200)   
#else
			if (errcnt > 300)   // 30 -> 300
#endif
			{
				sprintf(m_ErrorMsg, "[%s] CSOCKET: EWOULDBLOCK Error[%d][%d]", 
					__FILE__, errno, errcnt);
				return -1;
			}
			if(m_Connect == FALSE)
			{
				sprintf(m_ErrorMsg, "[%s] CSOCKET: Write중 Connect FALSE [%d][%d]", 
					__FILE__, errno, errcnt);
				return -1;
			}
			usleep(100000);
			errcnt++;
			continue;
		}
		else
		{
			;
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return nbyte;
}

int	SockLib::RecvPacket(char *data)
{
	int		i, pos, len;
	int		plen;
	char	tmp[32];

	if (m_front == m_tail) 
		return 0;
	pos = m_tail;

	plen = m_plen + m_STX;

	for(i = 0;i < plen;i ++) 
	{
		tmp[i] = m_RingBuff[pos++];
		pos %= RING_BUFFER_SIZE;
		if(pos == m_front) 
		{
			break;
		}
	}
	if(i < plen) return 0;
	tmp[plen] = (char )NULL;
	len = atoi(tmp + m_STX);

	if(m_plenAdd) len -= plen;

    if(m_front > pos)
	{
		if((m_front - pos) < len) return 0;
	}
	else if(m_front == pos) return 0;
	else
	{
		if(((RING_BUFFER_SIZE - pos) + m_front) < len) return 0;
	}

	memcpy(data, tmp, plen);
	len += plen;
	if(len > MAX_PACKET_LEN)
	{
		m_front = m_tail = 0;
		return 0;
	}
	int n = plen;
	for(i = plen;i < len;i ++) 
	{
		data[n++] = m_RingBuff[pos++];
		pos %= RING_BUFFER_SIZE;
		if(pos == m_front) 
		{
			if(n < len) return 0;
			break;
		}
	}
	m_tail = pos;
	return len;
}

//Header->lengthField value = total len  setting 1
void SockLib::SetLENAdd(int tmp)
{
	m_plenAdd = tmp;
}

//Header->lengthField Length
void SockLib::SetPacketLength(int len)
{
	m_plen = len;
}

void SockLib::SetTimeOut(int tmp)
{
	m_TimeOut = tmp;
}

void SockLib::SetFiller(void *temp)
{
	m_filler = temp;
}

void SockLib::GetMsg()
{
    int n = 1, rc = -1;
    char buff[MAX_PACKET_LEN];

    if(m_handler == NULL)
    {
        sprintf(m_ErrorMsg, "[%d:%s] SockLib Member(handler)Nothing", getpid(), __FILE__);
        return;
    }

	if(m_handler(this, TS_START, (int)NULL, NULL, m_filler) < 0)
	{
		m_tid = -1;
		Close();
		return;
	}

    while(m_Connect && rc)
    {
		n = Select(m_TimeOut, 0);
        if(n > 0)
        {
			if(m_SocketBlock)
			{
				if(CheckFd() <= 0) break;
				while((n = RecvPacket(buff)) > 0)
					rc = m_handler(this, TS_DATA, n, buff, m_filler);
			}
			else 
			{
				if ((n = read(m_rfd, buff, MAX_PACKET_LEN)) > 0) 
					rc = m_handler(this, TS_DATA, n, buff, m_filler);
				else break;
			}
		}
        else if (n == 0)
		{
            rc = m_handler(this, TS_TIMEOUT, rc, NULL, m_filler);
		}
		else 
		{
		}

    }
    m_tid = -1;
    Close();

    m_handler(this, TS_CLOSE, rc, NULL, m_filler);
	return;
}

void SockLib::GetAcpt()
{
    int n, rc = 1;

    if(m_handler == NULL)
    {
        sprintf(m_ErrorMsg, "[%d:%s] SockLib Member(handler)Nothing", getpid(), __FILE__);
        return;
    }

	if(m_handler(this, TS_START, (int)NULL, NULL, m_filler) < 0)
	{
		m_tid = -1;
		Close();
		return;
	}

    while((m_tid > 0) && rc)
    {
		if(Select(m_TimeOut, 0) > 0)
		{
			n = Accept();
			if(n > 0)
			{
				rc = m_handler(this, TS_DATA, n, NULL, m_filler);
			}
		}				
    }
    m_tid = -1;
    Close();

    m_handler(this, TS_CLOSE, (int)NULL, NULL, m_filler);
	return;
}

void *MsgLoop(void *arg)
{
	SockLib *Class = (SockLib *)arg;
	pthread_detach(Class->m_tid);

	Class->GetMsg();

    return (void *)NULL;
}

void *AcceptLoop(void *arg)
{
	SockLib *Class = (SockLib *)arg;
	pthread_detach(Class->m_tid);

	Class->GetAcpt();

    return (void *)NULL;
}

int	SockLib::Lock()
{
	return pthread_mutex_lock(&m_mutex);
}

int	SockLib::UnLock()
{
	return pthread_mutex_unlock(&m_mutex);
}
