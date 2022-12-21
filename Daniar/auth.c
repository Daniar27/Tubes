#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

FILE *file;

int checkUsn,checkPsw,opsi = 0;

int auth(){
	FILE *file;
	int i=0;
	int j;
	login:
	//Login Activity
	printf("=========================================\n");
	printf("\tAplikasi Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	printf("\tLogin\n");
	printf("\tUsername : ");
	scanf("%s", &user);
	printf("\tPassword : ");
	scanf("%s", &pass);	
	
	file=fopen("auth.txt", "r");
	do{
		fscanf(file, "%s %s\n", Admin[i].username,Admin[i].password);
		i++;
	}while(!feof(file));
	
	fclose(file);
	
	for(j=0;j<=i;j++){
		checkUsn=strcmp(user,Admin[j].username);
		checkPsw=strcmp(pass,Admin[j].password);
		if(checkUsn !=0||checkPsw !=0){
			continue;
		}
		else{
			CheckAuth=1;
			return CheckAuth;
		}
	}
	if(checkUsn !=0||checkPsw !=0){
		printf("\n\tusername/password yang anda masukkan salah!\n");
		printf("\tPress 1 to Continue\n\tPress number except 1 to exit :");
		scanf("%i", &opsi);
		if(opsi != 1){
			system("cls");
			CheckAuth=0;
			return CheckAuth;
		}
		else{
			system("cls");
			goto login;
		}
	}
		
	
	
}
