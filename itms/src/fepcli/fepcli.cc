#include "fepcli.h"

void sig_term(int signum)
{
    g_Log.Write("[%d:%s] SIGTERM Message Receive", g_Pid, __FILE__);
    printf("[%d:%s] SIGTERM Message Receive\n", g_Pid, __FILE__);
    g_Running = 0;
}

void sig_int(int signum)
{
    g_Log.Write("[%d:%s] SIGINT Message Receive", g_Pid, __FILE__);
    printf("[%d:%s] SIGINT Message Receive\n", g_Pid, __FILE__);
    g_Running = 0;
}

void sig_pipe(int signum)
{
    g_Log.Write("[%d:%s] SIGPIPE Message Receive", g_Pid, __FILE__);
    printf("[%d:%s] SIGPIPE Message Receive\n", g_Pid, __FILE__);
    g_Running = 0;
}

void sig_segv(int signum)
{
    g_Log.Write("[%d:%s] SIGSEGV Message Receive", g_Pid, __FILE__);
    printf("[%d:%s] SIGSEGV Message Receive\n", g_Pid, __FILE__);
    g_Running = 0;
}

void SignalSet()
{
    signal(SIGINT, sig_int);
    signal(SIGTERM, sig_term);
    signal(SIGPIPE, sig_pipe);
    signal(SIGSEGV, sig_segv);
}

int LogList();

int GetOption(int argc, char **argv)
{
	int i;
	char buff[256];

	getcwd(g_HomePath, sizeof(g_HomePath));

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"commom.cfg", (char *)"COMMON", 
		(char *)"LOG_PATH", (char *)"/itms/log", buff);
	sprintf(buff, "%s/%s", buff, g_PgmName);
	g_Log.Open(buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"seq.cfg", (char *)"COMMON", 
		(char *)"SEQ_PATH", NULL, buff);
	strcat(g_toSeqPath, buff);
	strcat(g_frSeqPath, buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"seq.cfg", (char *)"TO_FEP", 
		(char *)"NAME", NULL, buff);
	strcat(g_toSeqPath, "/");
	strcat(g_toSeqPath, buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"seq.cfg", (char *)"TO_FEP", 
		(char *)"LEN", NULL, buff);
	g_toSeqLen = atoi(buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"seq.cfg", (char *)"FROM_FEP", 
		(char *)"NAME", NULL, buff);
	strcat(g_frSeqPath, "/");
	strcat(g_frSeqPath, buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"seq.cfg", (char *)"FROM_FEP", 
		(char *)"LEN", NULL, buff);
	g_frSeqLen = atoi(buff);

	return 1;
}

SockLib *CreateTcpCli(char *ip, int port)
{
	SockLib *ConCliSock = new SockLib();
	if((port < 0) || (ip == NULL)) return NULL;
	ConCliSock->SetBlockSocket(1);
	if(ConCliSock->Create(port, ip, SOCK_STREAM, -1) < 0) return NULL;
	if(ConCliSock->Connect() != TRUE) 
	{
		ConCliSock->Close();
		delete ConCliSock;
		return NULL;
	}
	return ConCliSock;
}

int SetFepHead(lpFEP_HEADER head, int len, char *trdiv, long seq, char *cfg)
{
	char tmp[128];

	head->Stx[0] = STX;
	Int2Str(len, head->Length, sizeof(head->Length));

	memset(tmp, 0x00, sizeof(tmp));
	GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", cfg,
		(char *)"FEP_PS", NULL, tmp);
	memcpy(head->ApType, tmp, sizeof(head->ApType));

	memset(tmp, 0x00, sizeof(tmp));
	GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", cfg,
		(char *)"FEP_SYS_TYPE", NULL, tmp);
	memcpy(head->SysType, tmp, sizeof(head->SysType));

	memcpy(head->MsgType, trdiv, sizeof(head->MsgType));
	if(!memcmp(trdiv + 2,  "OK", 2)) memcpy(head->ResponseCode, "00", 2);

	GetDateTimeSec(tmp);
	memcpy(head->Date, tmp, sizeof(head->Date));
	memcpy(head->Time, tmp + sizeof(head->Date), sizeof(head->Time));

	Long2Str(seq, head->SeqNo, sizeof(head->SeqNo));

	return 1;
}

