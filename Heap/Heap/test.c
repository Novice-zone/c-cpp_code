#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 18);
	HeapPush(&hp, 17);
	HeapPush(&hp, 19);
	HeapPush(&hp, 60);
	HeapPush(&hp, 40);
	HeapPush(&hp, 27);
	HeapPush(&hp, 2);
	HeapPush(&hp, 53);
	HeapPush(&hp, 29);

	int k = 0;
	scanf("%d", &k);
	while (!HeapEmpty(&hp) && k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	return 0;
}
