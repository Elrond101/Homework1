/*编程按以下公式计算π的近似值，直至某个k值对应项引入的相对误差小于指定精度。例如，输出n表示精度为10^(-n)，且输出显示小数点后n位。1≤n≤12*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,k=0;
	scanf("%d", &n);
	long double pi_l = 0, pi_f = 0;//两个pi值用于前后精度的比较
	while (1)
	{
		pi_f = pi_l;
		pi_l += 1.0 / pow(16, k) * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6));
		/*判断是否到达指定精度，是则跳出循环*/
		if (pi_l - pi_f < pow(10,-n))
			break;
		k++;
	}
	printf("pi=%.*Lf",n,pi_l);
	return 0;
}