#ifndef __FEPCLI_H__
#define __FEPCLI_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <memory.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/stat.h>
//#include <sqlca.h>
//#include <sqlcpr.h>

#include "log.h"
#include "socklib.h"
#include "common.h"
#include "fepst.h"
#include "seqfile.h"
#include "socklist.h"

CLog g_Log;
CDataList g_trList;
SockLib *g_toFepCli = NULL;
SockLib *g_frFepCli = NULL;
SockLib *g_rqFepSvr = NULL;

int g_Pid = -1;
int g_Running = 1;
int g_toFailed = 0;
int g_frFailed = 0;

char	g_PgmName[64];
char	g_HomePath[128];

char	g_toSeqPath[128];
char	g_frSeqPath[128];
int		g_toSeqLen = 0;
int		g_frSeqLen = 0;

#ifdef __cplusplus
extern "C"{
#endif
void sig_term(int);
void sig_int(int);
void sig_pipe(int);
void sig_segv(int);
void SignalSet();
#ifdef __cplusplus
}
#endif

int FepCli(char *, int );

#endif
