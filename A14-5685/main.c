/*
* 行程码压缩。行程码（Run-Length Encoding）是一种统计编码，适用于经常出现连续符号的数据压缩，编码规则为：
（1）对2-8个连续出现的相同字符，用一个计数值和该字符来代替。例如aaa******dd表示为3a6*2d
（2）超过8个相同字符时，每次截取8个进行编码，例如??????????? (11个)表示为8?3?
（3）出现单独字符时，以计数值1开头，再列举连续的单独字符，在出现第一个连续相同字符之前以计数值1结尾，例如aaa!$$表示为3a1!12$，aaa!@#$$表示为3a1!@#12$
（4）输出编码结果时，计数值减1后以3位二进制数表示，字符以8位ASCII表示。例如3a6*2d表示为010 0110 0001 101 0010 1010 001 0110 0100，下划线表示计数值。最后按字节输出，
即01001100, 00110100, 10101000, 10110010, 00000000（不足一个字节时末尾补0），十六进制形式为4c34a8b200
输入一个字符串，输出压缩后的十六进制串。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int write_bin(int b[24], int* len, int count);//用于写入重复次数二进制
void ascii_to_binary(unsigned char c, int b[24], int* len);//用于写入字符二进制
void tran_hex(int b[24], FILE* out, int* len);//用于转换为十六进制并写入文件
int main()
{
	FILE* in, * out;
	int count = 0;//统计字符重复出现数量
	int len = 0;//二进制数组长度
	int b[24] = {0};//存储二进制
	char win[5] = { '\0','\0','\0','\0','\0' };//存储当前字符窗口,其中win[2]为当前字符
	char ch;
	in = fopen("A14s.txt", "r");
	out = fopen("A14t.txt", "w");
	win[2] = fgetc(in);
	if((ch = fgetc(in)) == EOF)//处理只有一个字符的情况
	{
		write_bin(b, &len, 1);
		ascii_to_binary(win[2], b, &len);
		write_bin(b, &len, 1);
		len = 8 - len % 8 + len;
		tran_hex(b, out, &len);//转换为十六进制并写入文件
		fclose(in);
		fclose(out);
		return 0;
	}
	else
	win[3] = ch;
	while (1)
	{
		if ((ch = fgetc(in)) != EOF)//读入下一个字符，若到达文件末尾，处理最后的字符
			win[4] = ch;
		else
			win[4] = '\0';
		if (win[2] == win[3])
		{
			
			count++;
			if (count == 7)//达到8个相同字符，输出编码
			{
				count++;
				write_bin(b, &len, count);
				ascii_to_binary(win[2], b, &len);
				win[0] = win[1];
				win[1] = win[2];
				win[2] = win[3];
				win[3] = win[4];//窗口后移
				if((ch = fgetc(in)) != EOF)//读入下一个字符，若到达文件末尾，处理最后的字符
					win[4] = ch;
				else
					win[4] = '\0';
				count = 0;
			}
		}
		else if (count > 0 && ( win[2] != win[3] ))//出现不同字符，输出编码
		{
			count++;
			write_bin(b, &len, count);
			ascii_to_binary(win[2], b, &len);
			count = 0;
		}
		else if (count == 0 && (win[2] != win[3]))//出现单独字符，输出编码
		{
			if (win[0] == win[1])
			{
				write_bin(b, &len, 1);//输出单个字符开头的1
			}
			ascii_to_binary(win[2], b, &len);
			if(win[3] == win[4])
				write_bin(b, &len, 1);//输出单个字符结尾的1
		}
		win[0] = win[1];
		win[1] = win[2];
		win[2] = win[3];
		win[3] = win[4];//窗口后移
		if (win[2] == '\0')
			break;
		tran_hex(b, out, &len);//转换为十六进制并写入文件

	}
	len = 8 - len % 8 + len;
	tran_hex(b, out, &len);//转换为十六进制并写入文件
	fclose(in);
	fclose(out);
	return 0;
}

int write_bin(int b[24], int* len, int count)
{
	switch (count)
	{
	case 0:
		return 0;
	case 1:
		b[*len] = 0;
		b[*len + 1] = 0;
		b[*len + 2] = 0;
		break;
	case 2:
		b[*len] = 0;
		b[*len + 1] = 0;
		b[*len + 2] = 1;
		break;
	case 3:
		b[*len] = 0;
		b[*len + 1] = 1;
		b[*len + 2] = 0;
		break;
	case 4:
		b[*len] = 0;
		b[*len + 1] = 1;
		b[*len + 2] = 1;
		break;
	case 5:
		b[*len] = 1;
		b[*len + 1] = 0;
		b[*len + 2] = 0;
		break;
	case 6:
		b[*len] = 1;
		b[*len + 1] = 0;
		b[*len + 2] = 1;
		break;
	case 7:
		b[*len] = 1;
		b[*len + 1] = 1;
		b[*len + 2] = 0;
		break;
	case 8:
		b[*len] = 1;
		b[*len + 1] = 1;
		b[*len + 2] = 1;
	default:
		break;
	}
	*len += 3;
	return 0;
}
void ascii_to_binary(unsigned char c, int b[24], int* len) 
{
	for (int i = 7; i >= 0; i--) {
		b[7 - i + *len] = (c >> i) & 1;
	}
	*len += 8;
}
void tran_hex(int b[24], FILE* out, int* len) {
	char hex_map[] = "0123456789abcdef";
	int total_bits = *len;
	int processed_bits = 0;
	int byte_value = 0;
	int bit_count = 0;

	// 处理所有完整的8位组（一个字节）
	for (int i = 0; i <= total_bits - 8; i += 8) {
		byte_value = 0;
		// 将8个位组合成一个字节
		for (int j = 0; j < 8; j++) {
			byte_value = (byte_value << 1) | b[i + j];
		}
		// 输出字节的十六进制形式（两位）
		fputc(hex_map[(byte_value >> 4) & 0x0F], out); // 高4位
		fputc(hex_map[byte_value & 0x0F], out);        // 低4位
		processed_bits += 8;
	}

	// 将未处理的位移动到数组前端
	int remaining_bits = total_bits - processed_bits;
	if (remaining_bits > 0) {
		for (int i = 0; i < remaining_bits; i++) 
		{
			b[i] = b[processed_bits + i];
		}
	}
	for(int i = remaining_bits; i < 24; i++) // 清除多余位
	{
		b[i] = 0;
	}
	// 更新len为剩余未处理的位数
	*len = remaining_bits;
}
