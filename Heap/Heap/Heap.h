﻿#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
//用顺序表（数组）实现堆
typedef int HPDataType;

typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapInitArray(HP* php, int* a, int n);
void HeapDestroy(HP* php);

bool HeapEmpty(HP* php);
void HeapPush(HP* php,HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);

void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);

void my_swap(HPDataType* p1, HPDataType* p2);