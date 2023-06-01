#include <stdio.h>
#include "SqList.h"

bool Delete_s_t(SqList &L, ElemType s, ElemType t)
{
    if (s > t || L.length <= 0)
    {
        return false;
    }
    
    int fast = 0, low = 0;
    while (fast < L.length)
    {
        if (L.data[fast] < s || L.data[fast] > t)
        {
            L.data[low] = L.data[fast];
            low++;
        }
        fast++;
    }
    L.length = low;
    
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
    L.data[5] = 3;
    L.data[6] = 4;
    L.length = 7;

    Delete_s_t(L, 3, 4);
    PrintList(L);

    return 0;    
}