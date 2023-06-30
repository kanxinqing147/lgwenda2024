#include <stdio.h>
#include <stdlib.h>
#include "CirDNode.h"

bool Symmetry(CirDLinkList L)
{
    CirDNode *left = L->next, *right = L->pre;

    while (left != right)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->pre;
    }
    
    return true;
}


int main()
{
    CirDLinkList L = (CirDNode *)malloc(sizeof(CirDNode));

    L->next = L;
    L->pre = L;
    CirDList_TailInsert(L, 1);
    CirDList_TailInsert(L, 2);
    CirDList_TailInsert(L, 4);

    printf("%d\n", Symmetry(L));

    return 0;
}