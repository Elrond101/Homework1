/*读入一个未排序int型数组nums，请找出其中没有出现的最小正整数。数组长度不超过10 ^ 5，数字大小[-2 ^ 31, 2 ^ 31 - 1]。
要求：时间复杂度为O(n)，且只使用常数级别的额外存储空间。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 1, i, switcher;
	scanf("%d", &n);
	int nums[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (1 <= nums[i] && nums[i] <= n)
		{
			if (nums[nums[i] - 1] == nums[i])
				continue;
			else
			{
				switcher = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = switcher;
			}
		}
	}
	for(i=0; i < n; i++)
	{
		if (nums[i] != i + 1)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("%d", n + 1);
	return 0;
}
