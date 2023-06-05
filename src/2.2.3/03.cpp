#include <stdio.h>
#include "SqList.h"

void DeleteX(SqList &L, ElemType x)
{
	int fast = 0, low = 0;
	while (fast < L.length)
	{
		if (L.data[fast] != x)
		{
			L.data[low] = L.data[fast];
			low++;
		}
		fast++;
	}
	L.length = low;
}

int main()
{
    SqList l;

	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.data[3] = 2;
	l.data[4] = 2;
	l.data[5] = 5;
	l.length = 6;

	DeleteX(l, 2);
	PrintList(l);

    return 0;
}
