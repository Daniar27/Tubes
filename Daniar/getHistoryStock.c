#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <time.h>

void getHistoryStock(){
	FILE *a, *b;
	printf("\n\tHistory Edit\n");
	int j=0;
	a=fopen("history.txt", "r+");
	if(!a){
		printf("\tHistory Masih Kosong\n");
	}
	else{
		do{
			fscanf(a,"%d %d %d %d %d %s %d\n", &riwayat[j].id, &riwayat[j].waktu.day, &riwayat[j].waktu.month, &riwayat[j].waktu.year, &riwayat[j].id_stock, riwayat[j].stok.nama, &riwayat[j].stok.jum);
			printf("\t%d %d %d id barang : %d; nama barang : %s; jumlah : %d;\n",riwayat[j].waktu.day, riwayat[j].waktu.month, riwayat[j].waktu.year, riwayat[j].id_stock, riwayat[j].stok.nama, riwayat[j].stok.jum);
			j++;
		}while(!feof(a));
	}
	fclose(a);
	printf("\n\t");
	system("pause");
}
