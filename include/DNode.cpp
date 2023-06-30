#include "DNode.h"
#include <stdio.h>
#include <stdlib.h>

DLinklist DList_TailInsert(DLinklist &L, DNodeElemType x)
{
    DLinklist newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = x;

    DLinklist tail;
    for (tail = L; tail->next != NULL; tail = tail->next)
        ;
    
    tail->next = newNode;
    newNode->pre = tail;
    newNode->next = NULL;

    return newNode;
}