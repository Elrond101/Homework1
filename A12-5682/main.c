/*
* 读入N个int型整数，将它们按照从小到大的顺序存放并显示。（0 ≤ N ≤ 1000)
要求1：数据存放在一个链表中。每输入一个数据，即将它插入到链表中，并维护链表的有序性。
要求2：建立链表、插入链表，显示链表等操作应使用单独的函数完成
要求3：请按照课本方法，使用指针进行节点之间的链接，并动态分配/释放内存。
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
