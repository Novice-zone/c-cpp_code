#include"SList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode* phead, SLTDataType x)
{
	//开辟新结点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc.fail");
		return;
	}

	//新节点赋值
	newnode->data = x;
	newnode->next = NULL;

	//找末尾元素位置sail
	SLTNode* sail = phead;
	while (sail->next != NULL)
	{
		sail = sail->next;
	}
	sail->next = newnode;
}