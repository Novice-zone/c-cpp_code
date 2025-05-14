#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int a = 10;
//
//namespace haha{
//	int a = 100;
//}
////using namespace haha;
//
//int main() {
//	int a = 1;
//	printf("%d\n", a);
//	
//	printf("%d\n", ::a);
//
//	printf("%d\n", haha::a);
//
//	return 0;
//}
// 1. 正常的命名空间定义，可以定义变量，函数，类型
namespace dfd {
    int a = 10;
    int Add(int left, int right) {
        return left + right;
    }
    struct Node {
        struct Node* next;
        int val;
    };
}      //不写;
//也可以嵌套定义
namespace S1 {
    int b = 20;
    namespace S2 {
        int b = 30;
    }
}

#include <iostream>
//int main() {
//    printf("%d ", dfd::a);
//    printf("%d ", S1::b);
//    printf("%d \n", S1::S2::b);
//
//    std::cout << dfd::a << std::endl;
//    
//    int p;
//    std::cin >> p;
//    std::cout << p << std::endl;
//    return 0;
//}
//using std::cout;
//using std::endl;
//int main() {
//    printf("%d ", dfd::a);
//    printf("%d ", S1::b);
//    printf("%d \n", S1::S2::b);
//
//    cout << dfd::a << endl;
//
//    int p;
//    std::cin >> p;
//    cout << p << endl;
//    return 0;
//}
using namespace std;
int main() {
    printf("%d ", dfd::a);
    printf("%d ", S1::b);
    printf("%d \n", S1::S2::b);

    cout << dfd::a << endl;

    int p;
    cin >> p;
    cout << p << endl;
    return 0;
}