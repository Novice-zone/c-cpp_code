#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int SLTDataType;

typedef struct SLTNode
{
	SLTDataType data;
	struct SLTNode* next;
}SLTNode;

//打印函数
void SLTPrint(SLTNode* phead);

//尾插函数
void SLTPushBack(SLTNode* phead, SLTDataType x);
