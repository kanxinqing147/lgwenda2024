#ifndef _LNODE_H_
#define _LNODE_H_

#define ElemType char

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

extern LinkList List_HeadInsert(LinkList &L, ElemType x);
extern LinkList List_TailInsert(LinkList &L, ElemType x);
extern void PrintLNode(LinkList L);

#endif