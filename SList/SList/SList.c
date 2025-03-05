#include"SList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建新节点
SLTNode* BuySLTNode(SLTDataType x)
{
	//开辟新结点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		return NULL;
	}

	//新节点赋值
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
void SLTPushBack(SLTNode** pphead, SLTDataType x)//二级指针可以修改实参,使用*pphead再修改数据即可
{
	SLTNode* newnode=BuySLTNode(x);

	if (*pphead == NULL)
	{
		(*pphead) = newnode;
		return;
	}
	//找尾指针
	SLTNode* tail = *pphead;
	//tail指针存储*pphead也就是头指针的地址也就是传入的实参&plist
	//再通过tail->next不断访问到下一个结点
	//当tail->next==NULL,表示tail指针当前存储的就是尾节点的地址
	//此时tail->next直接就可以修改尾节点的SLTNode* next区域为newnode即指向新节点
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
	
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//构建新节点
	SLTNode* newnode = BuySLTNode(x);	

	/*if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	
	SLTNode* tmp = *pphead;
	*pphead = newnode;
	newnode->next = tmp;*/
	newnode->next = *pphead;
	*pphead = newnode;

}