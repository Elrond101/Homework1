/*����һ��δ����int������nums�����ҳ�����û�г��ֵ���С�����������鳤�Ȳ�����10 ^ 5�����ִ�С[-2 ^ 31, 2 ^ 31 - 1]��
Ҫ��ʱ�临�Ӷ�ΪO(n)����ֻʹ�ó�������Ķ���洢�ռ䡣
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
