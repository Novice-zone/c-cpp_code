#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSL1()
{
	//初始化
	SL s;
	SLInit(&s);//传地址，修改实参的数据

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	SLPushBack(&s, 8);
	SLPrint(&s);

	SLPopBack(&s);
	SLPrint(&s);


	//销毁malloc申请的空间
	SLDestroy(&s);
}

void TestSL2()
{
	SL s;
	SLInit(&s);

	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPrint(&s);

	SLPushFront(&s, 5);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	//SLPopFront(&s);
	//SLPrint(&s);

	SLDestroy(&s);
}

void TestSL3()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLInsert(&s, 2, 20);
	SLPrint(&s);

	SLInsert(&s, 1, 200);
	SLPrint(&s);

	/*SLErase(&s, 1);
	SLPrint(&s);
	SLErase(&s, 1);
	SLPrint(&s);
	SLErase(&s, 1);
	SLPrint(&s);
	SLErase(&s, 1);
	SLPrint(&s);
	SLErase(&s, 1);
	SLPrint(&s);*/
	/*SLErase(&s, 1);
	SLPrint(&s);*/
	/*SLErase(&s, 1);
	SLPrint(&s);*/
	int a=SLFind(&s, 4);
	printf("%d\n", a);//返回第一个符合条件元素的下标

	SLDestroy(&s);
}

int main()
{
	TestSL3();
	return 0;
}