/*
编程验证哥德巴赫猜想：一个不小于6的偶数可以表示为两个奇素数之和。如6=3+3，8=3+5，10=3+7。
输入偶数n（unsigned int，6 ≤ n ≤ 10000），输出所有可能的分解结果（按第一个奇素数从小到大为序），
但不包括把两个素数交换位置相加的情形。例如8=3+5，不要再输出8=5+3。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int is_Prime(unsigned int a);
int main()
{
	unsigned int n;
	scanf("%ud", &n);
	for (unsigned int i = 3; i <= n / 2; i += 2)
	{
		if (!is_Prime(i))
			continue;
		else
		{
			if (is_Prime(n - i))
			{
				printf("%u=%u+%u\n", n, i, n - i);
			}
		}
	}
	return 0;
}

int is_Prime(unsigned int a)
{
	for (int i = 3; i <= sqrt(a); i += 2)
	{
		if (a % i == 0 && a != i)
			return 0;
	}
	return 1;
}
