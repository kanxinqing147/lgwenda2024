#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Delete_X(LinkList &L, ElemType x)
{
    LinkList prev = L, p = L->next;

    while (p != NULL)
    {
        if (p->data == x)
        {
            LinkList temp = p;
            prev->next = p->next;
            p = p->next;
            free(temp);
        } else
        {
            prev = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->next = NULL;
    List_TailInsert(L, 1);
    List_TailInsert(L, 2);
    List_TailInsert(L, 2);
    List_TailInsert(L, 3);
    List_TailInsert(L, 2);
    List_TailInsert(L, 5);

    Delete_X(L, 2);
    PrintLNode(L->next);

    return 0;
}