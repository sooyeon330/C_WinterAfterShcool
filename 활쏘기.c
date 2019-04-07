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
	char *target = "♡"; //문자열 상수이므로 수정불가능 , 바꾸려면 가리키는 주소를 바꿔줘야한다.
	srand(time(NULL)); //startrand로 랜덤함수의 초기값을 정하는 함수, 매번 바뀌어야 하므로 time사용함

	
	intro_game();

	do{
		system("cls");
		draw_rectangle(20, 20);
		rnd = rand() % 35 + 4; //위치
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
	char *horse = "▲", chr;
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
		//i의 값에 따라 k로 +(우)할것인지 -(좌)로 할것인지 결정

		horigental_slide(i + 2, 21, horse);
		horigental_slide2(rnd, target);

	} while (!_kbhit()); //값이 들어올때까지

	//누른키가 스페이스바 키이면 화살을 발사하고 화살을 화면에 연속적으로 표시
	//목표물이 맞았는지 확인 -> 맞았으면 개수증가
	chr = _getch();
	if (chr == 32){
		y = 21;//y축, y의 현재위치
		while (y > 2){
			y -= 1;
			gotoxy(i + 1, y);
			printf("↑");
			Sleep(50);
			printf("\b ");
		}//y>2
		if ((rnd - 1) <= i  &&  i <= (rnd + 1)){
			gotoxy(rnd, 2);
			printf("☆");
			sound = calc_frequency(4,7);
			gotoxy(46, 4);
			Beep(sound, 300);
			printf("맞았습니다!");
			Sleep(50);
			(*r_c)++; //r_count:맞춘횟수 
		}
		gotoxy(1, 24);
		printf("아무키나 누르세요");
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
	//시행한 횟수, 성공한 횟수 화면에 표시
	gotoxy(46, 2);
	puts("스페이스바를 누르면");
	gotoxy(46, 3);
	puts("화살이 발사됩니다");
	gotoxy(46, 5);
	printf("횟수: %d\n", count);
	gotoxy(46, 6);
	printf("성공한 횟수: %d\n", r_count);
	
}

void intro_game(){
	puts("말타며 화살쏘기\n");
	puts("말을 타고 이동하면서");
	puts("목표물을 맞추는 게임입니다.");
	puts("화살은 스페이스키로 발사합니다.\n");
	puts("아무키나 누르면 시작합니다.");
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

	//윗줄
	printf("%c%c", a, b[3]);
	for (int i = 0; i < width * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);

	puts("");//줄바꿈

	for (int i = 0; i < height; i++){
		printf("%c%c", a, b[2]);
		for (int j = 0; j < width; j++){
			printf("  ");
		}
		printf("%c%c", a, b[2]);
		puts("");
	}

	//아랫줄
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
