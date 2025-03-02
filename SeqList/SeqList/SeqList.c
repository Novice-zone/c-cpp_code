#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
	
}

void SLPrint(SL* ps)
{
	assert(ps);
	if (ps == 0) 
	{
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLDestroy(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("ralloc:tmp");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}


void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//检查是否需要扩容
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	//检查，防止数组越界
	/*if (ps->size == 0)
	{
		return;
	}*/
	//暴力检查
	assert(ps->size > 0);//要用记得头文件

	ps->size--;//没必要清空ps->s[ps->size]的元素
}


void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	int end = ps->size;
	while (end >= 0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	int begin = 0;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}