#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int a = 10;

namespace haha{
	int a = 100;
}
//using namespace haha;

int main() {
	int a = 1;
	printf("%d\n", a);
	
	printf("%d\n", ::a);

	printf("%d\n", haha::a);

	return 0;
}