int ErrRtn(SockLib *Class, char *data, int len)
{
	lpBASE_HEADER PbHead = (lpBASE_HEADER)(data);
    memcpy(PbHead->MessageCode, (char *)"9501", 4);
    Class->Write(data, len);
    g_Log.Write("[%d:%s] ErrRtn Cannot Send", g_Pid, __FILE__);
    return 1;
}

int SendFep(SockLib *Class, char *trdiv, char *data, int len, char *fep, 
	SockLib* CliClass)
{
	int  slen;
	int  seqlen;
	long seqno = 0;
	char seqpath[128];
	char sbuff[65536];
	lpGTS_HEADER head = (lpGTS_HEADER)(sbuff);	

	memset(sbuff, 0x20, sizeof(sbuff));

	if(!memcmp(fep, "TO_FEP", 6))
	{
		strcpy(seqpath, g_toSeqPath);
		seqlen = g_toSeqLen;
	}
	else if(!memcmp(fep, "FROM_FEP", 8))
	{
		strcpy(seqpath, g_frSeqPath);
		seqlen = g_frSeqLen;
	}
	else 
	{
		g_Log.Write("[%d:%s] Illegal FEP", g_Pid, __FILE__);
		return -1;
	}

	Class->Lock();
	if(!memcmp(trdiv, "DATA", 4))
	{
		seqno = GetNextSeq(seqpath, seqlen);
		DataBlock *data = new DataBlock;
		data->Class = CliClass;
		data->seqno = (long)seqno;
		g_trList.Add(data);
		g_Log.Write("[%d:%s] Add TR[%ld]", g_Pid, __FILE__, seqno);
	}
	else seqno = GetCurSeq(seqpath, seqlen);
	Class->UnLock();

	slen = len + SZ_FEP_HEADER;

	SetFepHead(&head->Fep, slen, trdiv, seqno, fep);

	if(!memcmp(trdiv, "DATA", 4))
	{
		memcpy(sbuff + SZ_FEP_HEADER, data, len);
		Long2Str(seqno, head->UserHead.Qkey, 
			sizeof(head->UserHead.Qkey));
	}

	Class->Write(sbuff, slen);

    g_Log.Write("[%d:%s] [%s] SND[%.4s] Len[%d] seq[%ld]",
        g_Pid, __FILE__, fep, trdiv, slen, seqno);
/*
    g_Log.Write("[%d:%s] [%s] SND [%.*s]", 
        g_Pid, __FILE__, fep, slen, sbuff);
*/

	return 1;
}

