#include <stdio.h>
#include <stdlib.h>
#include "CirLNode.h"

CirLinkList Link(CirLinkList &h1, CirLinkList &h2)
{
    CirLinkList h1_tail, h2_tail;
    for (h1_tail = h1; h1_tail->next != h1; h1_tail = h1_tail->next)
        ;
    for (h2_tail = h2; h2_tail->next != h2; h2_tail = h2_tail->next)
        ;
    
    h1_tail->next = h2;
    h2_tail->next = h1;

    return h1;
}

int main()
{
    CirLinkList h1 = (CirLNode *)malloc(sizeof(CirLNode));
    h1->data = 1;
    h1->next = h1;
    CirList_TailInsert(h1, 2);
    CirList_TailInsert(h1, 3);
    CirList_TailInsert(h1, 4);

    CirLinkList h2 = (CirLNode *)malloc(sizeof(CirLNode));
    h2->data = 5;
    h2->next = h2;
    CirList_TailInsert(h2, 6);
    CirList_TailInsert(h2, 7);

    Link(h1, h2);
    PrintCirLNode(h1);

    return 0;
}
