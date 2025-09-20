/*输入三条线段长度（不超过1000的正整数），判断能否构成三角形，及三角形类型（直角、等边、等腰、其它）。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comp(int a, int b, int c, int i);/*判断三角形角度关系的函数*/
int main(void)
{
	int a, b, c,i = 0;
	scanf("%d,%d,%d", &a, &b, &c);

	/*判断是否能构成三角形*/
	if (a - b < c && c < a + b && b - a < c)
	{
		/*验证是否为等边*/
		if (a == b && b == c)
			printf("equilateral triangle\n");
		else
		{
			/*验证是否为等腰*/
			if (a == b || a == c || b == c)
				printf("isosceles triangle\n"); 
			else
			{
				/*验证三角形的角度关系*/
				if (c > a && c > b)
					i = comp(a, b, c, i);
				if (a > b && a > c)
					i = comp(b, c, a, i);
				if (b > a && b > c)
					i = comp(a, c, b, i);
				if (i == 0)
					printf("normal triangle\n");
			}
		}
	}
	else
		printf("NOT triangle");
	return 0;
	
}
int comp(int a, int b, int c, int i)
{
	if (a * a + b * b == c * c)
	{
		printf("right triangle"); 
		return 1;//标记为直角三角形
	}
	else
		return 0; //不是直角三角形
}