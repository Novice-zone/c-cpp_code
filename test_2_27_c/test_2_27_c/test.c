#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct S
{
	int age;
	char c;
	char arr[];//柔性数组：结构体最后一个成员是数组时，可以不指定数组大小
};

void test()
{
	struct S* p = (struct S*)malloc(sizeof(struct S) + 20 * sizeof(char));
	p->age = 10;
	p->c = 'A';
	for (int i = 0; i < 20; i++)
	{
		p->arr[i] = i;
		printf("arr[%d]=%d\n", i, i);
	}
	free(p);
	p = NULL;
	//在此看出柔性数组好处是只需要malloc和free一次
}

int main()
{
	//test();
	printf("%d\n",sizeof(struct S));

	return 0;
}