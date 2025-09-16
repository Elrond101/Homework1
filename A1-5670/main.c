/*输入三条线段长度（不超过1000的正整数），判断能否构成三角形，及三角形类型（直角、等边、等腰、其它）。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comp(int a, int b, int c);/*判断三角形角度关系的函数*/
int main(void)
{
	int a, b, c;
	printf("请输入三角形的三条边（不超过1000的整数）：");
	scanf("%d%d%d", &a, &b, &c);

	/*判断是否能构成三角形*/
	if (a - b < c && c < a + b && b - a < c)
	{
		printf("能构成三角形\n");
		/*验证是否为等边*/
		if (a == b == c)
			printf("三角形为等边三角形\n");
		else
		{
			/*验证是否为等腰*/
			if (a == b || a == c || b == c)
				printf("三角形为等腰三角形\n");
			/*验证三角形的角度关系*/
			if (c > a && c > b)
				comp(a, b, c);
			if (a > b && a > c)
				comp(b, c, a);
			if (b > a && b > c)
				comp(a, c, b);

		}
	}
	else
		printf("不能构成三角形");
	return 0;
	
}
int comp(int a, int b, int c)
{
	if (a* a + b * b == c * c)
		printf("三角形为直角三角形");
	else
		printf("三角形不为直角三角形");

}