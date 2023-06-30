#include "CirDNode.h"
#include <stdio.h>
#include <stdlib.h>

CirDLinkList CirDList_TailInsert(CirDLinkList &L, CirDNodeElemType x){
    CirDLinkList newNode = (CirDNode *)malloc(sizeof(CirDNode));
    newNode->data = x;
    newNode->next = L;
    newNode->pre = L->pre;
    L->pre->next = newNode;
    L->pre = newNode;

    return newNode;
}