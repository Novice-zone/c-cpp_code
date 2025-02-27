#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrint(int val)
{
	cout << "for_each()遍历：" << val << endl;
}

void test1()
{
	//创建容器并通过模板参数指定容器中的数据类型
	vector<int> v;

	//尾插法插入元素
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//使用容器vector的迭代器遍历容器中的元素
	//v.begin()指向容器中第一个元素的位置
	//v.end()指向容器中最后一个元素的下一个位置
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//遍历容器
	//方法一：
	while (pBegin != pEnd)
	{
		cout <<"while遍历：" << *pBegin << endl;
		pBegin++;
	}

	//方法二：
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout <<"for遍历：" << *it << endl;
	}

	//方法三：STL提供的标准遍历算法 <algorithm>
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	test1();

	return 0;
}