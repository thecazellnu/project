#ifndef __SOCKLIST_H__
#define __SOCKLIST_H__

#include "socklib.h"
#include "list.h"

typedef struct
{
	SockLib *Class;
	long seqno;
}DataBlock;

class CDataList : public CList
{
public:	
	CDataList()
	{
		CList:CList();
	};
	~CDataList()
	{
	};

	DataBlock *Find(long seqno)
	{
		if(m_Count <= 0 || seqno < 1) return NULL;

		CNode *pNode = m_pHead;
		while(pNode) {
			if(((DataBlock *)pNode->m_pData)->seqno == seqno)
			{
				return (DataBlock *)pNode->m_pData;
			}
			pNode = pNode->m_pNext;
		}
		return NULL;
	}

public:	
};

#endif
