#include <stdio.h>
#include "SqList.h"

void Reveser(SqList &L, int start, int end)
{
    while (start < end)
    {
        ElemType temp = L.data[start];
        L.data[start] = L.data[end];
        L.data[end] = temp;
        start++;
        end--;
    }
}

void Converse(SqList &L, int p)
{
    Reveser(L, 0, p - 1);
    Reveser(L, p, L.length - 1);
    Reveser(L, 0, L.length - 1);
}

int main()
{
    SqList L;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.length = 5;

    Converse(L, 2);
    PrintList(L);

    return 0;
}