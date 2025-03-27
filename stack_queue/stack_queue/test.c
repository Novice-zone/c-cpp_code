#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include"queue.h"

void STTest()
{
	ST st;
	STInit(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
}

void QTest()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//printf("%d\n", QSize(&q));
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	return 0;
}
int main()
{
	QTest();
	return 0;
}