#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	//为什么给这个指针分配LTNode的空间而不是LTNode*（为什么给结构体指针分配结构体大小的空间）
	//后续的 sizeof(LTNode) 大小的内存空间是被该结构体对象所占用的，其他程序或操作不能随意访问或修改这部分内存
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

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	//哨兵位未置空
	free(phead);
	//phead=NULL;
}

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
	LTErase(phead->prev);
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
	LTErase(phead->next);
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
	LTNode* p = pos->prev;
	LTNode* n = pos->next;
	p->next = n;
	n->prev = p;

	free(pos);
	pos = NULL;
}