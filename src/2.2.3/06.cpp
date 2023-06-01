#include <stdio.h>
#include "SqList.h"

bool DeleteSame(SqList &L)
{
    if (L.length == 0)
    {
        return false;
    }
    

    int low = 0, fast = 1;
    while (fast < L.length)
    {
        if (L.data[low] != L.data[fast])
        {
            L.data[++low] = L.data[fast];
        }
        fast++;
    }
    L.length = low + 1;

    return true;
}

int main()
{
    SqList L;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 3;
    L.data[4] = 3;
    L.data[5] = 4;
    L.data[6] = 5;
    L.length = 7;

    DeleteSame(L);
    PrintList(L);

    return 0;
}