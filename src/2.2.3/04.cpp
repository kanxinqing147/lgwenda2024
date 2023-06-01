#include <stdio.h>
#include "SqList.h"

bool DeleteRange(SqList &L, int s, int t)
{
    if (L.length <= 0 || s > t)
    {
        return false;
    }

    int start, end;
    for (start = 0; start < L.length && L.data[start] < s; start++)
        ;
    if (start == L.length)
        return false;
    for (end = start; end < L.length && L.data[end] < t; end++)
        ;

    for (int i = start; i + end - start + 1 < L.length; i++)
    {
        L.data[i] = L.data[i + end - start + 1];
    }

    L.length -= end - start + 1;

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