#include "CirLNode.h"
#include <stdio.h>
#include <stdlib.h>

CirLinkList CirList_TailInsert(CirLinkList &L, CirLNodeElemType x)
{
    CirLinkList newNode = (CirLNode *)malloc(sizeof(CirLNode));
    newNode->data = x;
    newNode->next = L;

    CirLinkList tail;
    for (tail = L; tail->next != L; tail = tail->next)
        ;
    tail->next = newNode;

    return newNode;
}

void PrintCirLNode(CirLinkList L)
{
    for (CirLNode *i = L; i->next != L; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}
