#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

FILE *file;

int checkUsn,checkPsw,opsi = 0;
char pass[20], password[20],user[20],username[20];
int auth(){
	FILE *file;
	file=fopen("auth.txt", "r");
	fscanf(file, "%s %s", username,password);
	fclose(file);
	
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
	
		
	checkUsn=strcmp(user,username);
	checkPsw=strcmp(pass,password);
	if(checkUsn !=0||checkPsw !=0){
		
		printf("\n\tusername/password yang anda masukkan salah!\n");
		printf("\tPress 1 to Exit\n\tPress number except 1 to continue :");
		scanf("%i", &opsi);
		if(opsi == 1){
			system("cls");
			return CheckAuth;	
		}
		else{
			system("cls");
			goto login;
		}
		
	}
	else{
		CheckAuth=1;
		return CheckAuth;
	}
}
