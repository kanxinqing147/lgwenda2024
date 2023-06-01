#include <stdio.h>
#include "SqList.h"

SqList MergeSqList(SqList L1, SqList L2)
{
    int i1 = 0, i2 = 0;
    SqList L;
    while (i1 < L1.length && i2 < L2.length)
    {
        if (L1.data[i1] < L2.data[i2])
        {
            L.data[L.length] = L1.data[i1];
            i1++;
        } else {
            L.data[L.length] = L2.data[i2];
            i2++;
        }
        L.length++;
    }

    for (; i1 < L1.length; i1++)
    {
        L.data[L.length] = L1.data[i1];
        L.length++;
    }
    for (; i2 < L2.length; i2++)
    {
        L.data[L.length] = L2.data[i2];
        L.length++;
    }
    
    return L;
}

int main()
{
    SqList L1;

    L1.data[0] = 1;
    L1.data[1] = 3;
    L1.data[2] = 5;
    L1.data[3] = 7;
    L1.length = 4;

    SqList L2;

    L2.data[0] = 2;
    L2.data[1] = 4;
    L2.data[2] = 6;
    L2.data[3] = 8;
    L2.length = 4;

    SqList L = MergeSqList(L1, L2);

    PrintList(L);

    return 0;
}