int FepRcvProc(SockLib *Class, char *data, int len)
{
	char fep[32];
	char seqpath[64];
	long seqno;
	long userSeq;
	lpGTS_HEADER head = (lpGTS_HEADER)(data);	

	if(head->Fep.ApType[3] == 'R')
	{
		strcpy(fep, "TO_FEP");
	}
	else if(head->Fep.ApType[3] == 'S')
	{
		strcpy(fep, "FROM_FEP");
	}

    g_Log.Write("[%d:%s] [%s] RCV[%.6s]CD[%.2s][%.4s]SEQ[%.8s]",
        g_Pid, __FILE__, fep, head->Fep.ApType, head->Fep.ResponseCode, 
		head->Fep.MsgType, head->Fep.SeqNo);
g_Log.Write("[%d:%s] [%s] RCV[%d][%.*s]",
	g_Pid, __FILE__, fep, len, len, data);

	seqno = Str2Long(head->Fep.SeqNo, sizeof(head->Fep.SeqNo));
	//LINK RE CONNECT
	if(!memcmp(head->Fep.MsgType, "LIOK", sizeof(head->Fep.MsgType)))
	{
		if(!memcmp(fep, "TO", 2))
		{
			if(g_toFepCli == NULL) 
			{
				Class->Close();
				FepCli(fep, (int)seqno);
			}
		}
		else if(!memcmp(fep, "FR", 2))
		{
			if(g_frFepCli == NULL) 
			{
				Class->Close();
				FepCli(fep, (int)seqno);
			}
		}
	}
	else if(!memcmp(head->Fep.MsgType, "STOK", sizeof(head->Fep.MsgType)))
	{
		if(!memcmp(fep, "FROM_FEP", 8))
			SendFep(Class, (char *)"RESE",  NULL, 0, fep, NULL);

		Class->Lock();
		if(!memcmp(fep, "FROM_FEP", 8))
			WriteSeqno(g_frSeqPath, g_frSeqLen, seqno);
		else if(!memcmp(fep, "TO_FEP", 6))
			WriteSeqno(g_toSeqPath, g_toSeqLen, seqno);
		Class->UnLock();
	
	}
	else if(!memcmp(head->Fep.MsgType, "DATA", sizeof(head->Fep.MsgType)))
	{

		if(!memcmp(fep, "TO", 2))
		{
			if( memcmp(head->Fep.ResponseCode, "00", 
				sizeof(head->Fep.ResponseCode)) &&
				memcmp(head->Fep.ResponseCode, "  ", 
				sizeof(head->Fep.ResponseCode)))
			{
				g_Log.Write("[%d:%s]TO_FEPSend Error USEQ[%ld]", 
					g_Pid, __FILE__, userSeq);

				Class->Lock();
				DataBlock *dBlock = g_trList.Find((long)userSeq);
				Class->UnLock();

				ErrRtn(dBlock->Class, data, len);

				Class->Lock();
				g_trList.Del(dBlock);
				Class->UnLock();
			}
		}
		else if(!memcmp(fep, "FR", 2))
		{
			userSeq = 
				Str2Long(head->UserHead.Qkey, sizeof(head->UserHead.Qkey));
			g_Log.Write("[%d:%s] [%s] RCV SEQ[%.8s]USEQ[%.11s][%ld:%ld]",
				g_Pid, __FILE__, fep, head->Fep.SeqNo, 
				head->UserHead.Qkey, seqno, userSeq);

			Class->Lock();
			DataBlock *dBlock = g_trList.Find((long)userSeq);
			Class->UnLock();
			if(dBlock)
			{
				dBlock->Class->Write(data + SZ_FEP_HEADER, len - SZ_FEP_HEADER);
				g_Log.Write("[%d:%s] [%s] Send2Cli len[%d] fd[%d]",
					g_Pid, __FILE__, fep, len - SZ_FEP_HEADER, 
					dBlock->Class->m_wfd);
				dBlock->Class->Close();
			}
			else
			{
				g_Log.Write("[%d:%s] DataList Not Found userSeq[%ld]",
					g_Pid, __FILE__, userSeq);
//				return -1;
			}
			Class->Lock();
			if(dBlock) g_trList.Del(dBlock);
			WriteSeqno(g_frSeqPath, g_frSeqLen, seqno);
			Class->UnLock();

			SendFep(Class, (char *)"DAOK",  NULL, 0, fep, NULL);
		}
	}
	else if(!memcmp(head->Fep.MsgType, "LIVE", sizeof(head->Fep.MsgType)))
	{
		SendFep(Class, (char *)"LIOK",  NULL, 0, fep, NULL);
	}
	return 1;
}

int FepHandler(SockLib *Class, int cmd, int len, char *data, void *tmp)
{
	switch(cmd)
	{
		case TS_START:
			g_Log.Write("[%d:%s] Connect From[%s][%d] T[%d]",
				g_Pid, __FILE__, Class->m_Name, Class->m_Port, Class->m_tid);
			printf("[%d:%s] Connect From[%s][%d] T[%d]\n",
				g_Pid, __FILE__, Class->m_Name, Class->m_Port, Class->m_tid);
			break;
		case TS_DATA:
			FepRcvProc(Class, data, len);
			break;
		case TS_TIMEOUT:
			if(Class == g_toFepCli)
				SendFep(Class, (char *)"LIVE",  NULL, 0, 
					(char *)"TO_FEP", NULL);
			break;
		case TS_CLOSE:
			g_Log.Write("[%d:%s] DisConnect [%s][%d]",
				g_Pid, __FILE__, Class->m_Name, Class->m_Port);
			printf("[%d:%s] DisConnect [%s][%d]\n",
				g_Pid, __FILE__, Class->m_Name, Class->m_Port);

			if(Class == g_toFepCli)
				g_toFepCli = NULL;
			else if(Class == g_frFepCli)
				g_frFepCli = NULL;

			delete Class;

			break;
	}
	return 1;
}

