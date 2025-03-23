#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int LTDataType;

//双向循环链表
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;

	LTDataType data;
}LTNode;

LTNode* LTInit();

void LTDestroy(LTNode* phead);

void LTPrint(LTNode* phead);

bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPopFront(LTNode* phead);

//通过值来找pos，找不到返回NULL
LTNode* LTFind(LTNode* phead , LTDataType x);

//在pos位置之前插入节点
void LTInsert(LTNode* pos, LTDataType x);

//删除pos位置的节点
void LTErase(LTNode* pos);