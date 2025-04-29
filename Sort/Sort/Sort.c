#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
	//PrintArray(a, n);
}

void ShellSort(int* a, int n) {
	/*int gap = 3;
	for (int j = 0; j < gap; j++) {
		for (int i = j; i < n - gap; i += gap) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
		PrintArray(a, n);
	}*/
	/*int gap = 3;
	for (int i = 0; i < n - gap; i++) {
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + gap] = a[end];
				end -= gap;
			}
			else {
				break;
			}
		}
		a[end + gap] = tmp;
		PrintArray(a, n);
	}*/

	int gap = n;
	while (gap > 1) {
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n) {
	//left为要找到范围的左边界，right为右边界
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int mini = left, maxi = left;
		for (int i = left + 1; i <= right; i++) {//mini为最小数的下标，maxi为最大数的下标
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		//最小/最大数放在最前面和最后面
		Swap(&a[left], &a[mini]);

		//最大值maxi在最左边，而左边和mini交换位置，需要更新maxi的值
		if (left == maxi) {
			maxi = mini;
		}

		Swap(&a[right], &a[maxi]);

		left++;
		right--;
		PrintArray(a, n);
	}
}