#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;

//结构的设计，局部上，使用单链表实现队列
//各个节点共同构成队列
//每个节点有数据域和指针域
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//结构的设计，整体上，队列的关键就是头节点尾节点和长度
//头节点用于出队列，尾节点用于入队
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//下面的操作都是针对于整个队列的，因此是Queue*类型
//通过访问结构体成员head，tail，size修改队列
//实现上没有要求，能满足先进先出即可
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

