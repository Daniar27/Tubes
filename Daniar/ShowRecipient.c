#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

//Main Show Recipient
int ShowRecipient(){
	FILE *a;
	int j=0;
	int i,opsi, pilih;
	system("cls");
	printf("=========================================\n");
	printf("\tLaporan Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	printf("\tId\tNama Recipient\tTanggal Permintaan\n");
	a=fopen("recipient.txt", "r+");
	do{
		fscanf(a, "%d %s %d %d %d",&B[j].id_re, B[j].nama_re, &B[j].ct.day, &B[j].ct.month, &B[j].ct.year);
		for(i=0;i<2;i++){
			fscanf(a," %d %s %d\n", &B[j].item[i].id, B[j].item[i].nama, &B[j].item[i].jum);
		}
		fscanf(a, "\n");
		printf("\t%d\t%s\t\t%d-%d-%d\n",B[j].id_re,B[j].nama_re,B[j].ct.day,B[j].ct.month,B[j].ct.year);
		j++;
	}while(!feof(a));
	fclose(a);
	printf("\n\t 1. Info\n\t 2. Delete\n\t 0. Back");
	printf("\n\t Pilih : ");
	scanf("%d", &opsi);
	if(opsi==1){
		printf("\tMasukkan id data yang ingin dilihat : ");
		scanf("%d", &pilih);
		InfoRecipient(pilih);
	}
	return 0;
}

//Info Recipient
int InfoRecipient(int a){
	int i,j, opsi;
	system("cls");
	printf("=========================================\n");
	printf("\tManajemen Edit Recipient\n");
	printf("=========================================\n");
	printf("\n");
	printf("\tId\tNama Recipient\tTanggal Permintaan\n\n");
	for(j=0;j<=a;j++){
		if(a==B[j].id_re){
			printf("\t%d \t%s \t\t%d-%d-%d\n",B[j].id_re,B[j].nama_re,B[j].ct.day,B[j].ct.month,B[j].ct.year);
			printf("\t=================================");
			printf("\n\tDaftar Barang Yang Diberikan\n");
			printf("\t=================================\n\n");
			printf("\tItem_id\tNama Barang\tJumlah\n");
			for(i=0; i<2; i++){
				printf("\t%d\t%s\t\t%d\n", B[j].item[i].id, B[j].item[i].nama, B[j].item[i].jum);
			}
			printf("\n\t1.Edit Data Recipient\n\t2.Edit Data Item\n\t0.Back");
			printf("\n\tOpsi : ");
			scanf("%d",&opsi);
			EditManagement(a,opsi);
			return 0;
		}
	}
}
