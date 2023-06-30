#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

ElemType List_Locate_Head(LinkList l, int k)
{
    LNode *p = l->next, *q = l->next;
    for (int i = 1; p != NULL && i < k; i++)
    {
        p = p->next;
    }

    for (q = l; p != NULL; p = p->next, q = q->next)
        ;
    
    return q->data;
}

int main()
{
    LinkList l = (LNode *)malloc(sizeof(LNode));

    l->next = NULL;
    List_TailInsert(l, 1);
    List_TailInsert(l, 2);
    List_TailInsert(l, 3);
    List_TailInsert(l, 4);
    List_TailInsert(l, 5);

    printf("%d\n", List_Locate_Head(l, 3));

    return 0;
}