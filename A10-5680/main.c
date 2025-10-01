/*
某学生五门课程的成绩均为百分制整数。输入他的GPA，求其加权平均分的可能的范围（即最小值、最大值，保留一位小数），
以及加权平均分的可能分值的数量。假定所有课程的学分均为1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float gpa;
	float max, min;
	int pos;
	float ave_gpa;//除了最大或最小gpa后的平均gpa
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
			//计算最大值
			//当gpa中5最少时，取得最大值
			for (int i = 0; i <= 4; i++)
			{
				ave_gpa = (gpa * 5 - i * 5.0) / (5.0 - i);
				if (ave_gpa <= 4)
				{
					max = ((ave_gpa * 10 + 59) * (5 - i) + i * 100)/5;
					break;
				}
			}
			//计算最小值
			//当gpa中0最多时，取得最小值
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
