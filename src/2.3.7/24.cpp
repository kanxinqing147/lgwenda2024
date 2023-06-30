#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void func(LinkList &l, int n)
{
    bool appear[n+1] = {false};

    LNode *p = l;
    while (p->next != NULL)
    {
        int index = abs(p->next->data);
        if (!appear[index])
        {
            appear[index] = true;
            p = p->next;
        }
        else
        {
            LNode *temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
    }
}

int main(int argc, char const *argv[])
{
    LinkList l = (LNode *)malloc(sizeof(LNode));

    l->next = NULL;
    List_TailInsert(l, 21);
    List_TailInsert(l, -15);
    List_TailInsert(l, -15);
    List_TailInsert(l, -7);
    List_TailInsert(l, 15);

    func(l, 21);

    PrintLNode(l);

    return 0;
}
