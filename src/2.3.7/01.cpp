#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Delete_X(LinkList &L, ElemType x)
{
    if (L == NULL)
    {
        return;
    }

    if (L->data == x)
    {
        LinkList p = L;
        L = L->next;
        free(p);
        Delete_X(L, x);
    }
    else
    {
        Delete_X(L->next, x);
    }
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->data = 1;
    L->next = NULL;
    List_TailInsert(L, 2);
    List_TailInsert(L, 2);
    List_TailInsert(L, 3);
    List_TailInsert(L, 4);

    Delete_X(L, 2);
    PrintLNode(L);

    return 0;
}