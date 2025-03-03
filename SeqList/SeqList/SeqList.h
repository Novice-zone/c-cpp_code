#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 5 
typedef int SLDataType;
#define INIT_CAPACITY 4
//静态
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//动态
typedef struct SeqList
{
	SLDataType* a;
	int size;//当前存储个数
	int capacity;//顺序表容量
}SL;//SL=struct SeqList

//初始化函数
void SLInit(SL* ps);//传地址，以便在函数中修改源地址的值

//打印函数
void SLPrint(SL* ps);

//删除
void SLDestroy(SL* ps);

//扩容
void SLCheckCapacity(SL* ps);

//尾插法
void SLPushBack(SL* ps,SLDataType x);
//尾删法
void SLPopBack(SL* ps);

//头插法
void SLPushFront(SL* ps,SLDataType x);
//头删法
void SLPopFront(SL* ps);

//插入数据
void SLInsert(SL* ps, int pos, SLDataType x);

//删除数据
void SLErase(SL* ps, int pos);

//查找
int SLFind(SL* ps,SLDataType x);
