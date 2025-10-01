/*
����һ��5���Ƶ����ͣ������õ����͡�
�������ֻ�ɫ��Diamonds��Clubs��Hearts��Spades����ʮ�����ȼ���2��3��4��5��6��7��8��9��10��J��Q��K��A����
A�ȿ���Ϊ���ȼ���Ҳ����Ϊ��С�ȼ�������ʱ����ɫ�ô�д����ĸ��ʾ���ȼ������ֻ���ĸ��ʾ��10��T��ʾ����
���зǷ����룬ֱ�Ӷ������ɣ�ֱ������Ϊ 0 ʱ���������ܹ��ĺϷ�����ᱣ֤Ϊ5���ơ�
�������ظ�������������һ��������Ϊ0���������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Card
{
	char suit; // ��ɫ
	char rank; // �ȼ�
	int rank_num; // �ȼ���Ӧ������
};
void set_rank_num(struct Card* card);
int main()
{
	struct Card hand[5];
	int i;
	int pairs = 0, three_of_a_kind = 0, four_of_a_kind = 0, straight = 0, flush = 0;
	for (i = 0; i < 5; i++)
	{
		char suit, rank;
		if (scanf(" %c%c", &suit, &rank) != 2 || (suit != 'D' && suit != 'C' && suit != 'H' && suit != 'S') ||
			(rank != '2' && rank != '3' && rank != '4' && rank != '5' && rank != '6' && rank != '7' && rank != '8' &&
			 rank != '9' && rank != 'T' && rank != 'J' && rank != 'Q' && rank != 'K' && rank != 'A'))
		{
			if (i == '0' && suit == '0')
				return 0; // ��������
			i--; // �����Ƿ�����
			continue;
		}
		int j;
		for (j = 0; j < i; j++)
		{
			if (hand[j].suit == suit && hand[j].rank == rank)
				break; // �ظ��ƣ�����
		}
		if (j < i)
		{
			i--;
			continue;
		}
		hand[i].suit = suit;
		hand[i].rank = rank;
	}
	for (i = 0; i < 5; i++)
		set_rank_num(&hand[i]);
	//�ж��Ƿ���ͬ��
	if(hand[0].suit==hand[1].suit&&hand[0].suit==hand[2].suit&&hand[0].suit==hand[3].suit&&hand[0].suit==hand[4].suit)
		flush = 1;
	//�ж��Ƿ���˳��
	if((abs(hand[0].rank_num - hand[1].rank_num) == 4 && abs(hand[0].rank_num - hand[1].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[2].rank_num) == 4 && abs(hand[0].rank_num - hand[2].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[3].rank_num) == 4 && abs(hand[0].rank_num - hand[3].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[4].rank_num) == 4 && abs(hand[0].rank_num - hand[4].rank_num) <= 4))
		straight = 1;
	//A��1�����
	if(hand[0].rank_num==14||(hand[1].rank_num==14)||(hand[2].rank_num==14)||(hand[3].rank_num==14)||(hand[4].rank_num==14))
	{
		if((abs(1 - hand[0].rank_num) == 4 && abs(1 - hand[0].rank_num) <= 4 ||
		   abs(1 - hand[1].rank_num) == 4 && abs(1 - hand[1].rank_num) <= 4 ||
		   abs(1 - hand[2].rank_num) == 4 && abs(1 - hand[2].rank_num) <= 4 ||
		   abs(1 - hand[3].rank_num) == 4 && abs(1 - hand[3].rank_num) <= 4 ||
		   abs(1 - hand[4].rank_num) == 4 && abs(1 - hand[4].rank_num) <= 4))
			straight = 1;
	}
	//�ж��Ƿ�������,�����Լ���������
	for (i = 0; i < 5; i++)
	{
		int count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (hand[i].rank == hand[j].rank)
			count++;
		}

		if (count == 4)
			four_of_a_kind = 1;
		else if (count == 3)
			three_of_a_kind = 1;
		else if (count == 2)
			pairs++;
	}
	pairs /= 2; // ÿ��ֻ��һ��
	//�ж�����
	if (straight && flush)
		printf("straight flush\n");
	else if (four_of_a_kind)
		printf("four of a kind\n");
	else if (three_of_a_kind && pairs == 1)
		printf("full house\n");
	else if (flush)
		printf("flush\n");
	else if (straight)
		printf("straight\n");
	else if (three_of_a_kind)
		printf("three of a kind\n");
	else if (pairs == 2)
		printf("two pairs\n");
	else if (pairs == 1)
		printf("one pair\n");
	else
		printf("high card\n");
}
// �����Ƶĵȼ���Ӧ������
void set_rank_num(struct Card* card)
{
	if (card->rank >= '2' && card->rank <= '9')
		card->rank_num = card->rank - '0';
	else if (card->rank == 'T')
		card->rank_num = 10;
	else if (card->rank == 'J')
		card->rank_num = 11;
	else if (card->rank == 'Q')
		card->rank_num = 12;
	else if (card->rank == 'K')
		card->rank_num = 13;
	else if (card->rank == 'A')
		card->rank_num = 14;
}