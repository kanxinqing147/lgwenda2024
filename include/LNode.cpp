#include "LNode.h"
#include <stdio.h>
#include <stdlib.h>

LinkList List_HeadInsert(LinkList &L, ElemType x)
{
    LinkList newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = L;
    L = newNode;

    return newNode;
}

LinkList List_TailInsert(LinkList &L, ElemType x)
{
    LinkList newNode = (LNode *)malloc(sizeof(LNode));

    newNode->data = x;
    newNode->next = NULL;
    
    LinkList tail;
    for (tail = L; tail->next != NULL; tail = tail->next)
        ;
    tail->next = newNode;
    
    return newNode;
}

void PrintLNode(LinkList L)
{
    for (LinkList temp = L; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}
