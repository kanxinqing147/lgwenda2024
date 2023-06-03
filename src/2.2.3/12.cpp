#include <stdio.h>
#include "SqList.h"

ElemType GetPrimeNum(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        int count = 1;
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.data[i] == L.data[j])
            {
                count++;
            }
        }
        if (count > L.length / 2)
        {
            return L.data[i];
        }
    }
    

    return -1;
}

int main()
{
    SqList L1, L2;

    L1.data[0] = 0;
    L1.data[1] = 5;
    L1.data[2] = 5;
    L1.data[3] = 3;
    L1.data[4] = 5;
    L1.data[5] = 7;
    L1.data[6] = 5;
    L1.data[7] = 5;
    L1.length = 8;

    L2.data[0] = 0;
    L2.data[1] = 5;
    L2.data[2] = 5;
    L2.data[3] = 3;
    L2.data[4] = 5;
    L2.data[5] = 1;
    L2.data[6] = 5;
    L2.data[7] = 7;
    L2.length = 8;

    printf("%d\n", GetPrimeNum(L1));
    printf("%d\n", GetPrimeNum(L2));

    return 0;
}