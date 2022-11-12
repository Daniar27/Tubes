#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

void ReadStock(){
	FILE *a;
	int j=0;
	system("cls");
	printf("=========================================\n");
	printf("\tAplikasi Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	a=fopen("stock.txt", "r");
	do{
		fscanf(a, "%d %s %d",&A[j].id, A[j].nama, &A[j].jum," \n");	
		printf("\t%d\t%s\t%d\n",A[j].id, A[j].nama, A[j].jum);
		j++;
	}while(!feof(a));
	fclose(a);
	
}
