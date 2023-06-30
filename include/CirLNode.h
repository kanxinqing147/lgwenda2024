#ifndef _Cir_LNODE_H_
#define _Cir_LNODE_H_

#define CirLNodeElemType int

typedef struct CirLNode
{
    CirLNodeElemType data;
    struct CirLNode *next;
}CirLNode, *CirLinkList;

extern CirLinkList CirList_TailInsert(CirLinkList &L, CirLNodeElemType x);
void PrintCirLNode(CirLinkList L);

#endif