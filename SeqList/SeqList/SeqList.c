﻿#define _CRT_SECURE_NO_WARNINGS 1
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
	while (end > 0)
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
	assert(ps->size > 0);

	int begin = 0;
	while (begin < ps->size-1)//此处应该是size-1，否则有越界问题
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}

	/*for (int begin = 0; begin < ps->size - 1; begin++)
	{
		ps->a[begin] = ps->a[begin + 1];
	}*/

	//当size=1；不进入循环体直接size--，也满足删除的要求

	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	//pos为要插入位置的下标+1，方便传参
	assert(pos > 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	int end = ps->size;//最后一个元素的下标+1
	while (end >= pos)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}

	ps->a[pos - 1] = x;
	ps->size++;
}