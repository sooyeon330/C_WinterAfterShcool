/*Name: main.c ver1.0
*Content: main 함수
*프로그램 사용자의 입력을 받고 그에 따른 처리를 담당하도록 구성
*Implementation: csy
*
*Last modifided 2018/01/05
*/
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"

enum{ INPUT=1, SHOWALL, SEARCH, DELETE, EDIT, QUIT };
void main()
{
	int inputMenu = 0;

	while (1){
		ShowMenu(); //화면에 메뉴를 표시	
		scanf("%d", &inputMenu);
		fflush(stdin);

		switch (inputMenu){
		case INPUT:
			InputPhoneData();//입력
			break;
		case SHOWALL:
			ShowAllData();//ALL출력
			break;
		case SEARCH:
			SearchPhoneData();//검색
			break;
		case DELETE:
			DeletePhoneData();//삭제
			break;
		case EDIT:
			EditPhoneData();//삭제
			break;
		}//switch
		if (inputMenu == QUIT){ puts("이용해주셔서 감사합니다."); break; }//if
	}

}