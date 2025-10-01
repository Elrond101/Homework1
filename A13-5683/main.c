/*
分析一手5张牌的牌型，输出最好的牌型。
牌有四种花色（Diamonds、Clubs、Hearts、Spades）和十三个等级（2、3、4、5、6、7、8、9、10、J、Q、K、A），
A既可作为最大等级，也可作为最小等级。输入时，花色用大写首字母表示，等级用数字或字母表示（10用T表示）。
会有非法输入，直接丢弃即可，直到输入为 0 时结束程序，总共的合法输入会保证为5张牌。
若输入重复牌则丢弃，若第一张牌输入为0则结束程序。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Card
{
	char suit; // 花色
	char rank; // 等级
	int rank_num; // 等级对应的数字
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
				return 0; // 结束程序
			i--; // 丢弃非法输入
			continue;
		}
		int j;
		for (j = 0; j < i; j++)
		{
			if (hand[j].suit == suit && hand[j].rank == rank)
				break; // 重复牌，丢弃
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
	//判断是否有同花
	if(hand[0].suit==hand[1].suit&&hand[0].suit==hand[2].suit&&hand[0].suit==hand[3].suit&&hand[0].suit==hand[4].suit)
		flush = 1;
	//判断是否有顺子
	if((abs(hand[0].rank_num - hand[1].rank_num) == 4 && abs(hand[0].rank_num - hand[1].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[2].rank_num) == 4 && abs(hand[0].rank_num - hand[2].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[3].rank_num) == 4 && abs(hand[0].rank_num - hand[3].rank_num) <= 4 ||
	   abs(hand[0].rank_num - hand[4].rank_num) == 4 && abs(hand[0].rank_num - hand[4].rank_num) <= 4))
		straight = 1;
	//A当1的情况
	if(hand[0].rank_num==14||(hand[1].rank_num==14)||(hand[2].rank_num==14)||(hand[3].rank_num==14)||(hand[4].rank_num==14))
	{
		if((abs(1 - hand[0].rank_num) == 4 && abs(1 - hand[0].rank_num) <= 4 ||
		   abs(1 - hand[1].rank_num) == 4 && abs(1 - hand[1].rank_num) <= 4 ||
		   abs(1 - hand[2].rank_num) == 4 && abs(1 - hand[2].rank_num) <= 4 ||
		   abs(1 - hand[3].rank_num) == 4 && abs(1 - hand[3].rank_num) <= 4 ||
		   abs(1 - hand[4].rank_num) == 4 && abs(1 - hand[4].rank_num) <= 4))
			straight = 1;
	}
	//判断是否有四条,三条以及对子数量
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
	pairs /= 2; // 每对只算一次
	//判断牌型
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
// 设置牌的等级对应的数字
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