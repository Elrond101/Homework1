/*����������ͼ�Ρ������ϰ��ĸ߶ȣ����������֣��ɼ������룬������9��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n,i,k,j;
	scanf("%d", &n);
	/*���������*/
	for (i = 0; i < n ; i++)
	{
		/*���ÿ��ǰ�Ŀո�*/
		for (j = n - i- 2; j >= 0; j--)
		{
			printf(" ");
		}
		for (k = 0; k < i; k++)
		{
			printf("%-2d", i + 1);
		}
		printf("%d", i + 1);
		printf("\n");
	}
	/*���������*/
	for (i = n - 1; i > 0; i--)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (k = i - 1; k > 0; k--)
		{
			printf("%-2d", i);
		}
		printf("%d", i);
		printf("\n");
	}
	return 0;
}