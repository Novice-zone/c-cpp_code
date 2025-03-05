#include"Slist.h"

void TEST1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);//改变实参，传地址
	SLTPushBack(&plist, 2);//改变SLTNode*，传SLTNode*的地址
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
}

void TEST2()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);
}
int main()
{
	TEST2();
	return 0;
}