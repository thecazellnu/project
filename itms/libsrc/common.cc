#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>
#ifdef GCC
#include <varargs.h>
#endif
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "common.h"

#ifndef _PATH_DEVNULL
#define _PATH_DEVNULL       "/dev/null"
#endif
int Daemon(char *dir, int  io)
{
    int cpid;
    if ((cpid = fork()) == -1)
        return (-1);
    if (cpid)
        exit(0);
    (void) setsid();
    if (dir)
        (void) chdir(dir);
    if (io) {
        int devnull = open(_PATH_DEVNULL, O_RDWR, 0);
        if (devnull != -1) {
            (void) dup2(devnull, 0);
            (void) dup2(devnull, 1);
            (void) dup2(devnull, 2);
            if (devnull > 2)
                (void) close(devnull);
        }
    }
    return 1;
}

int Sleep(int sec, int msec)
{
    struct  timeval     tout;
    int     rc;

    tout.tv_sec = sec;              /* Second */
    tout.tv_usec = msec;        /* micro Second */
    rc = select(0,NULL,(fd_set *)0,(fd_set *)0,(struct timeval *)&tout);
    return rc;
}

void GetDateTime(char *dateinfo)
{
    time_t  timeval;
    struct  tm *tp;
    time(&timeval);
    tp = localtime(&timeval);
    sprintf(dateinfo, "%04d%02d%02d%02d%02d%02d",
        tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday,
        tp->tm_hour, tp->tm_min, tp->tm_sec);
    return;
}

void GetDateTimeSec(char *dateinfo)
{
    time_t  timeval;
    struct  tm *tp;
	struct	timeval usec; 
    time(&timeval);
    tp = localtime(&timeval);
	gettimeofday(&usec, NULL);
    sprintf(dateinfo, "%04d%02d%02d%02d%02d%02d%06ld",
        tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday,
        tp->tm_hour, tp->tm_min, tp->tm_sec, usec.tv_usec);
    return;
}

static int CutItemName(char *src, char *tar)
{
    while(src) {
        if(*src > ' ') break;
        src++;
    }
    if(*src <= ' ') return 0;
    while(1) {
        if(*src == 0 || *src <= ' ' || *src == '=' || *src == ']') break;
        *tar++ = *src++;
    }
    *tar = 0;
    if(strlen(tar) > 0) return 1;
    return 0;
}

static int GetString(unsigned char *src, unsigned char *tar)
{
    while(src) {
        if(*src == '=') break;
        src++;
    }
    if(*src != '=') return 0;
    src++;
    while(1) {
        if(*src == 0 || *src > 0x20) break;
        else if(*src <= 0x20) src++;
    }
    if(*src == 0) return 0;
    while(1) {
        *tar++ = *src++;
        if(*src < 0x20) break;
    }
    *tar = 0;
    return 1;
}

int GetCfg(char *filepath, char *filename, char *tablename,
        char *itemname, char *defname, char *buff)
{
    FILE *fp;
    char FileName[100], rbuf[1024], tmp[100];
    if(filepath == NULL)
        sprintf(FileName, "%s", filename);
    else if(*filepath == '/')
        sprintf(FileName, "%s/%s", filepath, filename);
    else
        sprintf(FileName, "./%s/%s", filepath, filename);

    if((fp = fopen(FileName, "rt")) == NULL) 
	{
        strcpy(buff, defname);
        return 0;
    }

    while(fgets(rbuf, 512, fp)) {
        if(rbuf[0] == '[') {
            CutItemName(&rbuf[1], tmp);
            if(strlen(tmp) != strlen(tablename)) continue;
            if(strncmp(&rbuf[1], tablename, strlen(tablename)) == 0) {
                while(fgets(rbuf, 512, fp)) {
                    if(rbuf[0] == '[') break;
                    if(rbuf[0] != '#' && rbuf[0] != ';') {
                        CutItemName(rbuf, tmp);
                        if(strlen(tmp) != strlen(itemname)) continue;
                        if(strncmp(tmp, itemname, strlen(itemname)) == 0) {
                            GetString((unsigned char *)rbuf,
                                        (unsigned char *)buff);

                            fclose(fp);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    strcpy(buff, defname);
    fclose(fp);
    return 0;
}

long Str2Long(char *str, int len)
{
	char tmp[32];
	strncpy(tmp, str, len);
	return atol(tmp);
}

int Str2Int(char *str, int len)
{
	char tmp[32];
	strncpy(tmp, str, len);
	return atoi(tmp);
}

double Str2Float(char *str, int len)
{
	char tmp[32];
	strncpy(tmp, str, len);
	return atof(tmp);
}

double Str2Dbl(char *str, int size)
{
    char tmp[64];
    char *ptr;

    if(size>64) size=64;
    if(size<0)  size=0;
    memcpy(tmp,str,size);
	tmp[size]=(char)NULL;
    ptr = &tmp[size];
    return(strtod(tmp,&ptr));
}

void Int2Str(int val, char *str, int size)
{
	int len = size;
	char tmp[64];
	if(val < 0) len -= 1;
	if(len < 0) len = 0;
	sprintf(tmp, "%#0*.*d", len, len, val);
	memcpy(str, tmp, size);
}

void Long2Str(long val, char *str, int size)
{
	int len = size;
	char tmp[64];
	if(val < 0) len -= 1;
	if(len < 0) len = 0;
	sprintf(tmp, "%#0*.*ld", len, len, val);
	memcpy(str, tmp, size);
}

int GetIpAddr(char *ip)
{
    char   temp[256];
    struct hostent *hp;
   
    if(gethostname(temp, sizeof (temp)))
        return -1;

    if((hp = gethostbyname(temp)) == NULL)
        return -1;

    strcpy(ip, (char *)inet_ntoa(*(struct in_addr *)hp->h_addr));
    return 1;
}

int IpConv(char *inip, char *outip)
{
    int  ii,jj,kk;
    char tip[4][3];

    jj = kk = 0;
    for(ii=0; ii < strlen(inip); ii++)
    {
        if(inip[ii] != '.')
        {
            tip[jj][kk] = inip[ii];
            kk++;
        }
        else
        {
            jj++;
            kk = 0;
        }
    }
    sprintf(outip,"%.3d%.3d%.3d%.3d",
        Str2Int(tip[0],3), 
		Str2Int(tip[1],3),
		Str2Int(tip[2],3),
		Str2Int(tip[3],3));
	return 1;
}

