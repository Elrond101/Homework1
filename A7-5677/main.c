/*
现有面值为a、b、c（0 < c < b < a ≤ 100）的三种钞票，买方分别有na、nb、nc张，
卖方分别有ma、mb、mc张。问双方能否就一个价值为E的商品完成购买？
如果可以，请给出一种双方交换钞票张数之和最少的支付与找钱的方法（张数相同时，取找钱数量最少的方法）。
每人每种面额钞票数不超过100，商品价值不超过10000，均为整数。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, na, nb, nc, ma, mb, mc, E;
	scanf("%d,%d,%d", a, b, c);
	scanf("%d,%d,%d", na, nb, nc);
	scanf("%d,%d,%d", ma, mb, mc);
	scanf("%d", E);

	return 0;
}
