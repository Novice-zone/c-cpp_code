#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//自定义类型-枚举enum
//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};//枚举类型enum Sex
//
//int main()
//{
//	enum Sex s;//默认值是从0开始一次递增1
//	printf("%d\n",MALE);//0
//	printf("%d\n",FEMALE);//1
//	printf("%d\n",SECRET);//2
//
//	return 0;
//}

//enum Sex
//{
//	MALE,
//	FEMALE=3,
//	SECRET=5,
//	Walmart_plastic_bag
//};//枚举类型enum Sex
//
//int main()
//{
//	//默认值是从0开始一次递增1
//	//可以初始化枚举常量的值，初始化的枚举常量之前的枚举常量的值仍是从0依次递增
//	//初始化的枚举常量之后的枚举常量的值也依次递增
//	printf("%d\n", MALE);//0
//	printf("%d\n", FEMALE);//3
//	printf("%d\n", SECRET);//5
//	printf("%d\n", Walmart_plastic_bag);//6
//
//	enum Sex s;//枚举类型变量s
//	printf("%d\n", sizeof(s));//大小是4字节
//	return 0;
//}

////////////////////////////////////////////////////////////////////
//自定义类型-联合体union

//联合体特点
//联合体共用一个内存空间，在下面这种情况下，二者均从第一个地址开始占用
union UN1
{
	char c;
	int i;
}un;

union UN2
{
	char c[5];//对齐数1
	int a;//对齐数4
}un2;

//int main()
//{
//	un.i = 1;
//	un.c = 0;
//	printf("%d\n", un.c);//0
//	printf("%d\n", un.i);//0
//	return 0;
//}
int main()
{
	un.c = 0;
	un.i = 1;

	printf("%d\n", un.c);//1
	printf("%d\n", un.i);//1

	printf("%d\n", sizeof(un));//大小是4字节
	printf("%d\n", sizeof(un2));//大小8字节，像结构体那样存在内存对齐

	//联合体大小最少是最大成员的大小如un大小是4

	return 0;
}

