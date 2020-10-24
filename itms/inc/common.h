#ifndef __COMMON_H__
#define __COMMON_H__

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef ERROR
#define ERROR -1
#endif

#ifndef NULL
#define NULL 0x00
#endif

#include "list.h"



int Daemon(char *, int);
int Sleep(int, int);
void GetDateTime(char *);
void GetDateTimeSec(char *);
int GetCfg(char *, char *, char *, char *, char *, char *);

int Str2Int(char *, int );
long Str2Long(char *, int );
double Str2Float(char *, int );
double Str2Dbl(char *, int );
void Int2Str(int, char *, int);
void Long2Str(long, char *, int);

int GetIpAddr(char *);
int IpConv(char *, char *);



#endif