int FepCli(char *fep, int port)
{
	char buff[256];
	char sHost[128];
	int  iPort;
	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", fep,
		(char *)"MAIN_HOST", NULL, buff);
	strcpy(sHost, buff);

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", fep,
		(char *)"MAIN_PORT", NULL, buff);
	iPort = atoi(buff);	
	if(port) iPort = port;

	SockLib *Cli = CreateTcpCli(sHost, iPort);
	if(Cli == NULL)
	{
		g_Log.Write("[%d:%s] [%s]Main Connection Error", 
			g_Pid, __FILE__, fep);

		memset(buff, 0x00, sizeof(buff));
		GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", fep,
			(char *)"DR_HOST", NULL, buff);
		strcpy(sHost, buff);

		memset(buff, 0x00, sizeof(buff));
		GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", fep,
			(char *)"DR_PORT", NULL, buff);
		iPort = atoi(buff);	
		if(port) iPort = port;

		SockLib *Cli = CreateTcpCli(sHost, iPort);
		if(Cli == NULL)
		{
			g_Log.Write("[%d:%s] [%s]DR Connection Error", 
				g_Pid, __FILE__, fep);

			if(!memcmp(fep, "TO_FEP", strlen(fep))) g_toFailed++;
			else if(!memcmp(fep, "FROM_FEP", strlen(fep))) g_frFailed++;

			return -1;
		}
	}

	g_Log.Write("[%d:%s] [%s]Client Connection IP[%s]PORT[%d]", 
		g_Pid, __FILE__, fep, sHost, iPort);

	if(!memcmp(fep, "TO_FEP", strlen(fep)))
	{
		g_toFailed = 0;
		if(port) g_toFepCli = Cli;
	}
	else if(!memcmp(fep, "FROM_FEP", strlen(fep)))
	{
		g_frFailed = 0;
		if(port) g_frFepCli = Cli;
	}

	Cli->SetHandler(FepHandler);	
	//Head LEN = PACKET LEN + LEN(5) + STX(1) --> TOTAL LENGTH : SetLENAdd(1)
	Cli->SetLENAdd(1);
	Cli->SetTimeOut(10);
	Cli->SetPacketLength(5);
	Cli->SetSTX(1);
	Cli->Start();

	if(!port) SendFep(Cli, (char *)"LINK",  NULL, 0, fep, NULL);
	else      SendFep(Cli, (char *)"STRT",  NULL, 0, fep, NULL);
	return 1;
}

