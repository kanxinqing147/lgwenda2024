#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void DeleteRange(LinkList &L, ElemType a, ElemType b)
{
    LinkList low = L;
    LinkList fast = L->next;

    while (fast != NULL)
    {
        if (a <= fast->data && fast->data <= b)
        {
            LinkList temp = fast;
            low->next = fast->next;
            fast = fast->next;
            free(temp);
        }
        else
        {
            low = fast;
            fast = fast->next;
        }
    }
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

    DeleteRange(L, 2, 4);
    PrintLNode(L->next);

    return 0;
}