#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"


//排升序，建大堆
void HeapSort(int* a, int n) {
	/*//建堆，向上调整建堆
	for (int i = 1; i < n; i++) {
		AdjustUp(a, i);
	}*/

	//建堆，向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	//排序，向下调整排序
	int end = n - 1;
	while (end > 0) {
		my_swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);

		end--;
	}
}


int main()
{
	/*HP hp;
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
	printf("\n");*/
	
	//堆排序
	int a[10] = { 2,1,5,7,6,8,0,9,4,3 };
	HeapSort(a, 10);

	

	return 0;
}
