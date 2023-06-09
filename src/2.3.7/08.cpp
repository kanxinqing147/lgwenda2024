#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LinkList SearchCommon(LinkList &L1, LinkList &L2)
{
    for (LinkList i1 = L1; i1->next != NULL; i1 = i1->next)
    {
        for (LinkList i2 = L2; i2->next != NULL; i2 = i2->next)
        {
            if (i1->next == i2->next)
            {
                return i1->next;
            }
            
        } 
    }
    

    return NULL;
}

int main()
{
    LinkList L1 = (LNode *)malloc(sizeof(LNode));
    LinkList L2 = (LNode *)malloc(sizeof(LNode));

    L1->data = 10;
    L1->next = NULL;
    List_TailInsert(L1, 11);
    List_TailInsert(L1, 12);
    LinkList Common = List_TailInsert(L1, 13);

    L2->data = 1;
    L2->next = Common;
    List_TailInsert(L2, 3);
    List_TailInsert(L2, 4);
    List_TailInsert(L2, 5);

    LinkList res = SearchCommon(L1, L2);
    PrintLNode(res);

    return 0;
}