#include <stdio.h>
#include "SqList.h"

void ReverseRange(SqList &L, int start, int end)
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

void ExchangePos(SqList &L, int m, int n)
{
    ReverseRange(L, 0, m - 1);
    ReverseRange(L, m, L.length - 1);

    for (int i = 0; i < n; i++)
    {
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

int main()
{
    SqList L;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 11;
    L.data[5] = 12;
    L.data[6] = 13;
    L.length = 7;

    ExchangePos(L, 4, 3);
    PrintList(L);

    return 0;
}