int RQHandler(SockLib *Class, int cmd, int len, char *data, void *tmp)
{
    int rc;
    switch(cmd)
    {
        case TS_START:
            g_Log.Write("[%d:%s] RQHandler Connect From[%s][%d] T[%d]",
                g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
            break;
        case TS_DATA:
            g_Log.Write("[%d:%s] RQHandler Data Recv From[%s][%d] L[%d]",
                g_Pid, __FILE__, Class->m_Name, Class->m_rfd, len);
            if(SendFep(g_toFepCli, (char *)"DATA", data, len, 
				(char *)"TO_FEP", Class) < 0)
            {
                ErrRtn(Class, data, len);
                return 0;
            }
            break;
        case TS_TIMEOUT:
            break;
        case TS_CLOSE:
            g_Log.Write("[%d:%s] RQHandler DisConnect FD[%d] T[%d]",
                g_Pid, __FILE__, Class->m_rfd, Class->m_tid);
            delete Class;
            break;
    }   
    return 1;
} 

int DmHandler(SockLib *Class, int cmd, int len, char *data, void *tmp)
{
    switch(cmd)
    {
        case TS_START:
            g_Log.Write("[%d:%s] DmHandler Listen From[%s][%d] T[%d]",
                g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
            break;
        case TS_DATA:
            g_Log.Write("[%d:%s] Accept Fd[%d]", g_Pid, __FILE__, len);
            {
                SockLib *ConClass = new SockLib;
                if(ConClass->Create(0, NULL, SOCK_STREAM, len) != ERROR)
                {
                    ConClass->SetHandler(RQHandler);
					ConClass->SetPacketLength(6);
                    ConClass->Start();
                }
                else return -1;
            }
            break;
        case TS_TIMEOUT:
            break;
        case TS_CLOSE:
            g_Log.Write("[%d:%s] DmHandler Destroy FD[%d] T[%d]",
                g_Pid, __FILE__, Class->m_rfd, Class->m_tid);
            delete Class;
            g_rqFepSvr = NULL;
            break;
    }
    return 1;
}

SockLib *CreateTcpSvr(int port)
{
    SockLib *ConSvrSocket = new SockLib();
    if(port < 0) return NULL;
    if(ConSvrSocket->Create(port) < 0) return NULL;
    if(ConSvrSocket->Bind() < 0)
    {
        ConSvrSocket->Close();
        delete ConSvrSocket;
        return NULL;
    }
    ConSvrSocket->Listen();
    return ConSvrSocket;
}

int FepConDm()
{
	int		port;
	char	buff[64];
	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"fep.cfg", (char *)"REQ_FEP", 
		(char *)"PORT", NULL, buff);
	port = atoi(buff);

    SockLib *FepConDm = CreateTcpSvr(port);
    if(FepConDm == NULL)
    {
        g_Log.Write("[%d:%s] Create TcpSvr Error", g_Pid, __FILE__);
        return -1;
    }
    else
    {
        FepConDm->SetHandler(DmHandler);
        FepConDm->StartDm();
        g_rqFepSvr = FepConDm;
        g_Log.Write("[%d:%s] FepConDm Listen Port[%d]",
            g_Pid, __FILE__, port);
    }
    return 1;
}

int Terminate()
{
/*
	if(g_toFepCli) delete g_toFepCli;
	if(g_frFepCli) delete g_frFepCli;
	if(g_rqFepSvr) delete g_rqFepSvr;
*/
	//delete &g_Log;
	return 1;
}

int InitSession()
{
	if(FepCli((char *)"TO_FEP", 0) < 0) return -1;
	if(FepCli((char *)"FROM_FEP", 0) < 0) return -1;
	if(FepConDm() < 0) return -1;

	while(!g_toFepCli || !g_frFepCli)
	{
		sleep(1);
	}
	return 1;
}

int LogList()
{
    CNode     *pNode;
    DataBlock *pinfo;
    int       listcnt = 0;
    g_Log.Write("[%d:%s] ======= DATA LIST ========", g_Pid, __FILE__);
    for (pNode = g_trList.GetFirst();
                pNode != NULL; pNode = g_trList.GetNext(pNode))
    {
        if(pNode->m_pData == NULL) continue;
        pinfo = (DataBlock *)pNode->m_pData;

        g_Log.Write("[%d:%s] [%d] trseqno[%ld]",
            g_Pid, __FILE__, listcnt, pinfo->seqno);
        listcnt++;
     }
    g_Log.Write("[%d:%s] ==========================", g_Pid, __FILE__);
    return 1;
}

int MainLoop()
{
	char tmp[64];
	char Date[8];
	int ListLog = 0;

	InitialSeqFile(g_toSeqPath, g_toSeqLen);
	InitialSeqFile(g_frSeqPath, g_frSeqLen);

	if(InitSession() < 0) return -1;

	GetDateTimeSec(tmp);
	memcpy(Date, tmp, 8);

	while(g_Running)
	{
		GetDateTimeSec(tmp);
		if(memcmp(Date, tmp, 8))
		{
			if(memcmp(tmp + 8, "0300", 4) > 0)
			{
				memcpy(Date, tmp, 8);
				g_Log.Write("[%d:%s] Day Changed[%s]", g_Pid, __FILE__, Date);
				InitialSeqFile(g_toSeqPath, g_toSeqLen);
				InitialSeqFile(g_frSeqPath, g_frSeqLen);
			}	
		}

		if(g_toFepCli == NULL)  
		{
			if(g_toFailed < 3) 
				FepCli((char *)"TO_FEP", 0);
			else if(!(ListLog % 500)) 
				FepCli((char *)"TO_FEP", 0);
		}

		if(g_frFepCli == NULL)
		{  
			if(g_frFailed < 3) 
				FepCli((char *)"FROM_FEP", 0);
			else if(!(ListLog % 500)) 
				FepCli((char *)"FROM_FEP", 0);
		}

		if(g_rqFepSvr == NULL)  FepConDm();

		if(!(ListLog++ % 1000)) LogList();
		usleep(1000000);
	}
    return TRUE;
}

int main(int argc, char **argv)
{
	Daemon(getenv("ITMS_BIN"), 1);
	g_Pid = getpid();
	strcpy(g_PgmName, "fepcli");

	if(GetOption(argc, argv) < 0)
	{
		printf("Option Errort\n");
		return -1;
	}

	g_Log.Write("[%d:%s] FEP Client Process Start====================", 
		g_Pid, __FILE__);

	chdir(g_HomePath);
	SignalSet();

	MainLoop();

	g_Log.Write("[%d:%s] FEP Client Process End ====================", 
		g_Pid, __FILE__);
	Terminate();

	return 1;
}
