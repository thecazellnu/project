#ifndef __CLOG_H__
#define __CLOG_H__

class CLog
{
public :
// Constructure & Destructure
	CLog();
	CLog(char *name);
	~CLog();

// Attribute
public :

protected :
	char	m_Name[256];
	char	m_FileName[256];
	char    m_Date[16];
	char    m_Time[16];

public :

// Member Method
private :

public :
	int	 Open(const char *name);
	void  GetDate();
	void  SetFile();	
	int  Close();
	void Write(const char *fmt,...);
};

#endif
/**********************************************************************/
