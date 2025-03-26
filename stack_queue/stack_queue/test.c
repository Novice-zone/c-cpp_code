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
	QInit(&q);

	QPush(&q, 1);
	QPush(&q, 2);
	QPush(&q, 3);
	//printf("%d\n", QSize(&q));
	QPush(&q, 4);
	QPush(&q, 5);

	while (!QEmpty(&q))
	{
		printf("%d ", QFront(&q));
		QPop(&q);
	}
	printf("\n");

	return 0;
}
int main()
{
	QTest();
	return 0;
}