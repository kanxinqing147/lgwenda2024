#ifndef _Cir_DNODE_H_
#define _Cir_DNODE_H_

#define CirDNodeElemType int

typedef struct CirDNode
{
    CirDNodeElemType data; 
    struct CirDNode* next;
    struct CirDNode* pre;
}CirDNode, *CirDLinkList;

extern CirDLinkList CirDList_TailInsert(CirDLinkList &L, CirDNodeElemType x);

#endif