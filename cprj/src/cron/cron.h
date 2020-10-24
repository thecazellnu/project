#ifndef __CRON_H__
#define __CRON_H__

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <memory.h>
#include <pwd.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/dir.h>
#include <dirent.h>

#include "log.h"
#include "common.h"
#include "pslist.h"
#include "socklib.h"

#define SQLCODE sqlca.sqlcode
#define SQLERRMSG sqlca.sqlerrm.sqlerrmc

pthread_mutex_t	g_Mutex;

extern "C" 
{
	__pid_t wait3(int *n, int option, struct rusage *rusage);
}

SockLib *g_IFSvr = NULL;
PSList  g_PSList;
CLog	g_Log;
int     g_Pid = -1;
int     gi_Port = 16384;
int     gi_ListChange = 0;
int		g_Running = TRUE;
char	g_PgmName[128];

void SetLog();
int DbConnect();
int Initialize(int, char **);
int GetDateInfo(int);
int GetDateInfoDB();
int DiffMonthDay(char *);
int DiffWeekDay(char *);
int DiffBizDay(char *);
int DiffDate(char *);
int DiffTime(char *, char *);
int killPS(int, PSInfo*);
int RunningClientDB();
int runPS(PSInfo *);
int CheckChildProc(int);
int UpdatePid(char *, int);
int KillAllProcessDB();
void Terminate();
int MainLoop();

extern "C" 
{
void sig_child(int);
void sig_term(int);
void sig_int(int);
void sig_pipe(int);
void SignalSet();
}

#endif
