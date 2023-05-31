#include <stdio.h>
#include "./include/SqList.h"

int main()
{
	SqList L;

	ListInsert(L, 1, 60);

	printf("%d\n", L.data[0]);

	return 0;
}
