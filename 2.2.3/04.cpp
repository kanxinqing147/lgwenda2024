#include <stdio.h>
#include "SqList.h"

bool DeleteRange(SqList &L, int s, int t)
{
    if (L.length <= 0 ||
        s > t ||
        s > L.length ||
        t > L.length)
    {
        return false;
    }

    for (int i = s - 1; i + t - s + 1 < L.length; i++)
    {
        L.data[i] = L.data[i + t - s + 1];
    }

    L.length -= t - s + 1;

    return true;
}

int main()
{
    SqList L;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.data[5] = 6;
    L.length = 6;

    DeleteRange(L, 3, 4);
    PrintList(L);

    return 0;
}