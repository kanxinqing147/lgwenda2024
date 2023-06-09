#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void ReservePrintLNode(LinkList &L)
{
    if (L == NULL)
    {
        return;
    }
    
    ReservePrintLNode(L->next);
    printf("%d ", L->data);
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

    ReservePrintLNode(L->next);

    return 0;
}