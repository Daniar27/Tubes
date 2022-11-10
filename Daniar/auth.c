#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

FILE *file;

int checkUsn,checkPsw = 0;
char pass[20], password[20],user[20],username[20],ch;
int auth(){
	FILE *file;
	file=fopen("auth.txt", "r");
	fscanf(file, "%s %s", username,password);
	fclose(file);
	
	login:
	//Login Activity
	printf("Login\n");
	printf("Username : ");
	scanf("%s", &user);
	printf("Password : ");
	scanf("%s", &pass);	
		
	checkUsn=strcmp(user,username);
	checkPsw=strcmp(pass,password);
	if(checkUsn !=0||checkPsw !=0){
		
		printf("nusername/password yang anda masukkan salah!\n");
		getch();
		system("cls");
		goto login;
	}
	else{
		CheckAuth=1;
		return CheckAuth;
	}
}
