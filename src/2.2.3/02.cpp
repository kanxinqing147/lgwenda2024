#include <stdio.h>
#include "SqList.h"

void Reverse(SqList &L)
{
	int left = 0;
	int right = L.length - 1;

	while (left < right)
	{
		ElemType temp = L.data[left];
		L.data[left] = L.data[right];
		L.data[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	SqList L;

	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.data[3] = 4;
	L.length = 4;

	Reverse(L);
	PrintList(L);

	return 0;
}
