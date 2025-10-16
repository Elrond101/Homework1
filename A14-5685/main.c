/*
* �г���ѹ�����г��루Run-Length Encoding����һ��ͳ�Ʊ��룬�����ھ��������������ŵ�����ѹ�����������Ϊ��
��1����2-8���������ֵ���ͬ�ַ�����һ������ֵ�͸��ַ������档����aaa******dd��ʾΪ3a6*2d
��2������8����ͬ�ַ�ʱ��ÿ�ν�ȡ8�����б��룬����??????????? (11��)��ʾΪ8?3?
��3�����ֵ����ַ�ʱ���Լ���ֵ1��ͷ�����о������ĵ����ַ����ڳ��ֵ�һ��������ͬ�ַ�֮ǰ�Լ���ֵ1��β������aaa!$$��ʾΪ3a1!12$��aaa!@#$$��ʾΪ3a1!@#12$
��4�����������ʱ������ֵ��1����3λ����������ʾ���ַ���8λASCII��ʾ������3a6*2d��ʾΪ010 0110 0001 101 0010 1010 001 0110 0100���»��߱�ʾ����ֵ������ֽ������
��01001100, 00110100, 10101000, 10110010, 00000000������һ���ֽ�ʱĩβ��0����ʮ��������ʽΪ4c34a8b200
����һ���ַ��������ѹ�����ʮ�����ƴ���
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int write_bin(int b[24], int* len, int count);//����д���ظ�����������
void ascii_to_binary(unsigned char c, int b[24], int* len);//����д���ַ�������
void tran_hex(int b[24], FILE* out, int* len);//����ת��Ϊʮ�����Ʋ�д���ļ�
int main()
{
	FILE* in, * out;
	int count = 0;//ͳ���ַ��ظ���������
	int len = 0;//���������鳤��
	int b[24] = {0};//�洢������
	char win[5] = { '\0','\0','\0','\0','\0' };//�洢��ǰ�ַ�����,����win[2]Ϊ��ǰ�ַ�
	char ch;
	in = fopen("A14s.txt", "r");
	out = fopen("A14t.txt", "w");
	win[2] = fgetc(in);
	if((ch = fgetc(in)) == EOF)//����ֻ��һ���ַ������
	{
		write_bin(b, &len, 1);
		ascii_to_binary(win[2], b, &len);
		write_bin(b, &len, 1);
		len = 8 - len % 8 + len;
		tran_hex(b, out, &len);//ת��Ϊʮ�����Ʋ�д���ļ�
		fclose(in);
		fclose(out);
		return 0;
	}
	else
	win[3] = ch;
	while (1)
	{
		if ((ch = fgetc(in)) != EOF)//������һ���ַ����������ļ�ĩβ�����������ַ�
			win[4] = ch;
		else
			win[4] = '\0';
		if (win[2] == win[3])
		{
			
			count++;
			if (count == 7)//�ﵽ8����ͬ�ַ����������
			{
				count++;
				write_bin(b, &len, count);
				ascii_to_binary(win[2], b, &len);
				win[0] = win[1];
				win[1] = win[2];
				win[2] = win[3];
				win[3] = win[4];//���ں���
				if((ch = fgetc(in)) != EOF)//������һ���ַ����������ļ�ĩβ�����������ַ�
					win[4] = ch;
				else
					win[4] = '\0';
				count = 0;
			}
		}
		else if (count > 0 && ( win[2] != win[3] ))//���ֲ�ͬ�ַ����������
		{
			count++;
			write_bin(b, &len, count);
			ascii_to_binary(win[2], b, &len);
			count = 0;
		}
		else if (count == 0 && (win[2] != win[3]))//���ֵ����ַ����������
		{
			if (win[0] == win[1])
			{
				write_bin(b, &len, 1);//��������ַ���ͷ��1
			}
			ascii_to_binary(win[2], b, &len);
			if(win[3] == win[4])
				write_bin(b, &len, 1);//��������ַ���β��1
		}
		win[0] = win[1];
		win[1] = win[2];
		win[2] = win[3];
		win[3] = win[4];//���ں���
		if (win[2] == '\0')
			break;
		tran_hex(b, out, &len);//ת��Ϊʮ�����Ʋ�д���ļ�

	}
	len = 8 - len % 8 + len;
	tran_hex(b, out, &len);//ת��Ϊʮ�����Ʋ�д���ļ�
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

	// ��������������8λ�飨һ���ֽڣ�
	for (int i = 0; i <= total_bits - 8; i += 8) {
		byte_value = 0;
		// ��8��λ��ϳ�һ���ֽ�
		for (int j = 0; j < 8; j++) {
			byte_value = (byte_value << 1) | b[i + j];
		}
		// ����ֽڵ�ʮ��������ʽ����λ��
		fputc(hex_map[(byte_value >> 4) & 0x0F], out); // ��4λ
		fputc(hex_map[byte_value & 0x0F], out);        // ��4λ
		processed_bits += 8;
	}

	// ��δ�����λ�ƶ�������ǰ��
	int remaining_bits = total_bits - processed_bits;
	if (remaining_bits > 0) {
		for (int i = 0; i < remaining_bits; i++) 
		{
			b[i] = b[processed_bits + i];
		}
	}
	for(int i = remaining_bits; i < 24; i++) // �������λ
	{
		b[i] = 0;
	}
	// ����lenΪʣ��δ�����λ��
	*len = remaining_bits;
}
