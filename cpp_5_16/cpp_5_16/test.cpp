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
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int a = 0;
	int b = 10;
	cout << "a:" << a << " b:" << b << endl;

	Swap(a, b);
	cout << "a:" << a << " b:" << b << endl;
	return 0;
}