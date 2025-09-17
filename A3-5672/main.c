/*编程输出下面图形。其中上半层的高度（即最大的数字）由键盘输入，不超过9。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n,i,k,j;
	printf("请输入一个不大于9的整数:");
	scanf("%d", &n);
	/*输出正三角*/
	for (i = 0; i < n ; i++)
	{
		/*输出每行前的空格*/
		for (j = n - i- 1; j >= 0; j--)
		{
			printf(" ");
		}
		for (k = 0; k < i + 1; k++)
		{
			printf("%-2d", i + 1);
		}
		printf("\n");
	}
	/*输出倒三角*/
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j <= n - i; j++)
			printf(" ");
		for (k = i; k > 0; k--)
		{
			printf("%-2d", i);
		}
		printf("\n");
	}
	return 0;
}