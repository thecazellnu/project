#include "i1001.h"

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

int GetOption(int argc, char **argv)
{
	int i;
	char buff[256];

    if(argc < 4)
    {
        printf ("Usage: %s fundcd brchno userid\n", g_PgmName);
        printf (" (ex) %s 99991921001 891 LD20041 \n", g_PgmName);
        exit (-1);
    }

	getcwd(g_HomePath, sizeof(g_HomePath));

	memset(buff, 0x00, sizeof(buff));
	GetCfg(getenv("ITMS_CFG"), (char *)"commom.cfg", (char *)"COMMON", 
		(char *)"LOG_PATH", (char *)"/itms/log", buff);
	sprintf(buff, "%s/%s", buff, g_PgmName);
	g_Log.Open(buff);

	strcpy(g_fundcd, argv[1]);
	strcpy(g_brchno, argv[2]);
	strcpy(g_userid, argv[3]);

	return 1;
}

int MainProc()
{
	int first = 0;
	char query[8092];

    SSESQ119_IN  in;
    lpSSESQ119_OUT outp;
    lpSSESQ119_OUT_OCCR1 outsubp;

	// Input setting
	memset((char *)&in, 0x30, SZ_SSESQ119_IN);
    memcpy(in.In,      "00001"     , sizeof(in.In));
    memset(in.FundOpAcntNo, 0x20, sizeof(in.FundOpAcntNo));
    memcpy(in.FundOpAcntNo, g_fundcd, 11);
    memcpy(in.EvalErnrat, "+0000.000000", 12);
    in.SrtVal          [0] = '+';
    in.OpLmtAmt        [0] = '+';
    in.BfDtBnsPnlamt   [0] = '+';
    in.BfDtEvalPnlAmt  [0] = '+';
    in.PrdayCmpMktAmt  [0] = '+';
    in.HldQty          [0] = '+';
    in.DtBnsplAmt      [0] = '+';
    in.MthBnsplAmt     [0] = '+';
    in.BnsplAmt        [0] = '+';
    in.HldAmt          [0] = '+';
    in.EvalAmt         [0] = '+';
    in.EvalPnlAmt      [0] = '+';
    in.EvalErnrat      [0] = '+';
    in.BuyLmtAmt       [0] = '+';
    in.PnlSumAmt       [0] = '+';

	int		i;
	int		outlen;
	int		datacnt;
	char	outdata[65536];
	char	tmp1[32];
	char	tmp2[32];
	char	msgcd[16];
	char	respmsg[256];
	char	reptdiv;
	char	reptkey[32];

	g_Log.Write("[%d:%s] Input[%d][%.*s]", 
		g_Pid, __FILE__, SZ_SSESQ119_IN, SZ_SSESQ119_IN,(char *)&in);

	reptdiv = 'N';
	memset(reptkey, 0x20, sizeof(reptkey));

	first = 1;
	while(1)
	{
		if(FepSndRcv((char *)&in, SZ_SSESQ119_IN, outdata, &outlen, g_brchno,  
			(char)'B', (char *)"SSESQ119", g_userid, reptdiv, reptkey,
			tmp1, tmp2, msgcd, respmsg) < 0)
		{
			g_Log.Write("[%d:%s] FepSndRcv Error[%s][%s]", 
				g_Pid, __FILE__, msgcd, respmsg);
			return -1;
		}
		else 
		{
			g_Log.Write("[%d:%s] tmp1[%s] tmp2[%s]",
					g_Pid, __FILE__, tmp1, tmp2);
			g_Log.Write("[%d:%s] FepSndRcv OK[%d][%s]", 
					g_Pid, __FILE__, outlen, outdata);

			outp    = (lpSSESQ119_OUT)(outdata + SZ_SSESQ119_IN);
			datacnt = Str2Int(outp->BalPnlSt, sizeof(outp->BalPnlSt));
			outsubp = (lpSSESQ119_OUT_OCCR1)
				(outdata + SZ_SSESQ119_IN + SZ_SSESQ119_OUT);

			g_Log.Write("[%d:%s] DataCnt[%d]", g_Pid, __FILE__, datacnt);
		}

		if(first)
		{
			sprintf(query,	" DELETE                     \n"
							" FROM		ITMS0110         \n"
							" WHERE		1=1              \n"
							" AND		DATE = CURDATE() \n"
							" AND		FUND_CD = '%s'   \n"
					, g_fundcd);
			if(MDBQuery(query) < 0)
			{
				g_Log.Write("[%d:%s] DELETE ITMS0110 Error", g_Pid, __FILE__);
				return -1;
			}
			else g_Log.Write("[%d:%s] DELETE ITMS0110", g_Pid, __FILE__);

			sprintf(query,	" DELETE                     \n"
							" FROM		ITMS0120         \n"
							" WHERE		1=1              \n"
							" AND		DATE = CURDATE() \n"
							" AND		FUND_CD = '%s'   \n"
					, g_fundcd);
			if(MDBQuery(query) < 0)
			{
				g_Log.Write("[%d:%s] DELETE ITMS0120 Error", g_Pid, __FILE__);
				return -1;
			}
			else g_Log.Write("[%d:%s] DELETE ITMS0120", g_Pid, __FILE__);
g_Log.Write("[%d:%s]펀드명          [%.40s]", g_Pid, __FILE__, outp->FundNm        );
g_Log.Write("[%d:%s]운용한도금액    [%.16s]", g_Pid, __FILE__, outp->OpLmtAmt      );
g_Log.Write("[%d:%s]전일매매손익금액[%.16s]", g_Pid, __FILE__, outp->BfDtBnsPnlamt );
g_Log.Write("[%d:%s]전일평가손익금액[%.16s]", g_Pid, __FILE__, outp->BfDtEvalPnlAmt);
g_Log.Write("[%d:%s]전일대비        [%.16s]", g_Pid, __FILE__, outp->PrdayCmpMktAmt);
g_Log.Write("[%d:%s]보유수량        [%.16s]", g_Pid, __FILE__, outp->HldQty        );
g_Log.Write("[%d:%s]일매매손익금액  [%.17s]", g_Pid, __FILE__, outp->DtBnsplAmt    );
g_Log.Write("[%d:%s]월매매손익금액  [%.17s]", g_Pid, __FILE__, outp->MthBnsplAmt   );
g_Log.Write("[%d:%s]매매손익금액    [%.16s]", g_Pid, __FILE__, outp->BnsplAmt      );
g_Log.Write("[%d:%s]보유금액        [%.16s]", g_Pid, __FILE__, outp->HldAmt        );
g_Log.Write("[%d:%s]평가금액        [%.16s]", g_Pid, __FILE__, outp->EvalAmt       );
g_Log.Write("[%d:%s]평가손익금액    [%.16s]", g_Pid, __FILE__, outp->EvalPnlAmt    );
g_Log.Write("[%d:%s]평가수익률      [%.12s]", g_Pid, __FILE__, outp->EvalErnrat    );
g_Log.Write("[%d:%s]매수한도금액    [%.16s]", g_Pid, __FILE__, outp->BuyLmtAmt     );
g_Log.Write("[%d:%s]손익합계금액    [%.16s]", g_Pid, __FILE__, outp->PnlSumAmt     );
g_Log.Write("[%d:%s]잔고수          [%.5s] ", g_Pid, __FILE__, outp->BalPnlSt      );

			sprintf(query,
				"  INSERT INTO ITMS0110                          \n"
				"  VALUES                                        \n"
				"  (                                             \n"
				"  NULL ,                                        \n"
				"  CURDATE(),                                    \n"
				"  '%s', trim('%.*s'), %f, %f, %f, %f, %f, %f, %f, \n"
				"  %f, %f, %f, %f, %f, %f, %f, %f, sysdate()     \n"
				"  )                                             \n"
				,
				g_fundcd,
				sizeof(outp->FundNm), outp->FundNm,
				Str2Dbl(outp->OpLmtAmt      , sizeof(outp->OpLmtAmt      )),
				Str2Dbl(outp->BfDtBnsPnlamt , sizeof(outp->BfDtBnsPnlamt )),
				Str2Dbl(outp->BfDtEvalPnlAmt, sizeof(outp->BfDtEvalPnlAmt)),
				Str2Dbl(outp->PrdayCmpMktAmt, sizeof(outp->PrdayCmpMktAmt)),
				Str2Dbl(outp->HldQty        , sizeof(outp->HldQty        )),
				Str2Dbl(outp->DtBnsplAmt    , sizeof(outp->DtBnsplAmt    )),
				Str2Dbl(outp->MthBnsplAmt   , sizeof(outp->MthBnsplAmt   )),
				Str2Dbl(outp->BnsplAmt      , sizeof(outp->BnsplAmt      )),
				Str2Dbl(outp->HldAmt        , sizeof(outp->HldAmt        )),
				Str2Dbl(outp->EvalAmt       , sizeof(outp->EvalAmt       )),
				Str2Dbl(outp->EvalPnlAmt    , sizeof(outp->EvalPnlAmt    )),
				Str2Dbl(outp->EvalErnrat    , sizeof(outp->EvalErnrat    )),
				Str2Dbl(outp->BuyLmtAmt     , sizeof(outp->BuyLmtAmt     )),
				Str2Dbl(outp->PnlSumAmt     , sizeof(outp->PnlSumAmt     )),
				Str2Dbl(outp->BalPnlSt      , sizeof(outp->BalPnlSt      ))
			);

			if(MDBQuery(query) < 0)
			{
				g_Log.Write("[%d:%s] Insert ITMS0110 Error", g_Pid, __FILE__);
				return -1;
			}
			else g_Log.Write("[%d:%s] Insert ITMS0110", g_Pid, __FILE__);


			first = 0;
		}

		for(i = 0; i < datacnt; i++)
		{
g_Log.Write("[%d:%s]%d-펀드코드        [%s]", g_Pid, __FILE__, i, g_fundcd);
g_Log.Write("[%d:%s]%d-펀드명          [%.40s]", g_Pid, __FILE__, i, outp->FundNm);
g_Log.Write("[%d:%s]%d-종목번호        [%.12s]", g_Pid, __FILE__, i, outsubp->IsuNo);
g_Log.Write("[%d:%s]%d-종목명          [%.40s]", g_Pid, __FILE__, i, outsubp->IsuNm);
g_Log.Write("[%d:%s]%d-전일보유수량    [%.16s]", g_Pid, __FILE__, i, outsubp->PrdayHldQty     );
g_Log.Write("[%d:%s]%d-금일보유수량    [%.16s]", g_Pid, __FILE__, i, outsubp->CrdayHldQty     );
g_Log.Write("[%d:%s]%d-금일매수체결수량[%.16s]", g_Pid, __FILE__, i, outsubp->CrdayBuyExecQty );
g_Log.Write("[%d:%s]%d-금일매도체결수량[%.16s]", g_Pid, __FILE__, i, outsubp->CrdaySellExecQty);
g_Log.Write("[%d:%s]%d-주문가능수량    [%.16s]", g_Pid, __FILE__, i, outsubp->OrdAbleQty      );
g_Log.Write("[%d:%s]%d-장부단가        [%.15s]", g_Pid, __FILE__, i, outsubp->BookUprc        );
g_Log.Write("[%d:%s]%d-현재가          [%.13s]", g_Pid, __FILE__, i, outsubp->Curprc          );
g_Log.Write("[%d:%s]%d-매도단가        [%.15s]", g_Pid, __FILE__, i, outsubp->SellUprc        );
g_Log.Write("[%d:%s]%d-매수단가        [%.15s]", g_Pid, __FILE__, i, outsubp->BuyUprc         );
g_Log.Write("[%d:%s]%d-매매손익금액    [%.16s]", g_Pid, __FILE__, i, outsubp->BnsplAmt        );
g_Log.Write("[%d:%s]%d-평가수익률      [%.12s]", g_Pid, __FILE__, i, outsubp->EvalErnrat      );
g_Log.Write("[%d:%s]%d-평가손익금액    [%.16s]", g_Pid, __FILE__, i, outsubp->EvalPnlAmt      );
g_Log.Write("[%d:%s]%d-금일보유비율    [%.12s]", g_Pid, __FILE__, i, outsubp->CrdayHldRat     );
g_Log.Write("[%d:%s]%d-운용비율        [%.10s]", g_Pid, __FILE__, i, outsubp->OpRat           );
g_Log.Write("[%d:%s]%d-평가금액        [%.16s]", g_Pid, __FILE__, i, outsubp->EvalAmt         );
g_Log.Write("[%d:%s]%d-장부금액        [%.16s]", g_Pid, __FILE__, i, outsubp->BookAmt         );

			sprintf(query,
				" INSERT INTO ITMS0120   \n"
				" VALUES                 \n"
				" (                      \n"
				" NULL ,                 \n"
				" CURDATE(),             \n"
				" '%s',                  \n"
				" TRIM('%.*s'),          \n"
				" TRIM('%.*s'),          \n"
				" TRIM('%.*s'),          \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" %f ,                   \n"
				" SYSDATE()              \n"
				" )                      \n"
				,
				g_fundcd,
				sizeof(outp->FundNm  ), outp->FundNm  ,
				sizeof(outsubp->IsuNo), outsubp->IsuNo,
				sizeof(outsubp->IsuNm), outsubp->IsuNm,
				Str2Dbl(outsubp->PrdayHldQty     ,sizeof(outsubp->PrdayHldQty     )),
				Str2Dbl(outsubp->CrdayHldQty     ,sizeof(outsubp->CrdayHldQty     )),
				Str2Dbl(outsubp->CrdayBuyExecQty ,sizeof(outsubp->CrdayBuyExecQty )),
				Str2Dbl(outsubp->CrdaySellExecQty,sizeof(outsubp->CrdaySellExecQty)),
				Str2Dbl(outsubp->OrdAbleQty      ,sizeof(outsubp->OrdAbleQty      )),
				Str2Dbl(outsubp->BookUprc        ,sizeof(outsubp->BookUprc        )),
				Str2Dbl(outsubp->Curprc          ,sizeof(outsubp->Curprc          )),
				Str2Dbl(outsubp->SellUprc        ,sizeof(outsubp->SellUprc        )),
				Str2Dbl(outsubp->BuyUprc         ,sizeof(outsubp->BuyUprc         )),
				Str2Dbl(outsubp->BnsplAmt        ,sizeof(outsubp->BnsplAmt        )),
				Str2Dbl(outsubp->EvalErnrat      ,sizeof(outsubp->EvalErnrat      )),
				Str2Dbl(outsubp->EvalPnlAmt      ,sizeof(outsubp->EvalPnlAmt      )),
				Str2Dbl(outsubp->CrdayHldRat     ,sizeof(outsubp->CrdayHldRat     )),
				Str2Dbl(outsubp->OpRat           ,sizeof(outsubp->OpRat           )),
				Str2Dbl(outsubp->EvalAmt         ,sizeof(outsubp->EvalAmt         )),
				Str2Dbl(outsubp->BookAmt         ,sizeof(outsubp->BookAmt         ))
			);

			if(MDBQuery(query) < 0)
			{
				g_Log.Write("[%d:%s] Insert ITMS0120 Error", g_Pid, __FILE__);
				return -1;
			}
			else g_Log.Write("[%d:%s] Insert ITMS0120", g_Pid, __FILE__);
			outsubp++;
		}

        if(tmp1[0] == 'Y')
        {
			reptdiv = tmp1[0];
			memcpy(reptkey, tmp2, 18);
        }
        else break;
	}
    return 1;
}

