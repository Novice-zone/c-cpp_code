#include<iostream>
using namespace std;

//int main() {
//	int a = 0;
//	//int& m;
//
//	int& b = a;
//	int& c = b;
//	int& d = c;
//
//	cout << a << endl << b << endl << c << endl << d << endl;
//
//	c = 9;
//	cout << a << endl << b << endl << c << endl << d << endl;
//
//	int m = 10;
//	//&b = m;
//	b = m;
//	cout << a << endl << b << endl << c << endl << d << endl;
//
//	return 0;
//}

//引用的好处
//void Swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main() {
//	int a = 1;
//	int b = 10;
//	cout << "a:" << a << " b:" << b << endl;
//
//	Swap(&a, &b);
//	cout << "a:" << a << " b:" << b << endl;
//
//	return 0;
//}
//void Swap(int& a, int& b) {//形参是实参的别名，交换整型，使用整型的别名a
//	int tmp = a;
//	a = b;
//	b = tmp;
//}

////引用：数据类型 & 别名
//void Swap(int*& a, int*& b) {//交换指针，使用指针的别名
//	int* tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a = 0;
//	int b = 10;
//	cout << "a:" << a << " b:" << b << endl;
//
//	Swap(a, b);
//	cout << "a:" << a << " b:" << b << endl;
//
//	int* pa = &a,* pb = &b;
//	cout << "pa:" << pa << " pb:" << pb << endl;
//	
//	Swap(pa, pb);
//	cout << "pa:" << pa << " pb:" << pb << endl;
//
//	return 0;
//}

//******引用：数据类型 & 别名
//因此之前在某本数据结构教材上看到这样的写法
//typedef struct ListNode {
//	int val;
//	struct ListNode* next;
//}LTNode,*PLTNode;
////上面是定义了结构体LTNode和结构体指针PLTNode
//
//
////void ListPushBack(LTNode* & phead,int x)
//void ListPushBack(PLTNode& phead, int x) {
//	//...此处省略具体实现
//}

//1.引用做参数 （输出型参数）--形参的改变影响实参

//经典的输出型参数
void Swap(int& left, int& right) {
	int tmp = left;
	left = right;
	right = tmp;
}
//前序遍历
// int* preTra(struct TreeNode* root,int* returnSize)-- c语言
// int* preTra(struct TreeNode* root,int& returnSize)-- c++


//引用做参数 （高效率）（大对象（占用空间比较大的对象））

//引用做返回值
//
//C语言设计返回值：会创建临时变量拷贝返回值a
int Counter1(int x) {
	static int a = x;
	return a;
}

//C++：不创建临时拷贝，直接返回静态局部变量 a 的引用
//注意：这里的static很关键，可以保证把销毁栈帧（栈帧返回给操作系统）后，返回值是正确的（博客里讨论不加static的两种情况）
//函数返回类型int&也很关键，使得函数更高效
int& Counter2() {
	static int a = 0;
	return a;
}

int main() {
	int& count = Counter2();
	cout << count << endl;

	Counter2()++;
	cout << count << endl;
	return 0;
}