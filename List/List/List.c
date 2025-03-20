#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc:");
		return NULL;
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;

	return newnode;
}

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->prev = phead;
	phead->next = phead;

	return phead;
}

void LTDestroy();

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	//不为空就无事发生
	//也就是不为空就返回1（true）
	return phead->next == phead;
}

void LTPrint(LTNode* phead)
{
	//保证phead已经被初始化
	assert(phead);

	printf("head<=>");
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("head\n");
	
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	////phead不能为空，必须要保证phead的prev和next有指向
	////或者说必须要保证phead已经被初始化
	//assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;

	////phead				tail	newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	////注意哪里需要更新prev和next指针

	//使用LTInsert即可
	//pos就是phead，因为在pos之前插入就是在phead之前也就是尾部插入
	LTInsert(phead, x);
}

void LTPopBack(LTNode* phead)
{
	////phead必须要初始化过
	//assert(phead);
	////链表要有有效节点
	//assert(!LTEmpty(phead));

	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;

	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//free(tail);
	//tail = NULL;
	LTErase(phead);
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	////保证phead初始化
	//assert(phead);
	///*LTNode* first = phead->next;

	//LTNode* newnode = BuyListNode(x);
	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = first;
	//first->prev = newnode;*/

	//LTNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//(phead->next)->prev = newnode;

	//newnode->prev = phead;
	//phead->next = newnode;

	//LTInsert代替头插
	//pos就是第一个有效节点phead->next
	//无有效节点也不影响
	LTInsert(phead->next, x);
}

void LTPopFront(LTNode* phead)
{
	//assert(phead);
	//assert(!LTEmpty(phead));

	////phead->next->next->prev = phead;
	////phead->next = phead->next->next;
	//phead->next = phead->next->next;
	//phead->next->prev = phead;
	LTErase(phead->next->next);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;//cur指向第一个有效节点
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);

	pos->prev->next = newnode;
	newnode->prev = pos->prev;

	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	assert(!LTEmpty(pos));
	LTNode* prev = pos->prev;
	(pos->prev->prev)->next = pos;
	pos->prev = pos->prev->prev;
	free(prev);
	prev = NULL;
}