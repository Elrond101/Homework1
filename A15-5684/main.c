/*
* ���ʵ����������ע���ǵ������򣬲�����ĸ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char str[]);//�����������
void print_sym(char symbol[]);//�������
int main()
{
	char str[1000] = {};
	gets(str);
	int len_of_str = strlen(str);
	char word[20] = {};//���浥��
	char symbol[10] = {};//�������
	int sym_tag = 0;//��Ǽ�¼���ŵ�λ��
	int i = 0, j = 0, k = 0, l = 0;
	//����ͷ�ķ���
	if ((!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))))
		{
			for (k = sym_tag; k <= len_of_str; k++)
			{
				sym_tag++;
				if (!((str[k] >= 'a' && str[k] <= 'z') || (str[k] >= 'A' && str[k] <= 'Z')))
				{
					symbol[l] = str[k];
					l++;
					if ((str[k + 1] >= 'a' && str[k + 1] <= 'z') || (str[k + 1] >= 'A' && str[k + 1] <= 'Z'))
					{
						l = 0;
						break;
					}
				}
			}
			print_sym(symbol);
			memset(symbol, 0, sizeof(symbol));
		}
	for(i = len_of_str - 1; i >= 0; i--)
	{
		//�Ӻ���ǰ���浥��
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			word[j] = str[i];
			j++;
		}
		else if(((i == len_of_str - 1 && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) || i != len_of_str - 1) && j != 0)
		{
			//��ǰ���󴢴����
			for (k = sym_tag; k <= len_of_str; k++)
			{
				sym_tag++;
				if (!((str[k] >= 'a' && str[k] <= 'z') || (str[k] >= 'A' && str[k] <= 'Z')) && strlen(word) != 0)
				{
					symbol[l] = str[k];
					l++;
					if ((str[k + 1] >= 'a' && str[k + 1] <= 'z') || (str[k + 1] >= 'A' && str[k + 1] <= 'Z'))
					{
						l = 0;
						break;
					}
				}
			}
			reverse(word);
			print_sym(symbol);
			memset(word, 0, sizeof(word));
			memset(symbol, 0, sizeof(symbol));
			j = 0;
			l = 0;
		}
	}
	//�����β�ĵ��ʼ�����
	for (k = sym_tag; k <= len_of_str; k++)
	{
		sym_tag++;
		if (!((str[k] >= 'a' && str[k] <= 'z') || (str[k] >= 'A' && str[k] <= 'Z')))
		{
			symbol[l] = str[k];
			l++;
			if ((str[k + 1] >= 'a' && str[k + 1] <= 'z') || (str[k + 1] >= 'A' && str[k + 1] <= 'Z'))
			{
				l = 0;
				break;
			}
		}
	}
	reverse(word);
	print_sym(symbol);
	return 0;
}
void reverse(char str[])
{
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
}
void print_sym(char symbol[])
{
	int len = strlen(symbol);
	for (int i = 0; i <= len - 1; i++)
		printf("%c", symbol[i]);
}
