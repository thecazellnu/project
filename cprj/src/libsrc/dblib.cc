#include <stdio.h>
#include <mysql.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "log.h"
#include "dblib.h"
MYSQL g_MySQL01;

extern int g_Pid;
extern CLog g_Log;

int MDBConnect()
{
	mysql_init(&g_MySQL01);

	g_Log.Write("[%d:%s] DBINFO IP[%s]PS[%s]PT[%d]SK[%s]US[%s]", 
		g_Pid, __FILE__, getenv("DB_IP"),  getenv("DB_PASS"),
		atoi(getenv("DB_PORT")),  getenv("DB_SOCK"), getenv("DB_USER"));

	if(!mysql_real_connect(&g_MySQL01, getenv("DB_IP"), getenv("DB_USER"), 
		getenv("DB_PASS"), "itms", atoi(getenv("DB_PORT")), 
		getenv("DB_SOCK"), 0))
	{
		g_Log.Write("[%d:%s] MariaDB Conn Error [%s]", 
			g_Pid, __FILE__, mysql_error(&g_MySQL01));
		return -1;
	}

	mysql_query(&g_MySQL01, "SET NAMES euckr");
	mysql_autocommit(&g_MySQL01, false);
	return 1;
}

int MDBQuery(char *qry)
{
	char buff[32];
    GetCfg(getenv("ITMS_CFG"), (char *)"commom.cfg", (char *)"COMMON",
        (char *)"LOG_QRY", (char *)"1", buff);
	
	if(atoi(buff)) g_Log.Write("[%d:%s] QRY\n%s", g_Pid, __FILE__, qry);

	if(mysql_query(&g_MySQL01, qry) != 0)
	{
		g_Log.Write("[%d:%s] Error QRY\n%s",
			g_Pid, __FILE__, qry );
		g_Log.Write("[%d:%s] Qry Excute Error [%s]", 
			g_Pid, __FILE__, mysql_error(&g_MySQL01));
		return -1;
	}
	return 1;
}

int MDBCommit()
{
	if(mysql_commit(&g_MySQL01) != 0) return -1;
	return 1;
}

int MDBRollback()
{
	if(mysql_rollback(&g_MySQL01) != 0) return -1;
	return 1;
}

int MDBClose()
{
	mysql_close(&g_MySQL01);
	return 1;
}
