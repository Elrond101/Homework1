/*����26����ĸ��ǰn���ַ������ظ������������ȫ���У������ֵ��������k�����е����С� 1��n��26��1��k��2^32-1��k>n!������ʾ���һ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fact(int a);
int main()
{
	int m,n,i,j;
	char d;
	long int k;
	scanf("%d,%ld", &n, &k);
	char c[n - 1];
	if(k>fact(n)&&n<13)/*��k>n!����ʾ���һ������*/
	{
		/*������������*/
		for (i = n-1; i >= 0; i--)
		{
			printf("%c", 97 + i);
		}
	}
	else
	{
			for (i = 0; i < n; i++)
			{
				c[i] = 97 + i;/*��ǰn��Сд��ĸ��������*/
			}
			/*�������k�ֽ�Ϊ1����n-1���׳˵����Ժ�*/
			if (n <= 13)
			{
				for (i = n - 1; i >= 1; i--)
				{
					m = 0;
					while (1)
					{
						if (k - 1 >= fact(i))
						{
							k -= fact(i);
							m++;
						}
						else
						{
							d = c[n - 1 - i + m];/*��d��ֵ��Ϊ��ǰ�׳˵��������Ŷ�Ӧ����������λ��*/
							for (j = n - 1 - i + m; j >= n - i; j--)
							{
								c[j] = c[j - 1];/*��Ԫ�غ���һλ*/
							}
							c[n - i - 1] = d;/*����ǰ����һλ����Ϊd*/
							break;
						}

					}
				}
			}
			else
			{
				for (i = 12; i >= 1; i--)
				{
					m = 0;
					while (1)
					{
						if (k - 1 >= fact(i))
						{
							k -= fact(i);
							m++;
						}
						else
						{
							d = c[n - 1 - i + m];/*��d��ֵ��Ϊ��ǰ�׳˵��������Ŷ�Ӧ����������λ��*/
							for (j = n - 1 - i + m; j >= n - i; j--)
							{
								c[j] = c[j - 1];/*��Ԫ�غ���һλ*/
							}
							c[n - i - 1] = d;/*����ǰ����һλ����Ϊd*/
							break;
						}

					}
				}
			}
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", c[i]);
	}
	return 0;
}
/*�׳˺���*/
int fact(int a)
{
	if (a == 1)
		return 1;
	else
		return a*fact(a-1);
}


