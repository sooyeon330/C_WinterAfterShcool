/*Name: main.c ver1.0
*Content: main �Լ�
*���α׷� ������� �Է��� �ް� �׿� ���� ó���� ����ϵ��� ����
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
		ShowMenu(); //ȭ�鿡 �޴��� ǥ��	
		scanf("%d", &inputMenu);
		fflush(stdin);

		switch (inputMenu){
		case INPUT:
			InputPhoneData();//�Է�
			break;
		case SHOWALL:
			ShowAllData();//ALL���
			break;
		case SEARCH:
			SearchPhoneData();//�˻�
			break;
		case DELETE:
			DeletePhoneData();//����
			break;
		case EDIT:
			EditPhoneData();//����
			break;
		}//switch
		if (inputMenu == QUIT){ puts("�̿����ּż� �����մϴ�."); break; }//if
	}

}