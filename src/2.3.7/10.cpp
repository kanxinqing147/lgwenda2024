#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LinkList DisCreate_1(LinkList &A)
{
    LinkList B = (LNode *)malloc(sizeof(LNode));
    B->next = NULL;

    int i = 0;
    LinkList iA = A, iB = B;
    LinkList p = A->next;
    A->next = NULL;
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            iB->next = p;
            iB = p;
        }
        else
        {
            iA->next = p;
            iA = p;
        }
        p = p->next;
    }
    
    return B;
}

int main()
{
    LinkList A = (LNode *)malloc(sizeof(LNode));

    A->next = NULL;
    List_TailInsert(A, 1);
    List_TailInsert(A, 2);
    List_TailInsert(A, 3);
    List_TailInsert(A, 4);
    List_TailInsert(A, 5);
    List_TailInsert(A, 6);

    LinkList B = DisCreate_1(A);
    PrintLNode(A);
    PrintLNode(B);

    return 0;
}