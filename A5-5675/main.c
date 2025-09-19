/*给定26个字母的前n个字符（不重复），对其进行全排列，并按字典排序，求第k个排列的序列。 1≤n≤26，1≤k≤2^32-1若k>n!，则显示最后一个排列*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fact(int a);
int devide(int n, long int k);
int main()
{
	int m,n,i,j;
	char d;
	long int k;
	printf("请输入字符数目：");
	scanf("%d", &n);
	printf("请输入排列序号：");
	scanf("%ld", &k);
	char c[n - 1] = {};
	if(k>fact(n))/*若k>n!，显示最后一个排列*/
	{
		/*输出反序的数组*/
		for (i = n-1; i >= 0; i--)
		{
			printf("%c", 97 + i);
		}
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			c[i] = 97 + i;/*将前n个小写字母赋给数组*/
		}
		/*将输入的k分解为1到（n-1）阶乘的线性和*/
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
					d = c[n - 1 - i + m];/*将d的值设为当前阶乘的最大倍数序号对应索引的数组位置*/
					for (j = n - 1 - i + m; j >= n - i; j--)
					{
						c[j] = c[j - 1];/*将元素后移一位*/
					}
					c[n - i - 1] = d;/*将当前“第一位”设为d*/
					break;
				}

			}
		}
	
		/*遍历数组元素*/
		for (i = 0; i < n; i++)
		{
			printf("%c", c[i]);
		}
	}
	return 0;
}
/*阶乘函数*/
int fact(int a)
{
	if (a == 1)
		return 1;
	else
		return a*fact(a-1);
}


