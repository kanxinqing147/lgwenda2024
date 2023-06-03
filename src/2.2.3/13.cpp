#include <stdio.h>
#include "SqList.h"

int GetMinNum(SqList L)
{
    bool *statue = new bool[L.length];

    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] > 0)
        {
            statue[L.data[i] - 1] = true;
        }
    }
    
    for (int i = 0; i < L.length; i++)
    {
        if (!statue[i])
        {
            return i + 1;
        }
    }
    
    return L.length + 1;
}

int main()
{
    SqList L1, L2;

    L1.data[0] = -5;
    L1.data[1] = 3;
    L1.data[2] = 2;
    L1.data[3] = 3;
    L1.length = 4;

    L2.data[0] = 1;
    L2.data[1] = 2;
    L2.data[2] = 3;
    L2.length = 3;

    printf("%d\n", GetMinNum(L1));
    printf("%d\n", GetMinNum(L2));

    return 0;
}