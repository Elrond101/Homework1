/*��̰����¹�ʽ����еĽ���ֵ��ֱ��ĳ��kֵ��Ӧ�������������С��ָ�����ȡ����磬���n��ʾ����Ϊ10^(-n)���������ʾС�����nλ��1��n��12*/
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653589793  /*����Բ���ʳ������ھ��ȱȽ�*/
#include <stdio.h>
#include <math.h>
int main(void)
{
	printf("�����뾫��n:");
	int n,k=0;
	scanf("%d", &n);
	long double pi = 0;
	while (1)
	{
		pi += 1.0 / pow(16, k) * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6));
		/*�ж��Ƿ񵽴�ָ�����ȣ���������ѭ��*/
		if (pow(10,n)*PI - pow(10, n) * pi < 1 && pow(10, n)* pi - pow(10, n) * PI < 1)
			break;
		k++;
	}
	printf("%.*Lf",n,pi);
	return 0;
}