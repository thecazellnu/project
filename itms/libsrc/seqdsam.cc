#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"common.h"
#include"log.h"

extern int g_Pid;
extern CLog g_Log;

DSAM_HANDLE *g_Seq;

int InitialSeq(char *path, int len)
{
	FILE *fp;
	char today[8];
	char buff[32];
	long seqno = 0;

	GetDateTime(buff);
	memcpy(today, buff, 8);

	*g_Seq= dsam_init(1, path);
	if(*g_Seq == NULL)
	{
		g_Log.Write("[%d:%s] Seq Initailize Error", g_Pid, __FILE__);
		return -1;
	}

	if(dsam_open(*g_Seq, DSAM_RDWT) < 0)
	{
		if(dsam_crate(*g_Seq, 8 + len, 1) < 0)
		{
			dsam_destory(*g_Seq);
			g_Log.Write("[%d:%s] Seq Create Error", g_Pid, __FILE__);
			return -1;
		}
		else
		{
			sprintf(buff, "%.8s%0*ld", today, len, 0); 
			if(dsam_write(*g_Seq, (char *)"1", 1, buff, sizeof(buff)) < 0)
			{
				dsam_destory(*g_Seq);
				g_Log.Write("[%d:%s] Seq Write Error", g_Pid, __FILE__);
				return -1;
			}
			dsam_destory(*g_Seq);
			g_Log.Write("[%d:%s] New SeqCreate", g_Pid, __FILE__);
			return 1;
		}
	}

	if(dsam_read(*g_Seq, (char*)"1", 1, EQ, buff, 1)< 0)
	{
	}

	if(dsam_write(*g_Seq, (char *)"1", 1, buff, sizeof(buff)) < 0)
	



	if(

	fp = fopen(path, "rb+");
	if(fp == NULL)
	{
		fp = fopen(path, "wb+");
		if (fp == NULL) return -1;
		fprintf(fp, "%.8s%0*ld\n", today, len, seqno); 
		g_Log.Write("[%d:%s] Create New Date SeqFile today[%.8s][%ld]", 
			g_Pid, __FILE__, today, seqno);
	}
	else
	{
		if(fgets(buff, sizeof(buff), fp) == NULL)
		{
			fclose(fp);
			fp = fopen(path, "wb+");
			if (fp == NULL) return -1;
			fprintf(fp, "%.8s%0*ld\n", today, len, seqno); 
			g_Log.Write("[%d:%s] ReCreate SeqData today[%.8s]", 
				g_Pid, __FILE__, today);
		}
		else 
		{
			if(!memcmp(buff, today, 8))
			{
				g_Log.Write("[%d:%s] Current dt[%.8s] Seqno[%.*s]",
					g_Pid, __FILE__, buff, len, buff + 8);
			}
			else 
			{
				fclose(fp);
				fp = fopen(path, "wb+");
				if (fp == NULL) return -1;
				fprintf(fp, "%.8s%0*ld\n", today, len, seqno); 
				g_Log.Write("[%d:%s] Update New Date SeqFile today[%.8s]", 
					g_Pid, __FILE__, today);
			}
		}
	}
	fclose(fp);
	return 1;
}

long GetCurSeq(char *path, int len)
{
	FILE *fp;	
	char tmp[16];
	char buff[32];

	fp = fopen(path, "rb+");
	if(fp)
	{
		if(fgets(buff, sizeof(buff), fp) == NULL) 
		{
			g_Log.Write("[%d:%d] fget Err[%s][%x]", g_Pid, __LINE__, buff,fp); 
			fclose(fp);
			return -1;
		}
		memset(tmp, 0x00, sizeof(tmp));
		memcpy(tmp, buff + 8, len);
		fclose(fp);
		return atol(tmp);
	}
	g_Log.Write("[%d:%d] fopen Error[%x]", g_Pid, __LINE__, fp); 
	fclose(fp);
	return -1;
}

long GetNextSeq(char *path, int len)
{
	FILE *fp;	
	char tmp[16];
	char buff[32];
	long seqno;

	fp = fopen(path, "rb+");
	if(fp)
	{
		if(fgets(buff, sizeof(buff), fp) == NULL)
		{
			g_Log.Write("[%d:%d] fget Err[%s][%x]", g_Pid, __LINE__, buff,fp); 
			fclose(fp);
			return -1;
		}
		memset(tmp, 0x00, sizeof(tmp));
		memcpy(tmp, buff + 8, len);
		seqno = atol(tmp);
		fclose(fp);
		fp = fopen(path, "wb+");
		if(fp)
		{
			seqno++;
			fprintf(fp, "%.8s%0*ld\n", buff, len, seqno);
			fclose(fp);
			return seqno;
		}
		else 
		{
			g_Log.Write("[%d:%d] Re fopen Error[%x]", g_Pid, __LINE__, fp); 
			return -1;
		}
	}
	g_Log.Write("[%d:%d] fopen Error[%x]", g_Pid, __LINE__, fp); 
	fclose(fp);
	return -1;
}

long WriteSeqno(char *path, int len, long seq)
{
	FILE *fp;	
	char buff[32];
	long seqno;

	fp = fopen(path, "rb+");
	if(fp)
	{
		if(fgets(buff, sizeof(buff), fp) == NULL)
		{
			g_Log.Write("[%d:%d] FGets Error[%s]", g_Pid, __LINE__, buff); 
			fclose(fp);
			return -1;
		}
		fclose(fp);
		fp = fopen(path, "wb+");
		if(fp)
		{
			fprintf(fp, "%.8s%0*ld\n", buff, len, seq);
			fclose(fp);
			return seq;
		}
		else
		{
			g_Log.Write("[%d:%d] Re fopen Error[%x]", g_Pid, __LINE__, fp); 
			return -1;
		}
	}
	g_Log.Write("[%d:%d] fopen Error[%x]", g_Pid, __LINE__, fp); 
	fclose(fp);
	return -1;
}
