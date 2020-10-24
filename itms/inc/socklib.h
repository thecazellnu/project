#ifndef __SOCKLIB_H__
#define __SOCKLIB_H__

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <pthread.h>

#ifndef LINUX
#define LINUX  1
#endif

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef ulong
#define ulong unsigned long
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef ERROR
#define ERROR -1
#endif

#ifndef NULL
#define NULL 0x00
#endif

#ifndef STX				
#define STX			0x02
#define ETX			0x03
#endif

#ifndef RING_BUFFER_SIZE
#define RING_BUFFER_SIZE	524288
#endif

#ifndef MAX_PACKET_LEN
#define MAX_PACKET_LEN	    65536
#endif 

#define DEF_PACKET_LEN	    8

#define SL_TOUT	    15

#define TS_START   2
#define TS_DATA    1
#define TS_CLOSE  -1
#define TS_TIMEOUT 0

class SockLib
{
public :
	int		m_id;
	int		m_Port;
	int		m_rfd;
	int		m_wfd;
	int 	m_plen;
	int		m_Connect;
	int		m_SocketType;
	int		m_SocketFamily;
	int		m_BlockPos;
	int		m_SocketBlock;
	int		m_TimeOut;
	char	m_Name[128];
	char	*m_DataBlock;
	int     (*m_handler)(SockLib *, int, int, char *, void *);
	void    *m_filler;
	pthread_t     m_tid;

	int		m_ErrorCode;
	char	m_ErrorMsg[128];

	struct	sockaddr_in	m_servaddr;
	struct	sockaddr_in	m_cliaddr;

	struct	sockaddr_in	m_sourceaddr;

	struct	sockaddr_un	m_servaddr_un;
	struct	sockaddr_un	m_cliaddr_un;
	char	m_socketpath[128];
	int		m_servlen;
	int		m_STX;            
	int		m_plenAdd;            

private:
	int		m_front;
	int		m_tail;
	char	m_RingBuff[RING_BUFFER_SIZE];
	pthread_mutex_t m_mutex;

public:
	SockLib();
	~SockLib();

	int Create(unsigned int nSocketPort = 0, char *szSocketAddress = NULL, 
		int nSocketType = SOCK_STREAM, int	nNewFd = -1);

	int Start();
	int StartDm();
	int Connect();
	int Connect(int time);
	int	Bind();
	int	Listen();
	int	Accept();
	int	Close();
	void Initial();
	int	Select(int sec, int usec);

	int	Read(char *data, int len);
	int	Write(char *data, int len);
	int	Write1(char *data, int len);
	int	RecvPacket(char *data);
	int CheckFd();
	int ClearTcpBuffer();
	int SetSocketSize(int nsize);
	int	SetSocketReuse();
	int	SetBlockSize(int bsize);
	int	SetBroadCast();

	int	Lock();
	int	UnLock();

	void SetTimeOut(int);
	void SetLENAdd(int);
	void SetBlockSocket(int);
	void GetMsg();
	void SetSTX(int);
	void GetAcpt();
	void SetPacketLength(int);
	void SetFiller(void *);
	int SetHandler(int (*handler)(SockLib *, int, int, char *, void *));
};

#endif
