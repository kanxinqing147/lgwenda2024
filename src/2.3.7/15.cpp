#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LinkList Union_LNode(LinkList &A, LinkList &B)
{
    LinkList i1 = A->next, i2 = B->next;
    LinkList p = A;

    while (i1 != NULL && i2 != NULL)
    {
        if (i1->data == i2->data)
        {
            p->next = i1;
            p = i1;
            i1 = i1->next;

            LinkList temp = i2;
            i2 = i2->next;
            free(temp);
        }
        else if (i1->data < i2->data)
        {
            LinkList temp = i1;
            i1 = i1->next;
            free(temp);
        }
        else
        {
            LinkList temp = i2;
            i2 = i2->next;
            free(temp);
        }
    }

    while (i1 != NULL)
    {
        LinkList temp = i1;
        i1 = i1->next;
        free(temp);
    }
    while (i2 != NULL)
    {
        LinkList temp = i2;
        i2 = i2->next;
        free(temp);
    }

    p->next = NULL;
    free(B);
    return A;
}

int main()
{
    LinkList A = (LNode *)malloc(sizeof(LNode));
    LinkList B = (LNode *)malloc(sizeof(LNode));

    A->next = NULL;
    List_TailInsert(A, 2);
    List_TailInsert(A, 4);
    List_TailInsert(A, 5);
    List_TailInsert(A, 8);
    List_TailInsert(A, 10);

    B->next = NULL;
    List_TailInsert(B, 1);
    List_TailInsert(B, 2);
    List_TailInsert(B, 3);
    List_TailInsert(B, 4);
    List_TailInsert(B, 5);

    LinkList C = Union_LNode(A, B);
    PrintLNode(C);

    return 0;
}