/*���� 1!+2!+3!+...+n!�����������ָ��Ϊmax����������ʾ��overflow��������������n��max���������������1��n��100, 0��max��4e9��+*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long int fact(unsigned long int n);/*�׳�*/
unsigned long int main(void)
{
	unsigned long int n, max, i, CF = 0, sum = 0;
	printf("������һ��������100����������");
	scanf("%d", &n);
	printf("\n������͵����ֵ:");
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
				CF = 1;/*�������ʶ��Ϊ1*/
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
		return fact(n - 1) * n;/*�ݹ����׳�*/
	else
		return 1;
	return 0;
}
