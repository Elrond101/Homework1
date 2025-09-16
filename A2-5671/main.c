/*计算 1!+2!+3!+...+n!。计算结果最大指定为max，超出则显示“overflow”。输入正整数n和max，输出计算结果。（1≤n≤100, 0≤max≤4e9）+*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long int fact(unsigned long int n);/*阶乘*/
unsigned long int main(void)
{
	unsigned long int n, max, i, CF = 0, sum = 0;
	printf("请输入一个不大于100的正整数：");
	scanf("%d", &n);
	printf("\n请输入和的最大值:");
	scanf("%d", &max);
	if (n >= 13)
		printf("\noverflow");
	else
	{
		for (i = 1; i <= n; i++)
		{
			sum += fact(i);
			if (sum > max)
			{
				CF = 1;/*将溢出标识设为1*/
				break;
			}
		}
		if (CF == 1)
			printf("overflow");
		else
			printf("\n%d", sum);
	}
	return 0;
}

unsigned long int fact(unsigned long int n)
{
	if (n > 1)
		return fact(n - 1) * n;/*递归计算阶乘*/
	else
		return 1;
	return 0;
}
