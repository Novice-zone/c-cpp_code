#include<iostream>
using namespace std;

//形参个数重载
//void Func(int a) {
//	cout <<"int a:" << a << endl;
//}
//void Func(int a, char b) {
//	cout << "int a:" << a << '\n' << "char b:" << b << endl;
//}
//
//int  main() {
//	int a = 1;
//	char b = 'D';
//
//	Func(a);
//	Func(a, b);
//
//	return 0;
//}
//形参类型重载
//void Func(int a) {
//	cout << "int :" << a << endl;
//}
//void Func(double b) {
//	cout << "double :" << b << endl;
//}
//
//int main() {
//	int a = 1;
//	double b = 1.1;
//	Func(a);
//	Func(b);
//	return 0;
//}
//形参顺序重载
void Func(int a, char b) {
	cout << "Func(int a,char b)" << endl;
}
//错误重载
//void Func(int b,char a){
//	cout << "Func(int b,char a)" << endl;
//}
//正确
void Func(char b, int a) {
	cout << "Func(char b,int a)" << endl;

}

int main() {
	int n = 1;
	char m = 'm';
	Func(n, m);
	Func(m, n);
	return 0;
}