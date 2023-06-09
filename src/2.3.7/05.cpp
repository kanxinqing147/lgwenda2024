#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void ReserveLNodeImpl(LinkList &L)
{
    if (L->next == NULL)
    {
        return;
    }
    
    ReserveLNodeImpl(L->next);
    L->next->next = L;
}

void ReserveLNode(LinkList &L)
{
    LinkList tail;
    for (tail = L->next; tail->next != NULL; tail = tail->next)
        ;

    ReserveLNodeImpl(L->next);
    L->next->next = NULL;
    L->next = tail;
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->next = NULL;
    List_TailInsert(L, 1);
    List_TailInsert(L, 2);
    List_TailInsert(L, 3);
    List_TailInsert(L, 4);
    List_TailInsert(L, 5);

    ReserveLNode(L);
    PrintLNode(L->next);

    return 0;
}