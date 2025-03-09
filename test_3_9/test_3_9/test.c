#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
int removeElement(int* nums, int numsSize, int val) {
	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[count] = nums[i];
			count++;
		}
	}
	return count;
}

void test()
{
	int nums[] = { 1,2,3,4,5,6,7,8,2,3,4,6,2,3 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int a=removeElement(nums, sz, 2);
	printf("%d\n", a);
	for (int i = 0; i < a; i++)
	{
		printf("%d ", nums[i]);
	}
}

int main()
{
	test();
	return 0;
}