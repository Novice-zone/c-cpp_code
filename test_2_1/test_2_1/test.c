#define _CRT_SECURE_NO_WARNINGS 1
//简单复现malloc,calloc,realloc

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

//malloc
//void *malloc(size_t size);
//动态开辟一块内存空间（堆区），返回指向空间的起始地址的指针
//int main()
//{
//	//申请十个整型所需要的空间,不会初始化
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)//申请失败
//	{
//		printf("%s\n", strerror(errno));//打印错误原因
//		return 1;
//	}
//	//使用该连续空间,类似于数组
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);//释放申请的内存
//	p = NULL;//避免野指针非法访问
//	return 0;
//}

//calloc
//void* calloc(size_t num, size_t size);
//为num个大小为size的元素在堆区开辟空间，并初始化为0
//返回指向空间的起始地址的指针
//int main()
//{
//	//申请十个整型大小的空间
//	int* p=(int*)calloc(10, 4);
//	
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	////打印
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(p + i));//全为0
//	//}
//	
//	//使用
//	int i = 0;
//	for (i = 0; i < 10;i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc
//void* realloc (void* ptr, size_t size);
//调整已申请的动态内存空间的大小,ptr是要改变的内存地址，size是改变后的大小

int main()
{
	//申请五个整型空间
	int* p=(int*)malloc(5 * sizeof(int));
	
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}

	//使用
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*(p + i) = 1;
	}

	for (i = 0; i < 5;i++)
	{
		printf("%d ", *(p + i));
	}

	//变成10个整型空间（增加5个整型空间）
	int* ptr = (int*)realloc(p, 10 * sizeof(int));
	//如果失败则会返回空指针
	//如果成功，存在两种情况
	//1.返回原地址
	//2.返回新地址
	if (ptr != NULL)
	{
		p = ptr;
		ptr = NULL;
	}
	//使用空间
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	
	free(p);
	p = NULL;
	return 0;
}