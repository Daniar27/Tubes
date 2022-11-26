#include <stdio.h>
#include <stdlib.h>
#include "..\Daniar\main.h"
#include <windows.h>

int MainMenu(){
	system("cls");
	printf("=========================================\n");
	printf("\tAplikasi Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	printf("\t1.Stock Management");
	printf("\n\t2.Recipient Management");
	printf("\n\t3.About");
	printf("\n\tPilih : ");
	scanf("%i",&Opsi);
	return Opsi;
}
