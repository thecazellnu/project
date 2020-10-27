
#define TCP_SERVER


/*
 * 서버 Connect
 */
int ServerConnect (FILE *LogFD, lpFepCfgSt lpFepCfg, int port)
{
	int	fd;
	int	fep_port;

	// Main 서버에 접속
	fep_port = (port == 0) ? lpFepCfg->MainPort : port;
	PutFmtLog(LogFD,"[%s][%d]\n",lpFepCfg->MainSvr,fep_port);
	if ((fd = tcp_c_open (lpFepCfg->MainSvr, fep_port)) < 0)
	{
		PutFmtLog (LogFD, "MAIN : tcp_c_open [%s] Port[%d] errno[%d]\n", 
					lpFepCfg->MainSvr,fep_port,errno);

		// Backup 서버에 접속
		fep_port = (port == 0) ? lpFepCfg->BackPort : port;
		if ((fd = tcp_c_open (lpFepCfg->BackSvr, fep_port)) < 0)
		{
			PutFmtLog (LogFD, "BACK : tcp_c_open [%s] Port[%d] errno[%d]\n", 
						lpFepCfg->BackSvr,fep_port,errno);
			return -1;
		}
	}

	return fd;
}

/*
 * 서버 Close
 */
int ServerClose (int fd)
{
	shutdown (fd, 2);
	close (fd);
	return 0;
}

/*
 * 헤더를 만듬
 */
int MakeFepHeader (unsigned char *buf, char *MsgType, lpFepCfgSt lpFepCfg)
{
	lpFEP_HEADER lpFep = (lpFEP_HEADER) buf;

	// 현재날자/시간
	GetDateTime();

	lpFep->Stx[0] = STX;
	MyItoa (lpFep->Length, SZ_FEP_HEADER, sizeof (lpFep->Length));
	// 업무구분 
	memcpy (lpFep->ApType, lpFepCfg->Job, 		
				MIN (sizeof (lpFep->ApType), strlen (lpFepCfg->Job)));
	// 업무장비
	//memcpy (lpFep->SysType, FEP_SYS_TYPE, sizeof (lpFep->SysType));
	//20170307 cjm
	if(strlen(lpFepCfg->Job) > 6)
	{
		memcpy (lpFep->SysType, &lpFepCfg->Job[6], sizeof(lpFep->SysType));
	}
	else
	{
		memcpy (lpFep->SysType, FEP_SYS_TYPE, sizeof (lpFep->SysType));
	}
  	// 운영코드
	memcpy (lpFep->MsgType, MsgType, sizeof (lpFep->MsgType));
	// 일자
	memcpy (lpFep->Date, TimeBuf.nDate, sizeof (lpFep->Date));
//	memcpy (lpFep->Date, "20080328", sizeof (lpFep->Date));
	// 시각
	memcpy (lpFep->Time, TimeBuf.nTime, sizeof (lpFep->Time));
	// 일련번호
	memset (lpFep->SeqNo, '0', SZ_SEQ);

	return 0;
}

/*
 * FEP에 LIVE를 보내고 LIOK를 받음
 */
int FepLive(FILE *LogFD, int SockFD, int SeqFD, lpFepCfgSt lpFepCfg)
{
	unsigned char buf[80];
	lpFEP_HEADER lpFep = (lpFEP_HEADER) buf;

	memset (buf, ' ', sizeof (buf));
	MakeFepHeader (buf, "LIVE", lpFepCfg);

	/* 헤더정보를 보냄 */
	if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
		return -1;

	memset (buf, 0x20, sizeof (buf));
	if (DataRead (LogFD, SockFD, buf, SZ_FEP_HEADER, WAIT) < 0)
		return -1;

	/* 응답확인 */
	if (memcmp (lpFep->MsgType, "LIOK", sizeof (lpFep->MsgType)))
	{
		PutFmtLog (LogFD, "FepLive() MsgType err[%.*s]\n", 
					sizeof (lpFep->MsgType), lpFep->MsgType);
		return -1;
	}
	if (memcmp (lpFep->ResponseCode, "00", sizeof (lpFep->ResponseCode)))
	{
		PutFmtLog (LogFD, "FepLive() ResponseCode err[%.*s]\n", 
					sizeof (lpFep->ResponseCode), lpFep->ResponseCode);
		return -1;
	}

	return 0;
}

/* 
 * FEP로 포트를 얻음
 */
int GetFepPort (FILE *LogFD, int SockFD, lpFepCfgSt lpFepCfg)
{
	unsigned char buf[80];
	lpFEP_HEADER lpFep = (lpFEP_HEADER) buf;

	memset (buf, 0x20, sizeof (buf));
	MakeFepHeader (buf, "LINK", lpFepCfg);

	/* 헤더정보를 보냄 */
	if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
		return -1;

	memset (buf, 0x20, sizeof (buf));
	if (DataRead (LogFD, SockFD, buf, SZ_FEP_HEADER, WAIT) < 0)
		return -1;

	/* 응답확인 */
	if (memcmp (lpFep->MsgType, "LIOK", sizeof (lpFep->MsgType)))
	{
		PutFmtLog (LogFD, "GetFepPort() MsgType err[%.*s]\n", 
					sizeof (lpFep->MsgType), lpFep->MsgType);
		return -1;
	}
	if (memcmp (lpFep->ResponseCode, "00", sizeof (lpFep->ResponseCode)))
	{
		PutFmtLog (LogFD, "GetFepPort() ResponseCode err[%.*s]\n", 
					sizeof (lpFep->ResponseCode), lpFep->ResponseCode);
		return -1;
	}

	/* 포트번호를 return */
	return MyAtoi (lpFep->SeqNo, SZ_SEQ);
}

