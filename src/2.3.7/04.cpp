#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Delete_Min(LinkList &L)
{
    LinkList PrevMinPoint = L;

    for (LinkList p = L; p->next != NULL; p = p->next)
    {
        if (p->next->data < PrevMinPoint->next->data)
        {
            PrevMinPoint = p;
        }
    }
    
    LinkList temp = PrevMinPoint->next;
    PrevMinPoint->next = PrevMinPoint->next->next;
    free(temp);
}

int main()
{
    LinkList L = (LNode *)malloc(sizeof(LNode));

    L->next = NULL;
    List_TailInsert(L, 3);
    List_TailInsert(L, 4);
    List_TailInsert(L, 2);
    List_TailInsert(L, 1);
    List_TailInsert(L, 7);

    Delete_Min(L);
    PrintLNode(L->next);

    return 0;
}