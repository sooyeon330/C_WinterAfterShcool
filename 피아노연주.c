//������Ÿ�굿�ÿ� ��µǰ��غ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
void touch_keyvoard(int code);
void display_manual();
void practice_piano();
void display_piano_keyboard();
void draw_check02(int width, int height);
int calc_frequency(int octave, int inx);
void gotoxy(int x, int y);

void play_();

void main()
{
	display_manual();
	practice_piano();

	gotoxy(1, 10);
}

void display_manual(){
	puts("Ű������ ���ڸ� ������ �ش�ǹݿ� ���� ǥ�õǰ�");
	puts("�ش� ���� ����Ŀ�� ��µ˴ϴ�");
	puts("�����Ͻ÷��� EscŰ�� ��������.");
}

void practice_piano(){
	int index[] = { 0, 2, 4, 5, 7, 9, 11, 12 };
	int code;
	int freq[8];
	for (int i = 0; i < 8; i++){
		freq[i] = calc_frequency(5, index[i]);
	}

	draw_check02(8, 2);
	display_piano_keyboard();

	do{
		code = _getch();

		if ('1' <= code&&code <= '8')
		{
			code -= 49;
			touch_keyvoard(code);
			Beep(freq[code], 300); //��,�����ð�
			display_piano_keyboard();
		}
	} while (code != 27);
}
void touch_keyvoard(int code)
{
	gotoxy(code * 4 + 3, 7);
	printf("%c%c", 0xa1, 0xe3); //�������� ǥ���� ����

}
void display_piano_keyboard(){
	int i;
	char code[8][4] = { "��", "��", "��", "��", "��", "��", "��", "��" };

	for (i = 0; i < 8; i++){
		gotoxy(i * 4 + 3, 5);
		printf("%2d", i + 1);
	}
	for (i = 0; i < 8; i++){
		gotoxy(i * 4 + 3, 7);
		printf("%s", code[i]);
	}



}


void draw_check02(int width, int height){
	unsigned char a = 0xa6, b[12], i;
	for (int i = 1; i < 12; i++)
		b[i] = 0xa0 + i;

	//����
	printf("%c%c", a, b[3]); //��
	for (int i = 0; i < width - 1; i++){
		printf(" %c%c", a, b[1]); //-
		printf(" %c%c", a, b[8]); //��
	}
	printf(" %c%c", a, b[1]); // ��
	printf(" %c%c", a, b[4]); //��

	puts("");//�ٹٲ�

	//�߰�
	for (int i = 0; i < height - 1; i++){
		printf("%c%c", a, b[2]); //��
		for (int j = 0; j < width; j++){
			printf("   ");
			printf("%c%c", a, b[2]); //��
		}

		puts("");

		printf("%c%c", a, b[7]); //��
		for (int j = 0; j < width - 1; j++){
			printf(" %c%c", a, b[1]); //��
			printf(" %c%c", a, b[11]); //��
		}
		printf(" %c%c", a, b[1]); //��
		printf(" %c%c", a, b[9]); //��

		puts("");
	}


	//�Ʒ���
	printf("%c%c", a, b[2]); //��
	for (int j = 0; j < width; j++){
		printf("   ");
		printf("%c%c", a, b[2]);// ��
	}

	puts("");

	printf("%c%c", a, b[6]); //��
	for (int i = 0; i < width - 1; i++){
		printf(" %c%c", a, b[1]); //��
		printf(" %c%c", a, b[10]); //��
	}
	printf(" %c%c", a, b[1]); //��
	printf(" %c%c", a, b[5]); //��

	puts("");
}
int calc_frequency(int octave, int inx){
	double do_scale = 32.7032;
	double ratio = (double)pow(2., 1 / 12.), temp;
	int i;
	temp = do_scale*(double)pow(2, octave - 1);
	for (i = 0; i < inx; i++){
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}


