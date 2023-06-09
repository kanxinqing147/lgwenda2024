#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Del_Same(LinkList &L)
{
    LinkList prev = L;
    LinkList p = L->next;

    while (p != NULL)
    {
        if (prev->data == p->data)
        {
            LinkList temp = p;
            prev->next = p->next;
            p = p->next;
            free(temp);
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->data = 7;
    L->next = NULL;
    List_TailInsert(L, 10);
    List_TailInsert(L, 10);
    List_TailInsert(L, 21);
    List_TailInsert(L, 30);
    List_TailInsert(L, 42);
    List_TailInsert(L, 42);
    List_TailInsert(L, 42);
    List_TailInsert(L, 51);
    List_TailInsert(L, 70);

    Del_Same(L);
    PrintLNode(L);

    return 0;
}