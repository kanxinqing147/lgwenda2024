#include <stdio.h>
#include "SqList.h"

int SearchList(SqList L, ElemType x)
{
    int left = 0, right = L.length - 1;

    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (L.data[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

void ExchangeInsert(SqList &L, int x)
{
    int i = SearchList(L, x);

    if (L.data[i] == x && i != L.length - 1)
    {
        ElemType temp = L.data[i];
        L.data[i] = L.data[i + 1];
        L.data[i + 1] = temp;
        return;
    }

    if (L.data[i] != x)
    {
        for (int j = L.length - 1; j >= i; j--)
        {
            L.data[j + 1] = L.data[j];
        }
        L.data[i] = x;
        L.length++;
    }
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

    ExchangeInsert(L, 2);    
    PrintList(L);

    return 0;
}