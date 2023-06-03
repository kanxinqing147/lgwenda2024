#include <stdio.h>
#include <math.h>
#include "SqList.h"

SqList findMinOfTrip(const SqList L1, const SqList L2, const SqList L3)
{
    SqList L;
    L.length = 3;
    int minTrip = INT_MAX;
    
    for (int i1 = 0; i1 < L1.length; i1++)
    {
        for (int i2 = 0; i2 < L2.length; i2++)
        {
            for (int i3 = 0; i3 < L3.length; i3++)
            {
                int newTrip = abs(L1.data[i1] - L2.data[i2]) + abs(L2.data[i2] - L3.data[i3]) + abs(L3.data[i3] - L1.data[i1]);
                if (newTrip < minTrip)
                {
                    minTrip = newTrip;
                    L.data[0] = L1.data[i1];
                    L.data[1] = L2.data[i2];
                    L.data[2] = L3.data[i3];
                }
            }
        }
    }

    return L;
}

int main()
{
    SqList L1, L2, L3;

    L1.data[0] = -1;
    L1.data[1] = 0;
    L1.data[2] = 9;
    L1.length = 3;

    L2.data[0] = -25;
    L2.data[1] = -10;
    L2.data[2] = 10;
    L2.data[3] = 11;
    L2.length = 4;

    L3.data[0] = 2;
    L3.data[1] = 9;
    L3.data[2] = 17;
    L3.data[3] = 30;
    L3.data[4] = 41;
    L3.length = 5;

    SqList L = findMinOfTrip(L1, L2, L3);
    PrintList(L);

    return 0;
}