/*
 * FEP 개시요구
 */
int FepStrt_ch (FILE *LogFD, int SockFD, int SeqFD, lpFepCfgSt lpFepCfg, int type, char gb)
{
	char seqbuf[100];
	unsigned char buf[80];
    lpFEP_HEADER lpFep = (lpFEP_HEADER) buf;

    memset (buf, 0x20, sizeof (buf));
    MakeFepHeader (buf, "STRT", lpFepCfg);
PutFmtLog(LogFD,"FepStrt_ch:gb[%c]\n",gb);

    /* 헤더정보를 보냄 */
    if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
        return -1;

    memset (buf, 0x20, sizeof (buf));
    if (DataRead (LogFD, SockFD, buf, SZ_FEP_HEADER, WAIT) < 0)
        return -1;

    /* 응답확인 */
    if (memcmp (lpFep->MsgType, "STOK", sizeof (lpFep->MsgType)))
    {
        PutFmtLog (LogFD, "FepStrt() MsgType err[%.*s]\n",
                    sizeof (lpFep->MsgType), lpFep->MsgType);
        return -1;
    }
    if (memcmp (lpFep->ResponseCode, "00", sizeof (lpFep->ResponseCode)))
    {
        PutFmtLog (LogFD, "FepStrt() ResponseCode err[%.*s]\n",
                    sizeof (lpFep->ResponseCode), lpFep->ResponseCode);
        return -1;
    }

    // 응답 프로세스일경우 RESE로 응답을 해줌
    if (RECV ==  type)
    {
        memcpy (lpFep->MsgType, "RESE", sizeof (lpFep->MsgType));
		if(gb == '1')
		{
			PutFmtLog(LogFD,"===start gb[%d]\n",gb);
			memset(lpFep->SeqNo, '0', sizeof(lpFep->SeqNo));
		}
		else if(gb == '0')
		{
			memset(seqbuf,0x00,sizeof(seqbuf));
			if (SeqFileRead (LogFD, SeqFD, SEEK_SET, seqbuf, SZ_SEQ) >= 0)
			{
				memcpy(lpFep->SeqNo,seqbuf,SZ_SEQ);					
			}
		}
        if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
            return -1;

        /* 09.04.30 : 응답으로 받은 SeqNo 세트 */
        SeqFileWrite (LogFD, SeqFD, SEEK_SET, lpFep->SeqNo, SZ_SEQ);
    }
    else
    {
        /* 응답으로 받은 SeqNo 세트 */
        SeqFileWrite (LogFD, SeqFD, SEEK_SET, lpFep->SeqNo, SZ_SEQ);
    }

    return 0;
}

/*
 * FEP 개시요구
 */
int FepStrt (FILE *LogFD, int SockFD, int SeqFD, lpFepCfgSt lpFepCfg, int type)
{
	unsigned char buf[80];
	lpFEP_HEADER lpFep = (lpFEP_HEADER) buf;

	memset (buf, 0x20, sizeof (buf));
	MakeFepHeader (buf, "STRT", lpFepCfg);

	/* 헤더정보를 보냄 */
	if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
		return -1;

	memset (buf, 0x20, sizeof (buf));
	if (DataRead (LogFD, SockFD, buf, SZ_FEP_HEADER, WAIT) < 0)
		return -1;

	/* 응답확인 */
	if (memcmp (lpFep->MsgType, "STOK", sizeof (lpFep->MsgType)))
	{
		PutFmtLog (LogFD, "FepStrt() MsgType err[%.*s]\n", 
					sizeof (lpFep->MsgType), lpFep->MsgType);
		return -1;
	}
	if (memcmp (lpFep->ResponseCode, "00", sizeof (lpFep->ResponseCode)))
	{
		PutFmtLog (LogFD, "FepStrt() ResponseCode err[%.*s]\n", 
					sizeof (lpFep->ResponseCode), lpFep->ResponseCode);
		return -1;
	}

	// 응답 프로세스일경우 RESE로 응답을 해줌
	if (RECV ==  type)
	{
		memcpy (lpFep->MsgType, "RESE", sizeof (lpFep->MsgType));
		if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
			return -1;

		/* 09.04.30 : 응답으로 받은 SeqNo 세트 */
		SeqFileWrite (LogFD, SeqFD, SEEK_SET, lpFep->SeqNo, SZ_SEQ);
	}
	else
	{
		/* 응답으로 받은 SeqNo 세트 */
		SeqFileWrite (LogFD, SeqFD, SEEK_SET, lpFep->SeqNo, SZ_SEQ);
	}

	return 0;
}

