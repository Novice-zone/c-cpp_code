#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

//单链表:Single LisT Node
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

//尾删函数
void SLTPopBack(SLTNode** pphead);

//头删函数
void SLTPopFront(SLTNode** pphead);

//查找函数，返回地址
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//pos之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//pos之前删除
void SLTErase(SLTNode** phead, SLTNode* pos);

//pos之后插入
void SLTInsertAfter(SLTNode* pos,SLTDataType x);

//pos之后删除
void SLTEraseAfter(SLTNode* pos);

