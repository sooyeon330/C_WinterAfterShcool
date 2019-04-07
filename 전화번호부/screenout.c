#include "common.h"
#include "phoneData.h"

void ShowMenu(){
	system("cls");//화면에 출력된것들을 모두지움

	printf("===========메뉴===========\n");
	printf("1.전화번호 입력\n");
	printf("2.전화번호 출력\n");	
	printf("3.검색\n");
	printf("4.삭제\n");
	printf("5.수정\n");
	printf("6.종료\n");
	printf("==========================\n");
	
	printf("선택 >> ");
}
void ShowPhoneinfo(phoneData phone){
	printf("------------------------------------\n");
	printf(" ▶ 이름 : %s\n", phone.name);
	printf(" ▶ 전화번호 : %s\n", phone.phoneNum);
	printf("------------------------------------\n\n");
}
void ShowPhoneInfoByPtr(phoneData *pPhone){
	printf("------------------------------------\n");
	printf(" ▶ 이름 : %s\n", pPhone->name);
	printf(" ▶ 전화번호 : %s\n", pPhone->phoneNum);
	printf("------------------------------------\n\n");
}