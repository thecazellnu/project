#ifndef __TEST_H__
#define __TEST_H__

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

#include "log.h"
#include "socklib.h"
#include "dsamdef.h"

CLog g_Log;
SockLib *g_TestCli = NULL;

int g_Pid = -1;
int g_Running = 1;

char	g_PgmName[64];
char	g_HomePath[128];
char	g_Addr[16];
int		g_Port;

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

#endif

