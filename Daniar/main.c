#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "main.h"
#include "..\Faisal\MainMenu.c"
#include "..\Faisal\about.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int b,a;
	auth:
	system("cls");
	fflush(stdin);
	auth();
	if(CheckAuth==1){
		printf("Login sukses");
		menu :
		a=MainMenu();
		if(a==1){
			b=ReadStock(b);
			if(b==0){
				goto menu;
			}
		}else if(a==2){
			b=RecipientMenu();
			if(b==0){
				goto menu;
			}
		}
		else if(a==3){
			about();
			system("color 07");
			goto menu;
		}
		else if(a==4)
		{
			exit(1);
		}
		else {
			goto auth;
		}
	}
	return 0;
}
