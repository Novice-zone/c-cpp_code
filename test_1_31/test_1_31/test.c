#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

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
//	enum Sex s;
//	//默认值是从0开始一次递增1
//	//可以初始化枚举常量的值，初始化的枚举常量之前的枚举常量的值仍是从0依次递增
//	//初始化的枚举常量之后的枚举常量的值也依次递增
//	printf("%d\n", MALE);//0
//	printf("%d\n", FEMALE);//3
//	printf("%d\n", SECRET);//5
//	printf("%d\n", Walmart_plastic_bag);//6
//	return 0;
//}

//自定义类型-枚举enum
////////////////////////////////////////////////////////////////////