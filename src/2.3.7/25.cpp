#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void change_list(LinkList &l)
{
    LNode *middle = l;

    LNode *end = l;
    while (end->next != NULL)
    {
        middle = middle->next;
        end = end->next;
        if (end->next != NULL)
        {
            end = end->next;
        }
    }

    LNode *back_head = middle->next;
    middle->next = NULL;
    LNode *temp;
    while (back_head != NULL)
    {
        temp = middle->next;
        back_head->next = middle->next;
        middle->next = back_head;
        back_head = temp;
    }

    LNode *front_head = l->next;
    back_head = middle->next;
    middle->next = NULL;
    while (back_head != NULL)
    {
        temp = back_head->next;
        back_head->next = front_head->next;
        front_head->next = back_head;
        front_head = back_head->next;
        back_head = temp;
    }
}

int main(int argc, char const *argv[])
{
    LinkList l = (LNode *)malloc(sizeof(LNode));

    l->next = NULL;
    List_TailInsert(l, 1);
    List_TailInsert(l, 2);
    List_TailInsert(l, 3);
    List_TailInsert(l, 4);
    List_TailInsert(l, 5);
    List_TailInsert(l, 6);
    List_TailInsert(l, 7);

    change_list(l);

    PrintLNode(l);

    return 0;
}