/*
 * FEP LINK
 */
int FepLink_ch (FILE *LogFD, int SeqFD, lpFepCfgSt lpFepCfg, int type, char gb)
{
	int fd;
    int fep_port;

    // FEP 와 접속
    if ((fd = ServerConnect (LogFD, lpFepCfg, 0)) < 0)
        return -1;

    // FEP와 LINK해서 포트를 얻음
    if ((fep_port = GetFepPort (LogFD, fd, lpFepCfg)) < 0)
    {
        ServerClose (fd);
        return -1;
    }

    // FEP와 재접속
    ServerClose (fd);
    if ((fd = ServerConnect (LogFD, lpFepCfg, fep_port)) < 0)
        return -1;

    // 개시요구
    if (FepStrt_ch (LogFD, fd, SeqFD, lpFepCfg, type, gb) < 0)
    {
        PutFmtLog(LogFD,"FepLink:FepStrt Fail...[%d]\n",fd);
        ServerClose(fd);
        return -1;
    }

    return fd;	
}
/* 
 * FEP LINK
 */
int FepLink (FILE *LogFD, int SeqFD, lpFepCfgSt lpFepCfg, int type)
{
	int	fd;
	int	fep_port;

	// FEP 와 접속
	if ((fd = ServerConnect (LogFD, lpFepCfg, 0)) < 0)
		return -1;

	// FEP와 LINK해서 포트를 얻음
	if ((fep_port = GetFepPort (LogFD, fd, lpFepCfg)) < 0)
	{
		ServerClose (fd);
		return -1;
	}

	// FEP와 재접속
	ServerClose (fd);
	if ((fd = ServerConnect (LogFD, lpFepCfg, fep_port)) < 0)
		return -1;

	// 개시요구
	if (FepStrt (LogFD, fd, SeqFD, lpFepCfg, type) < 0)
	{
		PutFmtLog(LogFD,"FepLink:FepStrt Fail...[%d]\n",fd);
        ServerClose(fd);
		return -1;
	}
	
	return fd;
}

/*
 * FEP에 STOP를 보냄
 */
int FepStop(FILE *LogFD, int SockFD, lpFepCfgSt lpFepCfg)
{
	unsigned char buf[80];

	memset (buf, ' ', sizeof (buf));
	MakeFepHeader (buf, "STOP", lpFepCfg);

	/* 헤더정보를 보냄 */
	if (DataWrite (LogFD, SockFD, buf, SZ_FEP_HEADER) < 0)
		return -1;

	return 0;
}


//#ifndef	FEP_CFG

/*
 * CFG 환경화일을 읽음
 */
int ReadCfg (FILE *LogFD, char *CfgGbn, lpFepCfgSt lpFepCfg)
{
	int		i, qid;
	int		sw;
	int 	CfgCnt;				/* 환경화일의 Cnt */
	Cfg_st	Cfg[MAX_CFG];		/* cfg환경화일 Buffer */
	int		shmid;
	key_t	shmkey;

	/* 환경화일을 읽어서 세트 */
	if ((CfgCnt = ReadCfgFile (LogFD, CFG_DIR, FEP_CFG, Cfg)) < 0)
		return -1;

	for (i = 0, sw = 0; i < CfgCnt; i++)
	{
		if (!strcmp (CfgGbn, Cfg[i].Fld[FEP_GBN]))
		{
			/* Main 서버명을 얻음 */
			strcpy (lpFepCfg->MainSvr, Cfg[i].Fld[FEP_SERVER]);

			/* Main Port명을 얻음 */
			lpFepCfg->MainPort = atoi (Cfg[i].Fld[FEP_PORT]);

			/* Backup 서버명을 얻음 */
			strcpy (lpFepCfg->BackSvr, Cfg[i].Fld[FEP_SERVER2]);

			/* Backup Port명을 얻음 */
			lpFepCfg->BackPort = atoi (Cfg[i].Fld[FEP_PORT2]);

			/* 큐ID를 얻음 */
			qid = atoi (Cfg[i].Fld[FEP_RQ]);
			if (qid > 0)
			{
				if ((lpFepCfg->Rqid = msgget (qid, PERM)) == EOF)
				{
        			PutFmtLog (LogFD, (char*)"ReadCfg() msgget Err[%d]\n", errno);
					return -1;
				}
			}
			qid = atoi (Cfg[i].Fld[FEP_SQ]);
			if (qid > 0)
			{
				if ((lpFepCfg->Sqid = msgget (qid, PERM)) == EOF)
				{
        			PutFmtLog (LogFD, (char*)"ReadCfg() msgget Err[%d]\n", errno);
					return -1;
				}
			}

			/* FEP업무구분자 */
			strcpy (lpFepCfg->Job, Cfg[i].Fld[FEP_JOB]);

			/* 받는큐에서의 알람 */
			lpFepCfg->AlarmTime = atol(Cfg[i].Fld[FEP_ALARM]);

			sw = 1;
			break;
		}
	}

	if (sw < 1)	return -1;

	return 0;
}
//#define	FEP_CFG
//#endif

