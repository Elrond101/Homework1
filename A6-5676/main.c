//��֪1600��1��1������������̼���A��B��C�յ���������1��7�����ԷǷ�����Ӧ������1600 �� Y �� 2100)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_Valid(int year, int month, int day);// �ж������Ƿ�Ϸ�
int main()
{
	int year, month, day;
	int diff_year, diff_month, diff_day, diff_sum;// ��1600��1��1�յĲ�ֵ
	int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d,%d,%d", &year, &month, &day);
	if (!is_Valid(year, month, day))
	{
		printf("Invalid");
	}
	else
	{
		diff_year = year - 1600;
		diff_month = month - 1;
		diff_day = day - 1;
		diff_sum = diff_year * 365 + (diff_year + 3)/ 4 - (diff_year + 99)/ 100 + (diff_year + 399)/ 400;
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			days_in_month[1] = 29; // ����
		for (int i = 0; i < diff_month; i++)
		{
			diff_sum += days_in_month[i];
		}
		diff_sum += diff_day;
		printf("%d", (diff_sum + 5) % 7 + 1);
	}
	return 0;
}
int is_Valid(int year, int month, int day)
{
	if (year < 1600 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
		return 0;
	int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		days_in_month[1] = 29; // ����
	if (day > days_in_month[month - 1])
		return 0;
	return 1;
}