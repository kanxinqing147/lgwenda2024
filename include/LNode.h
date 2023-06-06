#ifndef _LNODE_H_
#define _LNODE_H_

#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

extern LinkList List_TailInsert(LinkList &L, ElemType x);
extern void PrintLNode(LinkList L);

#endif