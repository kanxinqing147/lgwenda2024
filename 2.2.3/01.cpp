#include <stdio.h>
#include "../include/SqList.h"

bool DeleteMin(SqList L, ElemType &e)
{
	if (L.length == 0)
	{
		return false;
	}

	int pos = 0;
	e = L.data[0];
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] < e)
		{
			pos = i;
			e = L.data[i];
		}
	}

	L.data[pos] = L.data[L.length - 1];
	L.length--;

	return true;
}

int main()
{
	SqList L;
	L.data[0] = 25;
	L.data[1] = 13;
	L.data[2] = 36;
	L.length = 3;

	int e;
	DeleteMin(L, e);
	printf("%d", e);

	return 0;
}
