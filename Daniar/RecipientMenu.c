#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

int RecipientMenu(){
	int b;
	int data=1;
	FILE *a;
	a=fopen("recipient.txt", "r+");
	if(!a){
		data=0;
	}
	fclose(a);
	system("cls");
	printf("=========================================\n");
	printf("\tAplikasi Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	printf("\t1. Add Recipient\n\t2. Show Report Recipient\n\t3. Back To Main Menu\n\tOpsi : ");
	scanf("%d",&b);
	if(b==1){
		AddRecipient(data);
	}
	else if(b==2){
		ShowRecipient();
	}else{
		return 0;
	}
}
