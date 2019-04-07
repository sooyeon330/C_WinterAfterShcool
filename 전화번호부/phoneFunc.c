#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "phoneData.h"
#include "screenout.h"

#define LIST_NUM 100

int numofData = 0;
//phoneData phoneList[LIST_NUM];
phoneData *phoneList[LIST_NUM];

void InputPhoneData()
{
	//phoneData data;
	phoneData *pData;
	if (numofData >= 100){
		printf("�� �̻� �Է��ϽǼ� �����ϴ�.");
	}
	pData = (phoneData*) malloc(sizeof(phoneData));

		printf("�̸� �Է�: ");
		fflush(stdin);
		//gets(data.name);
		gets(pData->name);
		
		printf("��ȣ �Է�: ");
		fflush(stdin);
		//gets(data.phoneNum);
		gets(pData->phoneNum);

		for (int i = 0; i < numofData; i++){
			if (!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum)){
				printf("���� �����Ͱ� �̹� �ֽ��ϴ�."); free(pData);  getchar(); return;
			}
		}

		phoneList[numofData] = pData;

		numofData++;

		printf("�Է��� �Ϸ� �Ǿ����ϴ�.");
		getchar();

}//�Է�

void ShowAllData()
{
	int i;
	for (i = 0; i < numofData; i++)
		//ShowPhoneinfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);

	printf("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}//ALL���

void SearchPhoneData(){
	//ã���� �ϴ� ��� �̸�
	//ã���� �ϴ� ��� ���� �迭�� �ִ� �̸��� ��
	char name[100];
	int searchRe = 0;//ã���� 1 ��ã���� 0

	printf("�̸� >");
	gets(name);

	for (int i = 0; i < numofData; i++){
		//if (strcmp(name, phoneList[i].name) == 0) ShowPhoneinfo(phoneList[i]);
		if (strcmp(name, phoneList[i]->name) == 0){ ShowPhoneInfoByPtr(phoneList[i]); searchRe = 1; }
	}//for
	if (searchRe == 0)
		printf("�����Ͱ� �������� �ʽ��ϴ�.");
	else
		printf("�˻��Ϸ�.");

	getchar();
}//�˻�

void DeletePhoneData(){
	char delname[100];
	int i;
	int idxOfMatchingData[LIST_NUM];//�����Ϳ� ��Ī�Ǵ� �����͸� ��Ƴ��� �迭
	int matchedCount = 0;
	int delIdx=0;
	int selection;
	

	printf("�̸� >");
	gets(delname);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, delname))
			idxOfMatchingData[matchedCount++] = i;
	}


	if (matchedCount == 0){
		printf("ã�� �����Ͱ� �����ϴ�.");
		getchar(); return;
	}
	else if (matchedCount == 1){
		delIdx = idxOfMatchingData[0];
	}
	else{
		for (i = 0; i < matchedCount; i++){
			printf("NUM. %d\n", i+1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}
		printf("���� :");
		scanf("%d", &selection);

		delIdx = idxOfMatchingData[selection - 1];

		for (int j = delIdx; j < numofData - 1; j++){
			phoneList[j] = phoneList[j + 1];
		}
	}
	numofData--;
	printf("����");
	getchar();
	
/*	
for (i = 0; i < numofData; i++){
		//if (strcmp(name, phoneList[i].name) == 0) ShowPhoneinfo(phoneList[i]);
		if (strcmp(name, phoneList[i]->name) == 0) {  ShowPhoneInfoByPtr(phoneList[i]); }
	}
	printf("�����Ͻðڽ��ϱ�?(y or n) ");
	scanf("%c", &ans);

	if (ans == 'y'){
		for (int j = i; j < numofData-1 ; j++){
			phoneList[j] = phoneList[j + 1];
		}
	}
	numofData--;
	printf("����");
	getchar();
*/

}//����

void EditPhoneData(){//����
	char editname[100];
	char newnum[100];
	char newname[100];
	int i;
	int idxOfMatchingData[LIST_NUM];//�����Ϳ� ��Ī�Ǵ� �����͸� ��Ƴ��� �迭
	int matchedCount = 0;
	int editIdx = 0;
	int selection;


	printf("�̸� >");
	gets(editname);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, editname))
			idxOfMatchingData[matchedCount++] = i;
	}


	if (matchedCount == 0){
		printf("ã�� �����Ͱ� �����ϴ�.");
		getchar(); return;
	}
	else if (matchedCount == 1){
		editIdx = idxOfMatchingData[0];
	}
	else{
		for (i = 0; i < matchedCount; i++){
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		printf("���� :");
		scanf("%d", &selection);

//		printf("������ �̸� : ");
//		fflush(stdin);  gets(newname);
		
		printf("������ ��ȭ��ȣ:");
		fflush(stdin);  gets(newnum);

		editIdx = idxOfMatchingData[selection - 1];
		
		for (int i = 0; i < numofData; i++){
			if (!strcmp(phoneList[i]->name, phoneList[editIdx]->name) && !strcmp(phoneList[i]->phoneNum, newnum)){
				printf("���� ������ �̹� �ֽ��ϴ�.");  getchar(); return;
			}
		}

//		strcpy(phoneList[editIdx]->name, newname);//�̸�
		strcpy(phoneList[editIdx]->phoneNum, newnum);//��ȣ
	
		ShowPhoneInfoByPtr(phoneList[editIdx]);
		printf("����Ǿ����ϴ�.");
		getchar();
	}//else

	printf("��"); getchar();

	//�Ѹ�����̾ȴ�.....
}

