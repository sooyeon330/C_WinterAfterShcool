#include "common.h"
#include "phoneData.h"

void ShowMenu(){
	system("cls");//ȭ�鿡 ��µȰ͵��� �������

	printf("===========�޴�===========\n");
	printf("1.��ȭ��ȣ �Է�\n");
	printf("2.��ȭ��ȣ ���\n");	
	printf("3.�˻�\n");
	printf("4.����\n");
	printf("5.����\n");
	printf("6.����\n");
	printf("==========================\n");
	
	printf("���� >> ");
}
void ShowPhoneinfo(phoneData phone){
	printf("------------------------------------\n");
	printf(" �� �̸� : %s\n", phone.name);
	printf(" �� ��ȭ��ȣ : %s\n", phone.phoneNum);
	printf("------------------------------------\n\n");
}
void ShowPhoneInfoByPtr(phoneData *pPhone){
	printf("------------------------------------\n");
	printf(" �� �̸� : %s\n", pPhone->name);
	printf(" �� ��ȭ��ȣ : %s\n", pPhone->phoneNum);
	printf("------------------------------------\n\n");
}