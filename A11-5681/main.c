//����һ���ַ����������ַ����Ƿ��ǡ����ġ����ַ�������<100�����ܰ����ո�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int tag = 1;//��־�Ƿ�Ϊ��������
	char str[100];
	gets(str);
    // ����ָ�룺p1ָ���ַ�����ͷ��p2ָ���ַ���ĩβ
    char* p1 = str;
    char* p2 = str;
    while (*p2 != '\0') {
        p2++;
    }
    p2--; //��p2ָ�����һ����Ч�ַ�
 //�Ƚ�ָ��ָ����ַ��������м��ƶ�ָ��
    while (p1 < p2) {
        if (*p1 != *p2) {
            tag = 0;
            break;
        }
        p1++;
        p2--;
    }
	if (tag)
		printf("Yes");
	else
		printf("No");
	return 0;
}
