#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int SLTDataType;

typedef struct SLTNode
{
	SLTDataType data;
	struct SLTNode* next;
}SLTNode;

//打印函数
void SLTPrint(SLTNode* phead);

//尾插函数
void SLTPushBack(SLTNode** pphead, SLTDataType x);//改变SLTNode*，使用指针SLTNode**

//头插函数
void SLTPushFront(SLTNode** pphead, SLTDataType x);
