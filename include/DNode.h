#ifndef _DNODE_H_
#define _DNODE_H_

#define DNodeElemType int

typedef struct DNode
{
    DNodeElemType data;
    struct DNode *pre, *next;
}DNode, *DLinklist;

extern DLinklist DList_TailInsert(DLinklist &L, DNodeElemType x);



#endif