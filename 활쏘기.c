#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
void gotoxy(int x, int y);
void intro_game();
void draw_rectangle(int width,int height);
void display_text(int count, int r_count);
void gmae_control(int *r_count, int rnd, char *target);
void horigental_slide(int x,int y, char c2[]);
void horigental_slide2(int x, char c2[]);
void main()
{
	int count = 0, rnd;
	int r_count = 0;
	char *target = "��"; //���ڿ� ����̹Ƿ� �����Ұ��� , �ٲٷ��� ����Ű�� �ּҸ� �ٲ�����Ѵ�.
	srand(time(NULL)); //startrand�� �����Լ��� �ʱⰪ�� ���ϴ� �Լ�, �Ź� �ٲ��� �ϹǷ� time�����

	
	intro_game();

	do{
		system("cls");
		draw_rectangle(20, 20);
		rnd = rand() % 35 + 4; //��ġ
		//rnd = 2;
		gotoxy(rnd, 2);
		printf("%s", target);
		gotoxy(1, 20+4);
		display_text(count,r_count);
		gmae_control(&r_count, rnd, target);

		count++;

	} while (count < 10);
}
void gmae_control(int *r_c, int rnd,char *target){
	char *horse = "��", chr;
	int i = 1, k = 1, y, move = 1;
	int sound;
	do{
		rnd += move;
		i += k;

		if (rnd>38)
			move = -1;
		else if(rnd<3)
			move = 1;

		if (i>33)
			k -= 1;
		else if (i < 3)
			k += 1;
		//i�� ���� ���� k�� +(��)�Ұ����� -(��)�� �Ұ����� ����

		horigental_slide(i + 2, 21, horse);
		horigental_slide2(rnd, target);

	} while (!_kbhit()); //���� ���ö�����

	//����Ű�� �����̽��� Ű�̸� ȭ���� �߻��ϰ� ȭ���� ȭ�鿡 ���������� ǥ��
	//��ǥ���� �¾Ҵ��� Ȯ�� -> �¾����� ��������
	chr = _getch();
	if (chr == 32){
		y = 21;//y��, y�� ������ġ
		while (y > 2){
			y -= 1;
			gotoxy(i + 1, y);
			printf("��");
			Sleep(50);
			printf("\b ");
		}//y>2
		if ((rnd - 1) <= i  &&  i <= (rnd + 1)){
			gotoxy(rnd, 2);
			printf("��");
			sound = calc_frequency(4,7);
			gotoxy(46, 4);
			Beep(sound, 300);
			printf("�¾ҽ��ϴ�!");
			Sleep(50);
			(*r_c)++; //r_count:����Ƚ�� 
		}
		gotoxy(1, 24);
		printf("�ƹ�Ű�� ��������");
		_getch();

	}//if chr==32
}

void horigental_slide(int x, int y, char c2[]){
	gotoxy(x, y);
	printf("\b  ");
	printf("%s", c2);
	Sleep(50);
	printf("\b  ");	
}

void horigental_slide2(int x, char c2[]){
	gotoxy(x,2);
	printf("\b  ");
	printf("%s", c2);
	Sleep(50);
	printf("\b  ");
}

void display_text(int count,int r_count){
	//������ Ƚ��, ������ Ƚ�� ȭ�鿡 ǥ��
	gotoxy(46, 2);
	puts("�����̽��ٸ� ������");
	gotoxy(46, 3);
	puts("ȭ���� �߻�˴ϴ�");
	gotoxy(46, 5);
	printf("Ƚ��: %d\n", count);
	gotoxy(46, 6);
	printf("������ Ƚ��: %d\n", r_count);
	
}

void intro_game(){
	puts("��Ÿ�� ȭ����\n");
	puts("���� Ÿ�� �̵��ϸ鼭");
	puts("��ǥ���� ���ߴ� �����Դϴ�.");
	puts("ȭ���� �����̽�Ű�� �߻��մϴ�.\n");
	puts("�ƹ�Ű�� ������ �����մϴ�.");
	_getch();
}

int calc_frequency(int octave, int inx){
	double do_scale = 32.7032;
	double ratio = (double) pow(2., 1/12.), temp;
	int i;
	temp = do_scale*(double)pow(2, octave - 1);
	for (i = 0; i < inx; i++){
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}

void draw_rectangle(int width, int height){
	unsigned char a = 0xa6, b[7], i;
	for (int i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	//����
	printf("%c%c", a, b[3]);
	for (int i = 0; i < width * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);

	puts("");//�ٹٲ�

	for (int i = 0; i < height; i++){
		printf("%c%c", a, b[2]);
		for (int j = 0; j < width; j++){
			printf("  ");
		}
		printf("%c%c", a, b[2]);
		puts("");
	}

	//�Ʒ���
	printf("%c%c", a, b[6]);
	for (int i = 0; i < width * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);

	puts("");
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
