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
	SL ps;
	SLInit(&ps);

	SLPushFront(&ps, 1);
	SLPushFront(&ps, 2);
	SLPushFront(&ps, 3);
	SLPushFront(&ps, 4);
	SLPrint(&ps);

	SLPushFront(&ps, 5);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

	SLPopFront(&ps);
	SLPrint(&ps);

}

int main()
{
	TestSL2();
	return 0;
}