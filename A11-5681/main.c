//输入一个字符串，检查该字符串是否是“回文”。字符串长度<100，可能包括空格。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int tag = 1;//标志是否为回文序列
	char str[100];
	gets(str);
    // 设置指针：p1指向字符串开头，p2指向字符串末尾
    char* p1 = str;
    char* p2 = str;
    while (*p2 != '\0') {
        p2++;
    }
    p2--; //将p2指向最后一个有效字符
 //比较指针指向的字符，并向中间移动指针
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
