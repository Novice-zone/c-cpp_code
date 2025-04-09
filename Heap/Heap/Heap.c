#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php) {
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL) {
		perror("malloc:php->a");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}

void HeapInitArray(HP* php, int* a, int n) {
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL) {
		perror("malloc:php->a");
		return;
	}
	php->size = n;
	php->capacity = n;

	//建堆，向下调整建堆 --O（N）
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(php->a,php->size,i);
	}
}

void HeapDestroy(HP* php) {
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
void my_swap(HPDataType* p1, HPDataType* p2) {
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//要求左右子树都是大堆/小堆
//向上迭代，物理上是对数组进行操作，因此传参必须要有数组。要通过child确定插入元素的下标和父节点的下标，因此要传入child (size-1)
void AdjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] > a[parent]) {
			//交换元素
			my_swap(&a[child], &a[parent]);
			//迭代变量
			child = parent;
			parent = (child - 1) / 2;
		}
		else {//child的值小于parent，结束迭代
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity) {
		HPDataType* temp = (HPDataType*)realloc(php->a,sizeof(HPDataType) * (php->capacity) * 2);//满了就扩容二倍
		if (temp == NULL) {
			perror("realloc:temp");
			return;
		}
		php->a = temp;
		php->capacity *= 2;//记得更新capacity
	}

	//size是有效元素个数，也是最后一个元素下标的后一个下标
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);//迭代函数一次性迭代完
}

//要求左右子树都是大堆/小堆
//传入数组，数组大小，迭代位置parent
//void AdjustDown(HPDataType* a, int n,int parent) {
//	//同样的。对数组进行操作，传入数组。要得到数组大小来判断循环是否终止，传入数组大小n。
//	//要从parent位置开始迭代，传入parent
//	int child = (parent * 2) + 1;
//	
//	while (child < n) {
//		//保证child是大孩子,放入循环体保证每次都能更新child
//		//if (a[child] < a[child + 1]) 
//		if (child + 1 < n && a[child + 1] > a[child]) {
//			child++;
//		}
//		
//		if (a[parent] < a[child]) {
//			//交换元素
//			my_swap(&a[parent], &a[child]);
//			//迭代变量
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else {//parent>child就退出循环
//			break;
//		}
//	}
//}
//TopK问题需要建小堆
void AdjustDown(HPDataType* a, int n, int parent) {
	//同样的。对数组进行操作，传入数组。要得到数组大小来判断循环是否终止，传入数组大小n。
	//要从parent位置开始迭代，传入parent
	int child = (parent * 2) + 1;

	while (child < n) {
		//保证child是大孩子,放入循环体保证每次都能更新child
		//if (a[child] < a[child + 1]) 
		if (child + 1 < n && a[child + 1] < a[child]) {
			child++;
		}

		if (a[parent] > a[child]) {
			//交换元素
			my_swap(&a[parent], &a[child]);
			//迭代变量
			parent = child;
			child = parent * 2 + 1;
		}
		else {//parent>child就退出循环
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	//交换堆顶和堆尾元素
	my_swap(&php->a[0], &php->a[php->size - 1]);
	//删除堆尾（刚刚的堆顶）
	php->size--;

	//更新存储顺序为大堆
	AdjustDown(php->a, php->size, 0);//传入0是因为是把堆尾堆顶进行交换
}

HPDataType HeapTop(HP* php) {
	assert(php);
	return php->a[0];
}

bool HeapEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}

int HeapSize(HP* php) {
	assert(php);
	return php->size;
}
