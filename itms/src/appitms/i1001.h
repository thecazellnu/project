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

#include <mysql.h>
#include <errno.h>

#include "dblib.h"
#include "log.h"
#include "socklib.h"
#include "common.h"
#include "fepst.h"
#include "seqfile.h"
#include "socklist.h"
#include "tradest.h"
#include "fepcomm.h"

CLog g_Log;

SockLib *g_FepCli = NULL;

int g_Pid = -1;
int g_Running = 1;

char    g_PgmName[64];
char    g_HomePath[128];
char	g_fundcd[16];
char	g_brchno[16];
char	g_userid[16];
