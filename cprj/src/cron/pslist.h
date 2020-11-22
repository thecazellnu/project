#ifndef __PSLIST_H__
#define __PSLIST_H__

#include "list.h"
#include "common.h"

typedef struct
{
    char    rowid       [20  + 1];
    char    name        [128 + 1];
    char    month       [16  + 1];
    char    week        [16  + 1];
    char    bizday      [16  + 1];
    char    execdate    [8   + 1];
    char    attribute   [8   + 1];
    char    bintype     [8   + 1];
    char    sttime      [6   + 1];
    char    edtime      [6   + 1];
    char    path        [256 + 1];
    char    argv        [256 + 1];
    char    descript    [256 + 1];
    char    useyn       [1   + 1];
    char    last        [14  + 1];
    char    dbupdate    [1   + 1];
    int     pid                  ;
    int     runcnt               ;
    int     write                ;
}PSInfo;

class PSList : public CList
{
    public:
        PSList()
        {
            CList:CList();
        };
        ~PSList()
        {
        };

        PSInfo *SearchPid(int pid)
        {
            if(m_Count <= 0 || pid <= 1) return NULL;

            CNode *pNode;
            for(pNode = GetFirst();
                pNode != NULL;
                pNode = GetNext(pNode))
            {
                if(pNode->m_pData)
                    if(((PSInfo *)pNode->m_pData)->pid == pid)
                        return (PSInfo *)pNode->m_pData;
            }
            return NULL;
        }

        void Empty()
        {
            CNode *pNode;
            while(pNode = GetFirst()) 
            {
                if(pNode->m_pData != NULL)
                    delete (PSInfo *)pNode->m_pData;
                Del(pNode);
                pNode = pNode->m_pNext;
            }
            return;
        }

};

#endif
