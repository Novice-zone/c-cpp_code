#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSL()
{
	//初始化
	SL ps;
	SLInit(&ps);//传地址，修改实参的数据

	SLPushBack(&ps, 1);
	SLPushBack(&ps, 2);
	SLPushBack(&ps, 3);
	SLPushBack(&ps, 4);
	SLPrint(&ps);

	SLPushBack(&ps, 5);
	SLPushBack(&ps, 6);
	SLPushBack(&ps, 7);
	SLPushBack(&ps, 8);
	SLPrint(&ps);

	SLPopBack(&ps);
	SLPrint(&ps);


	//销毁malloc申请的空间
	SLDestroy(&ps);
}

int main()
{
	TestSL();
	return 0;
}