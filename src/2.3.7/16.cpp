#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

bool Pattern(LinkList &A, LinkList &B)
{
    LinkList i1 = A, i2 = B;
    LinkList pre = A;

    while (i1 != NULL && i2 != NULL)
    {
        if (i1->data == i2->data)
        {
            i1 = i1->next;
            i2 = i2->next;
        }
        else
        {
            pre = pre->next;
            i1 = pre;
            i2 = B;
        }
    }
    

    return i2 == NULL;
}

int main()
{
    LinkList A = (LNode *)malloc(sizeof(LNode));
    LinkList B = (LNode *)malloc(sizeof(LNode));

    A->data = 1;
    A->next = NULL;
    List_TailInsert(A, 2);
    List_TailInsert(A, 3);
    List_TailInsert(A, 4);
    List_TailInsert(A, 5);
    List_TailInsert(A, 6);

    B->data = 3;
    B->next = NULL;
    List_TailInsert(B, 4);
    List_TailInsert(B, 5);

    printf("%d\n", Pattern(A, B));


    return 0;
}