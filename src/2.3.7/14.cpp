#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LinkList Get_Common(LinkList &A, LinkList &B)
{
    LinkList C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    LinkList i3 = C;

    for (LinkList i1 = A->next; i1 != NULL; i1 = i1->next)
    {
        for (LinkList i2 = B->next; i2 != NULL; i2 = i2->next)
        {
            if (i1->data == i2->data)
            {
                LinkList temp = (LNode *)malloc(sizeof(LNode));
                temp->data = i1->data;
                temp->next = NULL;

                i3->next = temp;
                i3 = i3->next;
            }
            
        }
    }
    
    return C;
}

int main()
{
    LinkList A = (LNode *)malloc(sizeof(LNode));
    LinkList B = (LNode *)malloc(sizeof(LNode));

    A->next = NULL;
    List_TailInsert(A, 1);
    List_TailInsert(A, 2);
    List_TailInsert(A, 3);
    List_TailInsert(A, 4);
    List_TailInsert(A, 5);
    List_TailInsert(A, 6);

    B->next = NULL;
    List_TailInsert(B, 2);
    List_TailInsert(B, 4);
    List_TailInsert(B, 6);

    LinkList C = Get_Common(A, B);
    PrintLNode(C);
    

    return 0;
}