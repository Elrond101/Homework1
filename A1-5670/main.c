/*���������߶γ��ȣ�������1000�������������ж��ܷ񹹳������Σ������������ͣ�ֱ�ǡ��ȱߡ���������������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comp(int a, int b, int c, int i);/*�ж������νǶȹ�ϵ�ĺ���*/
int main(void)
{
	int a, b, c,i = 0;
	scanf("%d,%d,%d", &a, &b, &c);

	/*�ж��Ƿ��ܹ���������*/
	if (a - b < c && c < a + b && b - a < c)
	{
		/*��֤�Ƿ�Ϊ�ȱ�*/
		if (a == b && b == c)
			printf("equilateral triangle\n");
		else
		{
			/*��֤�Ƿ�Ϊ����*/
			if (a == b || a == c || b == c)
				printf("isosceles triangle\n"); 
			else
			{
				/*��֤�����εĽǶȹ�ϵ*/
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
		return 1;//���Ϊֱ��������
	}
	else
		return 0; //����ֱ��������
}