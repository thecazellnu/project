#ifndef __CLIST_H__ 
#define __CLIST_H__ 
 
#include <pthread.h> 
#include <unistd.h> 
 
class CNode 
{ 
public:	 
	CNode() 
	{ 
		m_pPrev = NULL; 
		m_pNext = NULL; 
		m_pData = NULL; 
	}; 
	CNode(void *pData) 
	{ 
		m_pPrev = NULL; 
		m_pNext = NULL; 
		m_pData = pData; 
	}; 
	~CNode() 
	{ 
		m_pData = NULL; 
	}; 
	 
public:	 
	void* 	m_pData; 
 
	CNode *m_pPrev; 
	CNode *m_pNext; 
}; 
 
class CList 
{ 
public:	 
	CList() 
	{ 
		m_pHead = NULL; 
		m_pTail = NULL; 
		m_Count = 0; 
		pthread_mutex_init(&m_mut, NULL); 
	}; 
	~CList() 
	{ 
		pthread_mutex_lock(&m_mut); 
		CNode *pNode = m_pHead; 
		while(pNode) { 
			m_pHead = m_pHead->m_pNext; 
			delete pNode; 
			pNode = m_pHead; 
		} 
		pthread_mutex_unlock(&m_mut); 
		pthread_mutex_destroy(&m_mut); 
	}; 

	int Add(void *pData) 
	{ 
		pthread_mutex_lock(&m_mut); 
		CNode *pNode = new CNode(pData); 
		if (pNode == NULL) { 
			pthread_mutex_unlock(&m_mut); 
			return FALSE; 
		} 
		if(m_pHead == NULL) { 
			m_pHead = m_pTail = pNode; 
		} 
		else { 
			pNode->m_pPrev = m_pTail; 
			if (m_pTail != NULL) m_pTail->m_pNext = pNode; 
			m_pTail = pNode; 
		} 
		m_Count++; 
		pthread_mutex_unlock(&m_mut); 
		return TRUE; 
	}

	int Del(CNode *pNode) 
	{ 
		if (pNode == NULL) { 
			return FALSE; 
		} 
		pthread_mutex_lock(&m_mut); 
		if(pNode == m_pHead && pNode == m_pTail) { 
			m_pHead = NULL; 
			m_pTail = NULL; 
		} 
		else if(pNode == m_pHead) { 
			m_pHead = m_pHead->m_pNext; 
			if (m_pHead != NULL) m_pHead->m_pPrev = NULL; 
			//m_pHead->m_pPrev = NULL; 
		} 
		else if(pNode == m_pTail) { 
			m_pTail = m_pTail->m_pPrev; 
			if (m_pTail != NULL) m_pTail->m_pNext = NULL; 
			//m_pTail->m_pNext = NULL; 
		} 
		else { 
			if (pNode->m_pPrev != NULL)  
				pNode->m_pPrev->m_pNext = pNode->m_pNext; 
			if (pNode->m_pNext != NULL) 
				pNode->m_pNext->m_pPrev = pNode->m_pPrev; 
		} 
		delete pNode; 
		m_Count--; 
		if(m_Count < 0) m_Count = 0; 
		pthread_mutex_unlock(&m_mut); 
		return TRUE; 
	} 

	int Del(void *pData) 
	{ 
		pthread_mutex_lock(&m_mut); 
		CNode *pNode = m_pHead; 
		while(pNode) { 
			if(pNode->m_pData == pData)  
			{ 
				if(pNode == m_pHead && pNode == m_pTail) { 
					m_pHead = NULL; 
					m_pTail = NULL; 
				} 
				else if(pNode == m_pHead) { 
					m_pHead = m_pHead->m_pNext; 
					if (m_pHead != NULL) m_pHead->m_pPrev = NULL; 
					//m_pHead->m_pPrev = NULL; 
				} 
				else if(pNode == m_pTail) { 
					m_pTail = m_pTail->m_pPrev; 
					if (m_pTail != NULL) m_pTail->m_pNext = NULL; 
					//m_pTail->m_pNext = NULL; 
				} 
				else { 
					if (pNode->m_pPrev != NULL)  
						pNode->m_pPrev->m_pNext = pNode->m_pNext; 
					if (pNode->m_pNext != NULL) 
						pNode->m_pNext->m_pPrev = pNode->m_pPrev; 
				} 
				delete pNode; 
				m_Count--; 
				if(m_Count < 0) m_Count = 0; 
				pthread_mutex_unlock(&m_mut); 
				return TRUE; 
			} 
			pNode = pNode->m_pNext; 
		} 
		pthread_mutex_unlock(&m_mut); 
		return FALSE; 
	} 
	void Lock() 
	{ 
		pthread_mutex_lock(&m_mut); 
	} 
	void Unlock() 
	{ 
		pthread_mutex_unlock(&m_mut); 
	} 
	CNode *GetFirst() 
	{ 
		if(m_pHead == NULL) return NULL; 
		return m_pHead;  
	} 
	CNode *GetNext(CNode *pNode) 
	{ 
		if(pNode == NULL) return NULL; 
		return pNode->m_pNext; 
	} 
	CNode *GetPrev(CNode *pNode) 
	{ 
		if(pNode == NULL) return NULL; 
		return pNode->m_pPrev; 
	} 
	void *GetData(CNode *pNode) 
	{ 
		if(pNode == NULL) return NULL; 
		return pNode->m_pData; 
	} 
	int GetCount() 
	{ 
		return m_Count; 
	} 
 
public:	 
	pthread_mutex_t 	m_mut; 
	pthread_mutexattr_t	mutattr; 
	int		m_Count; 
	CNode*	m_pHead; 
	CNode*	m_pTail; 
}; 
 
#endif 
