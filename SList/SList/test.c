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

void TEST3()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
	
	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
}

void TEST4()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
}

void TEST5()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);

	//找到结点位置之后就可以修改值
	SLTNode* find = SLTFind(plist, 2);
	if (find != NULL)
	{
		find->data = 4;
	}
	SLTPrint(plist);
	return;
}

void TEST6()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);

	SLTNode* pos = SLTFind(plist, 2);
	SLTInsert(&plist, pos, 20);
	SLTPrint(plist);

	SLTErase(&plist, pos);
	SLTPrint(plist);
}

void TEST7()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTNode* pos = SLTFind(plist,2);
	SLTInsertAfter(pos, 20);
	SLTPrint(plist);

	SLTEraseAfter(pos);
	SLTPrint(plist);

}

int main()
{
	TEST7();
	return 0;
}