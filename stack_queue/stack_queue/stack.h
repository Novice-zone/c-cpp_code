#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* ps);
void STDestroy(ST* ps);

void STPush(ST* ps,STDataType x);
void STPop(ST* ps);
bool STEmpty(ST* ps);
int STSize(ST* ps);
STDataType STTop(ST* ps);