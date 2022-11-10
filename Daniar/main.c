#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "main.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	auth();
	if(CheckAuth==1){
		printf("Login sukses");
	}
	return 0;
}
