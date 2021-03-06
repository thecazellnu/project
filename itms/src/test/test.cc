#include "test.h"

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

	getcwd(g_HomePath, sizeof(g_HomePath));

	memset(buff, 0x00, sizeof(buff));
	if(getenv("ITMS_LOG"))
		sprintf(buff, "%s/%s", getenv("ITMS_LOG"), g_PgmName);
	else 
		sprintf(buff, "/itms/log/%s", g_PgmName);
	g_Log.Open(buff);

	if(argc < 3) return -1;
	for(i = 1; i < argc; i++)
	{
		switch(i)
		{
			case 1:
				strncpy(g_Addr, argv[i], strlen(argv[i]));
				break;
			case 2:
				g_Port = atoi(argv[i]);
				break;
		}
	}

	return 1;
}

SockLib *CreateTcpCli(char *ip, int port)
{
	SockLib *ConCliSock = new SockLib();
	if((port < 0) || (ip == NULL)) return NULL;
	ConCliSock->SetBlockSocket(0);
	if(ConCliSock->Create(port, ip, SOCK_STREAM, -1) < 0) return NULL;
	if(ConCliSock->Connect() != TRUE) 
	{
		ConCliSock->Close();
		delete ConCliSock;
		return NULL;
	}
	return ConCliSock;
}

int TestSndHandler(SockLib *Class, int cmd, int len, char *data, void *tmp)
{
	switch(cmd)
	{
		case TS_START:
			g_Log.Write("[%d:%s] Connect From[%s][%d] T[%d]",
				g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
			printf("[%d:%s] Connect From[%s][%d] T[%d]\n",
				g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
			break;
		case TS_DATA:
			g_Log.Write("[%d:%s] Recv Data[%d][%s]",
				g_Pid, __FILE__, len, data);
			printf("[%d:%s] Recv Data[%d][%s]\n",
				g_Pid, __FILE__, len, data);
			break;
		case TS_TIMEOUT:
			g_Log.Write("[%d:%s] TimeOut [%s][%d] T[%d]",
				g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
			printf("[%d:%s] TimeOut [%s][%d] T[%d]\n",
				g_Pid, __FILE__, Class->m_Name, Class->m_rfd, Class->m_tid);
			break;
		case TS_CLOSE:
			g_Log.Write("[%d:%s] DisConnect FD[%d] T[%d]",
				g_Pid, __FILE__, Class->m_rfd, Class->m_tid);
			printf("[%d:%s] DisConnect FD[%d] T[%d]\n",
				g_Pid, __FILE__, Class->m_rfd, Class->m_tid);
			delete Class;
			g_TestCli = NULL;
			break;
	}
	return 1;
}

int Terminate()
{
	if(g_TestCli)  delete g_TestCli;
	//delete &g_Log;
	return 1;
}

int TESTCli()
{
	SockLib *TestCli = CreateTcpCli(g_Addr, g_Port);
	if(TestCli == NULL)
	{
		g_Log.Write("[%d:%s] Client Connection Error", g_Pid, __FILE__);
		printf("[%d:%s] Client Connection Error\n", g_Pid, __FILE__);
		
		return -1;
	}
	else 
	{
		g_Log.Write("[%d:%s] Client Connection IP[%s]PORT[%d]", g_Pid, __FILE__, g_Addr, g_Port);
		printf("[%d:%s] Client Connection IP[%s]PORT[%d]\n", g_Pid, __FILE__, g_Addr, g_Port);
	}
	TestCli->SetHandler(TestSndHandler);	
	TestCli->Start();
	g_TestCli = TestCli;

char sbuf[256];
memset(sbuf, 0x00, sizeof(sbuf));
sbuf[0] = STX;
memcpy(sbuf +1, "00011HELLO", 10);
g_TestCli->Write(sbuf, 11);
	return 1;
}

int InitSession()
{
	if(TESTCli() < 0) return -1;
	return 1;
}

int MainLoop()
{
	if(InitSession() < 0) return -1;

	while(g_Running)
	{
//		if(g_TestCli == NULL)  TESTCli();
printf("[%d:%s] Main Thread ====================\n", g_Pid, __FILE__);
		usleep(1000000);
	}
    return TRUE;
}

int main(int argc, char **argv)
{
	g_Pid = getpid();
	strcpy(g_PgmName, "test");

	if(GetOption(argc, argv) < 0)
	{
		printf("Usage : %s Ip Port\n", argv[0]);
		return -1;
	}

	g_Log.Write("[%d:%s] TEST Process Start====================", 
		g_Pid, __FILE__);
	printf("[%d:%s] TEST Process Start====================\n", 
		g_Pid, __FILE__);

	g_Log.Write("[%d:%s] IP[%s] PORT[%d]", 
		g_Pid, __FILE__, g_Addr, g_Port);
	printf("[%d:%s] IP[%s] PORT[%d]\n",
		g_Pid, __FILE__, g_Addr, g_Port);

	chdir(g_HomePath);
	SignalSet();

	MainLoop();

	g_Log.Write("[%d:%s] TEST Process End ====================", 
		g_Pid, __FILE__);
	printf("[%d:%s] TEST Process End ====================\n", 
		g_Pid, __FILE__);
	Terminate();

	return 1;
}
