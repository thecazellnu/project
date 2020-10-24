#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "socklib.h"
#include "fepst.h"
#include "log.h"

#define TIMEOUT 15

extern int g_Pid;
extern CLog g_Log;

int SetBaseHeader(lpBASE_HEADER lpBase, char *brchno, char trdiv, char *trcd,
	char *uid, char reptdiv, char *reptkey, int len, int *slen)
{
    char    tmp     [32];
    char    tmp1    [32];

	*slen = len + SZ_BASE_HEADER + SZ_BASE_USER_HEADER;
	Int2Str(*slen - sizeof(lpBase->DataLen), lpBase->DataLen, 
		sizeof(lpBase->DataLen));
    lpBase->TrGubun[0] = trdiv;
    lpBase->ComGubun[0] = '0';
    lpBase->SecGubun[0] = '0';

	Int2Str(SZ_BASE_HEADER + SZ_BASE_USER_HEADER, lpBase->DataSeek, 
		sizeof (lpBase->DataSeek));
    memcpy(lpBase->ServCode, trcd, sizeof (lpBase->ServCode));
    memcpy(lpBase->CompanyNo, COMPANY_NO, sizeof (lpBase->CompanyNo));

    memcpy(lpBase->UserId, uid, strlen(uid));
    memcpy(lpBase->ConnectCode, "HT", sizeof (lpBase->ConnectCode));
    memcpy(lpBase->ConnectCh, "000", sizeof (lpBase->ConnectCh));
    memcpy(lpBase->TrSeq, "000000000", sizeof (lpBase->TrSeq));
    lpBase->TrChId[0] = '@';
    memcpy(lpBase->TrChId + 1, trcd, strlen (trcd));
	GetIpAddr(tmp);
	IpConv(tmp, tmp1);
    memcpy (lpBase->PuIP, tmp1, sizeof (lpBase->PuIP));
    memcpy (lpBase->PvIP, tmp1, sizeof (lpBase->PvIP));
    memcpy (lpBase->ProBrNo, brchno, sizeof (lpBase->ProBrNo));
    memcpy (lpBase->BrNo, brchno, sizeof (lpBase->BrNo));
    memcpy (lpBase->TermNo, "GS0  000", sizeof (lpBase->TermNo));
    memcpy (lpBase->LanCode, "K", sizeof (lpBase->LanCode));
    GetDateTimeSec(tmp);
    memcpy (lpBase->APProTime, tmp + 8, sizeof (lpBase->APProTime));
    memcpy (lpBase->ComRequest, "0", sizeof (lpBase->ComRequest));
    memcpy (lpBase->RequestRecord, "0000", sizeof (lpBase->RequestRecord));

    if (reptdiv == 'Y') 
    {
        lpBase->FunKey[0] = '7';
        lpBase->ContinueYn[0] = reptdiv;
        memcpy(lpBase->ContinueKey, reptkey, sizeof (lpBase->ContinueKey));
    }
    else
    {
        lpBase->FunKey[0] = 'C';
    }
	Int2Str(SZ_BASE_USER_HEADER, lpBase->VariLen, sizeof (lpBase->VariLen));
	Int2Str(0, lpBase->VariHead, sizeof (lpBase->VariHead));
	Int2Str(0, lpBase->VariMes, sizeof (lpBase->VariMes));

	return 1;
}

SockLib *CreateTcpCli(char *ip, int port)
{
	SockLib *ConCliSock = new SockLib();
	if((port < 0) || (ip == NULL)) return NULL;
	ConCliSock->SetBlockSocket(0);
	ConCliSock->SetPacketLength(6);
	if(ConCliSock->Create(port, ip, SOCK_STREAM, -1) < 0) return NULL;
	if(ConCliSock->Connect() != TRUE) 
	{
		ConCliSock->Close();
		delete ConCliSock;
		return NULL;
	}
	return ConCliSock;
}

