#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *pre, *next;
    int freq;
}DNode, *DLinklist;


DNode *TailInsert(DLinklist &L, int x)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = x;
    newNode->freq = 0;

    DNode *tail;
    for (tail = L; tail->next != NULL; tail = tail->next)
        ;

    newNode->pre = tail;
    tail->next = newNode;
    newNode->next = NULL;

    return newNode;
}

void PrintDNode(DLinklist L)
{
    for (DNode *i = L; i->next != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

DNode *Locate(DLinklist &L, int x)
{
    if (L->next == NULL)
        return NULL;

    if (L->next->next == NULL)
    {
        if (L->next->data != x)
        {
            return NULL;
        }
        else
        {
            L->next->freq++;
            return L->next;
        }
    }

    DNode *aim;
    for (aim = L->next; aim->next != NULL && aim->data != x; aim = aim->next)
        ;
    if (aim->data != x)
        return NULL;
    aim->freq++;

    aim->pre->next = aim->next;
    if (aim->next != NULL)
        aim->next->pre = aim->pre;

    DNode *pre_aim;
    for (pre_aim = L->next; pre_aim->next != NULL && pre_aim->freq > aim->freq; pre_aim = pre_aim->next)
        ;
    pre_aim = pre_aim->pre;
    
    aim->pre = pre_aim;
    aim->next = pre_aim->next;
    if (pre_aim->next != NULL)
        pre_aim->next->pre = aim;
    pre_aim->next = aim;

    return aim;
}

int main()
{
    DLinklist L = (DNode *)malloc(sizeof(DNode));
    L->pre = L->next = NULL;

    TailInsert(L, 1);
    TailInsert(L, 2);
    TailInsert(L, 3);
    TailInsert(L, 4);
    TailInsert(L, 5);

    Locate(L, 1);
    Locate(L, 1);
    Locate(L, 5);
    Locate(L, 5);

    PrintDNode(L);

    return 0;
}