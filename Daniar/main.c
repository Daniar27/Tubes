#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "main.h"
#include "..\Faisal\MainMenu.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int b,a;
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
			printf("Recipient Menu");
		}
	}
	return 0;
}
