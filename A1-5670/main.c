/*���������߶γ��ȣ�������1000�������������ж��ܷ񹹳������Σ������������ͣ�ֱ�ǡ��ȱߡ���������������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comp(int a, int b, int c);/*�ж������νǶȹ�ϵ�ĺ���*/
int main(void)
{
	int a, b, c;
	printf("�����������ε������ߣ�������1000����������");
	scanf("%d%d%d", &a, &b, &c);

	/*�ж��Ƿ��ܹ���������*/
	if (a - b < c && c < a + b && b - a < c)
	{
		printf("�ܹ���������\n");
		/*��֤�Ƿ�Ϊ�ȱ�*/
		if (a == b == c)
			printf("������Ϊ�ȱ�������\n");
		else
		{
			/*��֤�Ƿ�Ϊ����*/
			if (a == b || a == c || b == c)
				printf("������Ϊ����������\n");
			/*��֤�����εĽǶȹ�ϵ*/
			if (c > a && c > b)
				comp(a, b, c);
			if (a > b && a > c)
				comp(b, c, a);
			if (b > a && b > c)
				comp(a, c, b);

		}
	}
	else
		printf("���ܹ���������");
	return 0;
	
}
int comp(int a, int b, int c)
{
	if (a* a + b * b == c * c)
		printf("������Ϊֱ��������");
	else
		printf("�����β�Ϊֱ��������");

}