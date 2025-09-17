/*编程按以下公式计算π的近似值，直至某个k值对应项引入的相对误差小于指定精度。例如，输出n表示精度为10^(-n)，且输出显示小数点后n位。1≤n≤12*/
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653589793  /*设置圆周率常量用于精度比较*/
#include <stdio.h>
#include <math.h>
int main(void)
{
	printf("请输入精度n:");
	int n,k=0;
	scanf("%d", &n);
	long double pi = 0;
	while (1)
	{
		pi += 1.0 / pow(16, k) * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6));
		/*判断是否到达指定精度，是则跳出循环*/
		if (pow(10,n)*PI - pow(10, n) * pi < 1 && pow(10, n)* pi - pow(10, n) * PI < 1)
			break;
		k++;
	}
	printf("%.*Lf",n,pi);
	return 0;
}