#include"Slist.h"

void TEST1()
{
	SLTNode* plist = NULL;
	SLTPushBack(plist, 1);
	SLTPushBack(plist, 2);
	SLTPushBack(plist, 3);
	SLTPushBack(plist, 4);
	SLTPrint(plist);
}

int main()
{
	TEST1();
	return 0;
}