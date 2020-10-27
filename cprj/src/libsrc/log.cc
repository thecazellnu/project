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

#include "log.h"

CLog::CLog()
{
}

CLog::CLog(char *name)
{
	strcpy(m_Name, name);
}

CLog::~CLog()
{
}
void CLog::GetDate()
{
	time_t    timeval;
	struct tm *tp;
	struct timeval usec;
	time(&timeval);
	tp = localtime(&timeval);
	sprintf(m_Date, "%04d%02d%02d", 
        tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday);
    gettimeofday(&usec, NULL);
    sprintf(m_Time, "%02d:%02d:%02d-%06ld", 
        tp->tm_hour, tp->tm_min, tp->tm_sec, usec.tv_usec);

	return;
}

void CLog::SetFile()
{
	GetDate();
	sprintf(m_FileName,"%s.%s", m_Name, m_Date);
	return;
}

int CLog::Open(const char *name)
{
	strcpy(m_Name, name);
	return 1;
}

int CLog::Close()
{
	return 1;
}

void CLog::Write(const char *fmt,...)
{
	va_list args;
	char	msgbuff[8192];
	int     len;
	FILE	*fp;

    SetFile();

	fp = fopen(m_FileName, "a+t");
	if(fp != NULL) 
    {
		va_start(args, fmt);
		len = vsprintf(msgbuff, fmt, args);
		va_end(args);
        fprintf(fp,"[%s]%s\n", m_Time, msgbuff);
		fclose(fp);
		fp = NULL;
	}
}
