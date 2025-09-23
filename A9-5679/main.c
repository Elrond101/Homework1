/*
�����֤��°ͺղ��룺һ����С��6��ż�����Ա�ʾΪ����������֮�͡���6=3+3��8=3+5��10=3+7��
����ż��n��unsigned int��6 �� n �� 10000����������п��ܵķֽ���������һ����������С����Ϊ�򣩣�
����������������������λ����ӵ����Ρ�����8=3+5����Ҫ�����8=5+3��
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
