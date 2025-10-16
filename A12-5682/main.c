/*
* ����N��int�������������ǰ��մ�С�����˳���Ų���ʾ����0 �� N �� 1000)
Ҫ��1�����ݴ����һ�������С�ÿ����һ�����ݣ����������뵽�����У���ά������������ԡ�
Ҫ��2��������������������ʾ����Ȳ���Ӧʹ�õ����ĺ������
Ҫ��3���밴�տα�������ʹ��ָ����нڵ�֮������ӣ�����̬����/�ͷ��ڴ档
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int num;
	struct node* next;
};
struct node* insert_List(struct node* head, struct node* rear, struct node* q)
{
	struct node* p;
	if (!head)
	{
		q->next = NULL;
		head = q;
		rear = q;
		return head;
	}
	if(head->num >= q->num)
	{
		q->next = head;
		head = q;
		return head;
	}
	p = head;
	while (p->next && p->next->num < q->num)
		p = p->next;
	q->next = p->next;
	p->next = q;
	return head;
};
struct node *delete_List(struct node* head)
{
	struct node* p;
	while (head)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return head;
};
void print_List(struct node* head)
{
	struct node* p = head;
	while (p)
	{
		printf("%d\n", p->num);
		p = p->next;
	}
	printf("\n");
};
int main()
{
	int N, num;
	struct node* head = NULL, * rear = NULL, * p;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		p = (struct node*)malloc(sizeof(struct node));
		p->num = num;
		head = insert_List(head, rear, p);
	}
	print_List(head);
	delete_List(head);
	return 0;
}
