#include "LNode.h"

LinkList List_TailInsert(LinkList &L, ElemType x)
{
    LinkList newNode = (LNode *)malloc(sizeof(LNode));

    newNode->data = x;
    newNode->next = NULL;
    
    LinkList tail;
    for (tail = L; tail->next != NULL; tail = tail->next)
        ;
    tail->next = newNode;
    
    return L;
}

void PrintLNode(LinkList L)
{
    for (LinkList temp = L; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}
