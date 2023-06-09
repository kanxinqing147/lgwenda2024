#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void MergeList(LinkList &L1, LinkList &L2)
{
    LinkList i1 = L1, i2 = L2;

    while (i1 != NULL && i2 != NULL)
    {
        if (i1->data < i2->data)
        {
            LinkList temp = i2;
            i2 = i2->next;
            temp->next = i1->next;
            i1->next = temp;
            i1 = i1->next;
        }
        else
        {
            
        }
    } 
}

int main()
{
    

    return 0;
}