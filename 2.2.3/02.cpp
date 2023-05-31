#include <stdio.h>
#include "../include/SqList.h"

void Reverse(SqList L)
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

}
