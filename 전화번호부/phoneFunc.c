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
		printf("더 이상 입력하실수 없습니다.");
	}
	pData = (phoneData*) malloc(sizeof(phoneData));

		printf("이름 입력: ");
		fflush(stdin);
		//gets(data.name);
		gets(pData->name);
		
		printf("번호 입력: ");
		fflush(stdin);
		//gets(data.phoneNum);
		gets(pData->phoneNum);

		for (int i = 0; i < numofData; i++){
			if (!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum)){
				printf("같은 데이터가 이미 있습니다."); free(pData);  getchar(); return;
			}
		}

		phoneList[numofData] = pData;

		numofData++;

		printf("입력이 완료 되었습니다.");
		getchar();

}//입력

void ShowAllData()
{
	int i;
	for (i = 0; i < numofData; i++)
		//ShowPhoneinfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);

	printf("출력이 완료되었습니다.");
	getchar();
}//ALL출력

void SearchPhoneData(){
	//찾고자 하는 사람 이름
	//찾고자 하는 사람 음과 배열에 있는 이름을 비교
	char name[100];
	int searchRe = 0;//찾으면 1 못찾으면 0

	printf("이름 >");
	gets(name);

	for (int i = 0; i < numofData; i++){
		//if (strcmp(name, phoneList[i].name) == 0) ShowPhoneinfo(phoneList[i]);
		if (strcmp(name, phoneList[i]->name) == 0){ ShowPhoneInfoByPtr(phoneList[i]); searchRe = 1; }
	}//for
	if (searchRe == 0)
		printf("데이터가 존재하지 않습니다.");
	else
		printf("검색완료.");

	getchar();
}//검색

void DeletePhoneData(){
	char delname[100];
	int i;
	int idxOfMatchingData[LIST_NUM];//데이터와 매칭되는 데이터를 모아놓은 배열
	int matchedCount = 0;
	int delIdx=0;
	int selection;
	

	printf("이름 >");
	gets(delname);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, delname))
			idxOfMatchingData[matchedCount++] = i;
	}


	if (matchedCount == 0){
		printf("찾는 데이터가 없습니다.");
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
		printf("선택 :");
		scanf("%d", &selection);

		delIdx = idxOfMatchingData[selection - 1];

		for (int j = delIdx; j < numofData - 1; j++){
			phoneList[j] = phoneList[j + 1];
		}
	}
	numofData--;
	printf("성공");
	getchar();
	
/*	
for (i = 0; i < numofData; i++){
		//if (strcmp(name, phoneList[i].name) == 0) ShowPhoneinfo(phoneList[i]);
		if (strcmp(name, phoneList[i]->name) == 0) {  ShowPhoneInfoByPtr(phoneList[i]); }
	}
	printf("삭제하시겠습니까?(y or n) ");
	scanf("%c", &ans);

	if (ans == 'y'){
		for (int j = i; j < numofData-1 ; j++){
			phoneList[j] = phoneList[j + 1];
		}
	}
	numofData--;
	printf("성공");
	getchar();
*/

}//삭제

void EditPhoneData(){//수정
	char editname[100];
	char newnum[100];
	char newname[100];
	int i;
	int idxOfMatchingData[LIST_NUM];//데이터와 매칭되는 데이터를 모아놓은 배열
	int matchedCount = 0;
	int editIdx = 0;
	int selection;


	printf("이름 >");
	gets(editname);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, editname))
			idxOfMatchingData[matchedCount++] = i;
	}


	if (matchedCount == 0){
		printf("찾는 데이터가 없습니다.");
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

		printf("선택 :");
		scanf("%d", &selection);

//		printf("변경할 이름 : ");
//		fflush(stdin);  gets(newname);
		
		printf("변경할 전화번호:");
		fflush(stdin);  gets(newnum);

		editIdx = idxOfMatchingData[selection - 1];
		
		for (int i = 0; i < numofData; i++){
			if (!strcmp(phoneList[i]->name, phoneList[editIdx]->name) && !strcmp(phoneList[i]->phoneNum, newnum)){
				printf("같은 정보가 이미 있습니다.");  getchar(); return;
			}
		}

//		strcpy(phoneList[editIdx]->name, newname);//이름
		strcpy(phoneList[editIdx]->phoneNum, newnum);//번호
	
		ShowPhoneInfoByPtr(phoneList[editIdx]);
		printf("변경되었습니다.");
		getchar();
	}//else

	printf("끝"); getchar();

	//한명수정이안댐.....
}

