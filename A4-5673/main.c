/*��̰����¹�ʽ����еĽ���ֵ��ֱ��ĳ��kֵ��Ӧ�������������С��ָ�����ȡ����磬���n��ʾ����Ϊ10^(-n)���������ʾС�����nλ��1��n��12*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,k=0;
	scanf("%d", &n);
	long double pi_l = 0, pi_f = 0;//����piֵ����ǰ�󾫶ȵıȽ�
	while (1)
	{
		pi_f = pi_l;
		pi_l += 1.0 / pow(16, k) * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6));
		/*�ж��Ƿ񵽴�ָ�����ȣ���������ѭ��*/
		if (pi_l - pi_f < pow(10,-n))
			break;
		k++;
	}
	printf("pi=%.*Lf",n,pi_l);
	return 0;
}