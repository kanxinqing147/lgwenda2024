#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void SortLNode(LinkList &L)
{
    for (LinkList i = L->next; i != NULL; i = i->next)
    {
        for (LinkList j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                ElemType temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->next = NULL;
    List_TailInsert(L, 3);
    List_TailInsert(L, 2);
    List_TailInsert(L, 5);
    List_TailInsert(L, 1);
    List_TailInsert(L, 4);

    SortLNode(L);
    PrintLNode(L->next);

    return 0;
}