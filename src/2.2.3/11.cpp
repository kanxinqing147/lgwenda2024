#include <stdio.h>
#include "SqList.h"

SqList Mergelist(SqList &L1, SqList &L2)
{
    SqList L;
    L.length = 0;

    int i1 = 0, i2 = 0;

    while (i1 < L1.length && i2 < L2.length)
    {
        if (L1.data[i1] < L2.data[i2])
        {
            L.data[L.length] = L1.data[i1];
            L.length++;
            i1++;
        }
        else
        {
            L.data[L.length] = L2.data[i2];
            L.length++;
            i2++;
        }
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
    SqList L1, L2;

    L1.data[0] = 11;
    L1.data[1] = 13;
    L1.data[2] = 15;
    L1.data[3] = 17;
    L1.data[4] = 19;
    L1.length = 5;

    L2.data[0] = 2;
    L2.data[1] = 4;
    L2.data[2] = 6;
    L2.data[3] = 8;
    L2.data[4] = 20;
    L2.length = 5;

    SqList L = Mergelist(L1, L2);
    printf("%d\n", L.data[(L.length - 1) / 2]);

    return 0;
}