int main(int argc, char **argv)
{
	g_Pid = getpid();
	strcpy(g_PgmName, "itms1001");

	if(GetOption(argc, argv) < 0)
	{
		printf("Option Errort\n");
		return -1;
	}

	g_Log.Write("[%d:%s] [%s] Process Start====================", 
		g_Pid, __FILE__, g_PgmName);

	g_Log.Write("[%d:%s] FUND[%s] BRCH[%s] ID[%s]", 
		g_Pid, __FILE__, g_fundcd, g_brchno, g_userid);

	chdir(g_HomePath);
	SignalSet();

	if(MDBConnect() < 0)
	{
		g_Log.Write("[%d:%s] DBConnect Error", g_Pid, __FILE__);
		return -1;
	}
	else g_Log.Write("[%d:%s] DBConnect OK", g_Pid, __FILE__);

	if(MainProc() < 0)
	{
		MDBRollback();
		g_Log.Write("[%d:%s] DB RollBack ", g_Pid, __FILE__);
		return -1;
	}
	MDBCommit();
	g_Log.Write("[%d:%s] DB COMMIT ", g_Pid, __FILE__);

	MDBClose();

	g_Log.Write("[%d:%s] [%s] Process End====================", 
		g_Pid, __FILE__, g_PgmName);

	return 1;
}
