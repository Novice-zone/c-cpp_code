#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL* ps)
{
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
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	//检查是否需要扩容
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp=realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("ralloc:tmp");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	ps->size--;//没必要清空ps->s[ps->size]的元素
}