#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//缺省参数（默认参数值）
void Func1(int a = 0) {
	cout << a << endl;
}

////多个参数，全缺省
//void Func2(int a = 10, int b = 20, int c = 30) {
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	cout << endl;
//}
//多个参数，半缺省（部分缺省）--从右往左缺省
void Func2(int a , int b = 20, int c = 30) {
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << endl;
}
int main() {

	Func1();//不传参数，调用参数的默认值
	Func1(50);//传参，调用指定实参

	//Func2();
	Func2(1);
	Func2(1,2);
	Func2(1, 2, 3);
	//Func2(1, , 3);不能跳着给
	return 0;
}