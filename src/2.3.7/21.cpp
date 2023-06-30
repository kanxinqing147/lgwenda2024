#include "LNode.h"
#include <stdio.h>
#include <stdlib.h>

LNode *FindLoopStart(LinkList head)
{
    LNode *fast = head, *low = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        low = low->next;
        if (fast == low)
        {
            LNode *p = head;
            while (p != low)
            {
                p = p->next;
                low = low->next;
            }
            return p;
        }
    }

    return NULL;
}

int main()
{
    LNode *temp1 = NULL, *temp2 = NULL;

    LinkList l1 = (LNode *)malloc(sizeof(LNode));
    LinkList l2 = (LNode *)malloc(sizeof(LNode));
    l1->next = NULL;
    l2->next = NULL; 

    List_TailInsert(l1, 1);
    List_TailInsert(l1, 2);
    temp1 = List_TailInsert(l1, 3);
    List_TailInsert(l1, 4);
    temp2 = List_TailInsert(l1, 5);
    
    temp2->next = temp1;
    printf("%p\n", FindLoopStart(l1));

    List_TailInsert(l2, 1);
    List_TailInsert(l2, 2);
    List_TailInsert(l2, 3);
    List_TailInsert(l2, 4);
    List_TailInsert(l2, 5);

    printf("%p\n", FindLoopStart(l2));

    return 0;
}