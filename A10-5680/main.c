/*
ĳѧ�����ſγ̵ĳɼ���Ϊ�ٷ�����������������GPA�������Ȩƽ���ֵĿ��ܵķ�Χ������Сֵ�����ֵ������һλС������
�Լ���Ȩƽ���ֵĿ��ܷ�ֵ���������ٶ����пγ̵�ѧ�־�Ϊ1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float gpa;
	float max, min;
	int pos;
	float ave_gpa;//����������Сgpa���ƽ��gpa
	scanf("%f", &gpa);
	if (gpa * 5 - (int)(gpa * 5) > 1e-3)
	{
		printf("Impossible");
		return 0;
	}
	if(gpa == 5)
	{
		max = 100;
		min = 100;
		pos = 1;
	}
	else
	{
		if (gpa == 0)
		{
			max = 59;
			min = 0;
			pos = 60;
		}
		else
		{
			//�������ֵ
			//��gpa��5����ʱ��ȡ�����ֵ
			for (int i = 0; i <= 4; i++)
			{
				ave_gpa = (gpa * 5 - i * 5.0) / (5.0 - i);
				if (ave_gpa <= 4)
				{
					max = ((ave_gpa * 10 + 59) * (5 - i) + i * 100)/5;
					break;
				}
			}
			//������Сֵ
			//��gpa��0���ʱ��ȡ����Сֵ
			for (int i = 4; i >= 0; i--)
			{
				ave_gpa = gpa * 5 / (5.0 - i);
				if (ave_gpa <= 5)
				{
					min = ((ave_gpa * 10 + 50) * (5 - i) + i * 0)/5;
					break;
				}
			}
			pos = (int)((max - min)*5 + 1);
		}
	}
	printf("MinAve:%.1f MaxAve:%.1f PossibleAve:%d", min, max, pos);
	return 0;
}
