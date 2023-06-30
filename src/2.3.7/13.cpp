#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void MergeList(LinkList &L1, LinkList &L2)
{
    LinkList i1 = L1, i2 = L2;

    while (i1 != NULL && i2 != NULL)
    {
        if (i1->data <= i2->data)
        {
            LinkList temp = i2;
            i2 = i2->next;
            temp->next = i1->next;
            i1->next = temp;
            i1 = temp->next;
        }
        else
        {
            LinkList temp = i2;
            i2 = i2->next;
            temp->next = i1;
            i1 = temp->next;
        }
    }

    if (i2 != NULL)
    {
        LinkList tail;
        for (tail = L1; tail->next != NULL; tail = tail->next)
            ;
        
        tail->next = i2;
    }
}

int main()
{
    LinkList L1 = (LNode *)malloc(sizeof(LNode));
    LinkList L2 = (LNode *)malloc(sizeof(LNode));

    L1->data = 1;   
    L1->next = NULL;
    List_TailInsert(L1, 3);
    List_TailInsert(L1, 5);
    List_TailInsert(L1, 7);

    L2->data = 2;
    L2->next = NULL;
    List_TailInsert(L2, 4);
    List_TailInsert(L2, 6);

    MergeList(L1, L2);
    PrintLNode(L1);

    return 0;
}