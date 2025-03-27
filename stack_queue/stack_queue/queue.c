#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);//确保传入的队列不为空

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//释放每个节点，以达到释放整个队列的空间
	while (pq->head)
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	//把指针置空防止非法访问
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//尾插新节点
	QNode* newcode = (QNode*)malloc(sizeof(QNode));
	if (newcode == NULL)
	{
		perror("malloc:newcode");
		return;
	}
	newcode->data = x;
	newcode->next = NULL;

	if (pq->head == NULL)//当队列为空
	{
		assert(pq->tail == NULL);
		pq->head = pq->tail = newcode;
	}
	else
	{
		pq->tail->next = newcode;
		pq->tail = pq->tail->next;
	}

	pq->size++;
}
void QueuePop(Queue* pq)
{
	//断言其实就是看是否存在为空的可能性，不可能则需要断言，以便出错时查找
	assert(pq);
	assert(pq->head!=NULL);

	//最后一个节点要把head和tail都置空
	//head  ->NULL
	//tail  ->NULL
	if (pq->head->next==NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		//头删
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//return pq->head == pq->tail&&pq->head == NULL;
	return pq->size == 0;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
