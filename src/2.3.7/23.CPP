#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

LNode *find_addr(LinkList str1, LinkList str2)
{
    int str1_len = 0, str2_len = 0;

    for (LNode *p = str1->next; p != NULL; p = p->next)
        str1_len++;
    for (LNode *p = str2->next; p != NULL; p = p->next)
        str2_len++;

    LNode *p = NULL, *q = NULL;
    int gap = 0;
    if (str1_len > str2_len)
    {
        p = str1->next;
        q = str2->next;
        gap = str1_len - str2_len;
    }
    else
    {
        p = str2->next;
        q = str1->next;
        gap = str2_len - str1_len;
    }
    
    for (int i = 0; i < gap; i++)
    {
        p = p->next;
    }
    

    while (p != NULL && q != NULL && p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p;
}

int main()
{
    LinkList l1 = (LNode *)malloc(sizeof(LNode));
    LinkList l2 = (LNode *)malloc(sizeof(LNode));
    l1->next = NULL;
    l2->next = NULL;

    List_TailInsert(l1, 'l');
    List_TailInsert(l1, 'o');
    List_TailInsert(l1, 'a');
    List_TailInsert(l1, 'd');
    LNode *temp1 = List_TailInsert(l1, 'i');
    List_TailInsert(l1, 'n');
    List_TailInsert(l1, 'g');

    List_TailInsert(l2, 'b');
    LNode *temp2 = List_TailInsert(l2, 'e');
    temp2->next = temp1;

    temp1 = find_addr(l1, l2);
    printf("%c\n", temp1->data);

    return 0;
}