int SendRecv(char *ip, int port, char *data, int len, 
	char *outdata, int *outlen)
{
    int n;
    int split = 0;
    int rc = -1;
	int running = 1;

    SockLib *FepSR = CreateTcpCli(ip, port);
    if(FepSR == NULL)
    {   
        g_Log.Write("[%d:%s] Client Connection Error [%s][%d]",
            g_Pid, __FILE__, ip, port);
        return -1;
    }
    g_Log.Write("[%d:%s] Client Connection Success [%s][%d]",
		g_Pid, __FILE__, ip, port);

    if(FepSR->Write(data, len) != len)
    {   
        g_Log.Write("[%d:%s] Send Data Error [%d]", g_Pid, __FILE__, errno);
        FepSR->Close();
        delete FepSR;
        return -1;
    }
    g_Log.Write("[%d:%s] Client Write Success [%s][%d]fd[%d]len[%d]",
		g_Pid, __FILE__, ip, port, FepSR->m_wfd, len);

    while(running)
    {   
        n = FepSR->Select(TIMEOUT, 0);
        if(n > 0)
        {   
            if(FepSR->CheckFd() <= 0) break; 
            else while(FepSR->CheckFd() > 0) split++;
            while(1)
            {   
                rc = FepSR->RecvPacket(outdata);
                if(rc == 0)
                {
                    usleep(10000);
                    continue;
                }
                else
                {
                    *outlen = rc;
                    g_Log.Write("[%d:%s] FepSR rc[%d]len[%d]n[%d]fd[%d]",
                        g_Pid, __FILE__, rc, *outlen, n, FepSR->m_rfd);
					running = 0;
                    break;
                }
            }
        }
        else if(n == 0)
            g_Log.Write("[%d:%s] FepSendRecv TimeOut[%d]", g_Pid, __FILE__, n);
        else
            g_Log.Write("[%d:%s] FepSendRecv Socket Error[%d]",
                g_Pid, __FILE__, n);
        break;
    }
    FepSR->Close();
    delete FepSR;

    return rc;
}

int FepSndRcv(char *data, int len, char *outdata, int *outlen,
    char *brchno, char trdiv, char *trcd, char *uid,
    char reptdiv, char *reptkey, char *outreptdiv, char *outreptkey,
    char *msgcd, char*msg)
{
    int slen;
    int port;
    int rcvlen;
    int dataoffset;
    char ip[32];
    char buff[256];
    char rcvdata[65536];
    char EnvPath[256];
    char sbuff[65536];
    char *temp = NULL;
    BASE_HEADER			bhead;
    BASE_USER_HEADER	buhead;

	lpBASE_HEADER rhead;
	
    memset(&bhead,  0x20, SZ_BASE_HEADER);
    memset(&buhead, 0x20, SZ_BASE_USER_HEADER);

    temp = getenv("ITMS_CFG");
    if(temp == NULL) strcpy(EnvPath, "/itms/cfg");
    strcpy(EnvPath, temp);

    GetCfg(EnvPath, (char *)"fep.cfg", (char *)"REQ_FEP",
        (char *)"HOST", (char *)"", ip);
    GetCfg(EnvPath, (char *)"fep.cfg", (char *)"REQ_FEP",
        (char *)"PORT", (char *)"", buff);
    port = atoi(buff);

    g_Log.Write("[%d:%s] FEP Send IP[%s]Port[%d]", g_Pid, __FILE__, ip, port);

    if(SetBaseHeader(&bhead, brchno, trdiv, trcd, uid, reptdiv,
        reptkey, len, &slen) < 0) return -1;

	/* SetBaseUserHead */
	memcpy(buhead.MarketType, "12", sizeof (buhead.MarketType));
	memcpy(buhead.BaseBpNo,   "00", sizeof (buhead.BaseBpNo));
    GetCfg(EnvPath, (char *)"fep.cfg", (char *)"COMMON",
        (char *)"FEP_QKEY", (char *)"", buff);
	Int2Str(atoi(buff), buhead.Qkey, sizeof(buhead.Qkey));

    memset(sbuff, 0x00, sizeof(sbuff));
    memcpy(sbuff, &bhead, SZ_BASE_HEADER);
    memcpy(sbuff + SZ_BASE_HEADER, &buhead, SZ_BASE_USER_HEADER);
    memcpy(sbuff + SZ_BASE_HEADER + SZ_BASE_USER_HEADER, data, len);

    if(SendRecv(ip, port, sbuff, slen, rcvdata, &rcvlen) > 0)
    {
		rhead = (lpBASE_HEADER)(rcvdata);

        dataoffset = Str2Int(rhead->VariMes, sizeof(rhead->VariMes));
        *outlen  = rcvlen - (SZ_BASE_HEADER + SZ_BASE_USER_HEADER + dataoffset);
        memcpy(outdata, 
			rcvdata + SZ_BASE_HEADER + SZ_BASE_USER_HEADER + dataoffset, 
			*outlen);

        memcpy(msgcd, rhead->MessageCode, sizeof(rhead->MessageCode));
        memcpy(msg,   rcvdata + SZ_TOT_HEADER, dataoffset);

        if(rhead->MessageCode[0] == '0')
        {
            memcpy(outreptdiv, rhead->ContinueYn, sizeof(rhead->ContinueYn));
            memcpy(outreptkey, rhead->ContinueKey, sizeof(rhead->ContinueKey));
            return 1;
        }
        else
        {
            g_Log.Write("[%d:%s] [%.*s]",
                g_Pid, __FILE__, dataoffset, 
				rcvdata + SZ_BASE_HEADER + SZ_BASE_USER_HEADER);
            return -2;
        }
    }
    strcpy(msgcd, "8001");
    return -1;
}

