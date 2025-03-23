#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	LTPrint(plist);
}

void TestList2()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 4);
	LTPushFront(plist, 3);
	LTPushFront(plist, 2);
	LTPushFront(plist, 1);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPrint(plist);
}

void TestList3()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTNode* pos = LTFind(plist,3);
	if (pos != NULL)
	{
		LTErase(pos);
	}
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	TestList3();
	return 0;
}