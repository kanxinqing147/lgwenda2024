#include <stdio.h>
#include <stdlib.h>
#include "CirLNode.h"

void Del_All(CirLinkList &L)
{
    while (L->next != L)
    {
        CirLNode *pre_min = L, *min = L->next;
        for (CirLNode *i = L; i->next->next != L; i = i->next)
        {
            if (i->next->data < min->data)
            {
                pre_min = i;
                min = i->next;
            }
        }
        printf("%d ", min->data);
        pre_min->next = min->next;
        free(min);
    }
    
    printf("\n");
    free(L);
}

int main()
{
    CirLinkList L = (CirLNode *)malloc(sizeof(CirLNode));

    L->next = L;
    CirList_TailInsert(L, 4);
    CirList_TailInsert(L, 7);
    CirList_TailInsert(L, 1);
    CirList_TailInsert(L, 9);
    CirList_TailInsert(L, 5);
    CirList_TailInsert(L, 2);
    CirList_TailInsert(L, 3);
    CirList_TailInsert(L, 6);
    CirList_TailInsert(L, 8);

    Del_All(L);

    return 0;
}