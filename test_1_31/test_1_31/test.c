#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//�Զ�������-ö��enum
//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};//ö������enum Sex
//
//int main()
//{
//	enum Sex s;//Ĭ��ֵ�Ǵ�0��ʼһ�ε���1
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
//};//ö������enum Sex
//
//int main()
//{
//	//Ĭ��ֵ�Ǵ�0��ʼһ�ε���1
//	//���Գ�ʼ��ö�ٳ�����ֵ����ʼ����ö�ٳ���֮ǰ��ö�ٳ�����ֵ���Ǵ�0���ε���
//	//��ʼ����ö�ٳ���֮���ö�ٳ�����ֵҲ���ε���
//	printf("%d\n", MALE);//0
//	printf("%d\n", FEMALE);//3
//	printf("%d\n", SECRET);//5
//	printf("%d\n", Walmart_plastic_bag);//6
//
//	enum Sex s;//ö�����ͱ���s
//	printf("%d\n", sizeof(s));//��С��4�ֽ�
//	return 0;
//}

////////////////////////////////////////////////////////////////////
//�Զ�������-������union

//�������ص�
//�����干��һ���ڴ�ռ䣬��������������£����߾��ӵ�һ����ַ��ʼռ��
union UN1
{
	char c;
	int i;
}un;

union UN2
{
	char c[5];//������1
	int a;//������4
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

	printf("%d\n", sizeof(un));//��С��4�ֽ�
	printf("%d\n", sizeof(un2));//��С8�ֽڣ���ṹ�����������ڴ����

	//�������С����������Ա�Ĵ�С��un��С��4

	return 0;
}

