#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void QInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QDestroy(Queue* pq)
{
	assert(pq);
	while (pq->head)
	{
		Queue* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QPush(Queue* pq, QDataType x)
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
	if (pq->head == NULL)
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
void QPop(Queue* pq)
{
	assert(pq);
	assert(pq->head!=NULL);
	//最后一个节点要把head和tail都置空
	if (pq->head->next==NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
int QSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == pq->tail&&pq->head == NULL;
}
QDataType QFront(Queue* pq)
{
	assert(pq);
	assert(!QEmpty(pq));
	return pq->head->data;
}
QDataType QBack(Queue* pq)
{
	assert(pq);
	return pq->tail->data;
}
