#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void STInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc");
		return;
	}

	//top为栈顶的下一个位置
	ps->top = 0;

	ps->capacity = 4;
}

void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void STPush(ST* ps,STDataType x)
{
	assert(ps);
	//判断是否需要扩容
	if (ps->top == ps->capacity)
	{
		STDataType* temp = (STDataType*)realloc(ps->a,sizeof(STDataType) * ps->capacity * 2);
		if (temp == NULL)
		{
			perror("realloc");
			return;
		}
		ps->a = temp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;//top为0表示栈空
}
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}