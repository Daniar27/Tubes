#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "main.h"

int EditManagement(int a, int opsi){
	if(opsi==1){
		EditRecipient(a);
	}
}

struct Recipient EditRecipient(int a){
	int i;
	system("cls");
	printf("\t%d \t%s \t\t%d-%d-%d\n",B[a].id_re,B[a].nama_re,B[a].ct.day,B[a].ct.month,B[a].ct.year);
	printf("\t=================================");
	printf("\n\tDaftar Barang Yang Diberikan\n");
	printf("\t=================================\n\n");
	printf("\tItem_id\tNama Barang\tJumlah\n");
	for(i=0; i<2; i++){
		printf("\t%d\t%s\t\t%d\n", B[a].item[i].id, B[a].item[i].nama, B[a].item[i].jum);
	}
	system("pause");
}
