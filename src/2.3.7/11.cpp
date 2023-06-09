#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LinkList DisCreate_2(LinkList &C)
{
    LinkList B = NULL;

    int i = 0;
    LinkList iA = C, iB = B;
    LinkList p = C->next;
    C->next = NULL;
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            LinkList temp = p->next;
            p->next = iB;
            iB = p;
            p = temp;
        }
        else
        {
            iA->next = p;
            iA = p;
            p = p->next;
            iA->next = NULL;
        }
    }
    
    B = (LNode *)malloc(sizeof(LNode));
    B->next = iB;
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

    LinkList B = DisCreate_2(A);
    PrintLNode(A);
    PrintLNode(B);

    return 0;
}