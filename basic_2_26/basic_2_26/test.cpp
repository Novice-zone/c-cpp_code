#define _CRT_SECURE_NO_WARNINGS 1


//排序算法
//规则：升序
//算法1.冒泡排序
//#include <iostream>
//
//using namespace std;
//
//void myBubbleSort(int arr[], int sz)
//{
//	//第一轮：每个元素与后面的那个元素比较大小，共比较sz-1次
//	//第二轮：共比较sz-2次
//	//共比较sz-1轮
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz - i - 1;j++)
//		{
//			if (arr[j]  > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void printArr(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test1()
//{
//	int arr[] = { 9,7,5,4,3,8,6,1,2, };
//	int sz = sizeof(arr) / sizeof(arr[0]);//这里的数组名表示整个数组
//	myBubbleSort(arr, sz);
//	printArr(arr, sz);
//}
//
//int main()
//{
//	test1();
//	return 0;
//}

//算法2：选择排序
#include<iostream>
using namespace std;

template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void chooseSort(int arr[],int sz)
{
	//规则：
	//第一轮：拿第一个元素和后面的元素依次比较，找出最大的一个放在最后一位
	for (int i = 0; i < sz-1; i++)
	{
		int min = i;//min为最小元素下标
		for (int j = i+1; j < sz; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		mySwap(arr[min], arr[i]);
	}
}

void printArr(const int arr[], const int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test2()
{
	int arr[] = { 9,7,5,4,3,8,6,1,2, };
	int sz = sizeof(arr) / sizeof(arr[0]);//这里的数组名表示整个数组
	chooseSort(arr, sz);
	printArr(arr, sz);
}

int main()
{
	test2();
	return 0;
}


//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//#define stunum 3
//#define teanum 3
//
//struct Stu
//{
//	int age;
//	string name;
//	bool sex;
//};
//
//struct Teacher
//{
//	string name;
//	
//	struct Stu sarr[stunum];
//};
//
////赋值函数
//void allocate(struct Teacher tarr[teanum])
//{
//	string nameSeed = "ABCDEFGHI";
//	int StudentIndex = 0;
//
//	for (int i = 0; i < teanum; i++)
//	{
//		// 将 char 转换为 string 再拼接
//		tarr[i].name = "teacher_" + string(1, nameSeed[i]);
//		for (int j = 0; j < stunum; j++)
//		{
//			tarr[i].sarr[j].age = rand() % 4 + 18;
//			// 将 char 转换为 string 再拼接
//			tarr[i].sarr[j].name = "student_" + string(1, nameSeed[StudentIndex]);
//			tarr[i].sarr[j].sex = rand() % 2;
//			StudentIndex++;
//		}
//
//	}
//
//}
//
////打印函数
//void print_info(struct Teacher tarr[teanum])
//{
//	for (int i = 0; i < teanum; i++)
//	{
//		cout << "老师姓名：" << tarr[i].name << endl;
//		for (int j = 0; j < stunum; j++)
//		{
//			cout << "\t学生姓名：" << tarr[i].sarr[j].name << endl;
//			cout << "\t学生年龄：" << tarr[i].sarr[j].age << endl;
//			cout << "\t学生性别：" << tarr[i].sarr[j].sex << endl;
//
//		}
//	}
//	
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	//创建老师
//	struct Teacher tarr[teanum];
//
//	//给老师和学生赋值
//	allocate(tarr);
//
//	//打印老师和学生的信息
//	print_info(tarr);
//
//	return 0;
//}

//new
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int* p = new int(10);
//	cout << *p << endl;
//	delete p;
//
//	int * p2=new int[10];
//	for (int i = 0; i < 10; i++)
//	{
//		*(p2 + i) = i;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p2[i] << endl;
//	}
//
//	delete p2;
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	int a = 10;
//	int& b = a;
//	std::cout <<"a的地址为：" << &a << std::endl <<"b的地址为：" << &b;
//	return 0;
//}

//引用就是起别名
//#include <iostream>
//using namespace std;
//
//void my_swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << "a的地址为：" << &a << endl << "b的地址为：" << &b<<endl;
//	cout << "a的值为：" << a << endl << "b的值为：" << b << endl;
//
//	b = 8;
//	cout << "a的值为：" << a << endl
//		<< "b的值为：" << b << endl;
//
//	int c = 5;
//	b = c;
//	cout << "a的值为：" << a << endl
//		<< "b的值为：" << b << endl
//		<< "c的值为：" << c << endl;
//
//	//int& b = c;错误
//	int d = 10;
//	int e = 20;
//	my_swap(d, e);
//
//	cout << d << endl << e << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
////函数模板
//template <typename T>
//void mySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	//自动类型推导
//	mySwap(a, b);
//	cout << "a=" << a << endl << "b=" << b << endl;
//	//显示指定类型
//	mySwap<int>(a, b);
//	cout << "a=" << a << endl << "b=" << b << endl;
//
//	return 0;
//}

////创建数组排序模板函数
//// 规则：从大到小
//// 算法：选择
//// 测试：字符数组和整型数组
//
//#include <iostream>
//
//using namespace std;
//

//template <class T>
//void mySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template <class T>
//void mySort(T arr[],int len)
//{
//	
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;//最大元素下标
//		for (int j = i+1; j < len; j++)
//		{
//			if (arr[max] <arr[j])
//			{
//				max = j;
//			}
//		}
//		//交换位置
//		mySwap(arr[i], arr[max]);
//	}
//}
//
////打印模板函数
//template <class T>
//void myPrint(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
////测试用例
//void test1()
//{
//	char arr[] = "akjrwfd";
//	int num = sizeof(arr) / sizeof(arr[0])-1;
//	mySort(arr, num);
//	myPrint(arr, num);
//}
//
//int main()
//{
//	test1();
//	return 0;
//}