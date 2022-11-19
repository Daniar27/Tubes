#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "main.h"

void AddRecipient(){
	int j=0;
	int id1, id2, i, k, l, juml;
	
	FILE *a;
	FILE *b;
	FILE *c;
	FILE *d;
	
	system("cls");
	printf("=========================================\n");
	printf("\tLaporan Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	a=fopen("recipient.txt", "r");
	do{
		fscanf(a, "%d %s %d %d %d",&B[j].id_re, B[j].nama_re, &B[j].ct.day, &B[j].ct.month, &B[j].ct.year);
		for(i=0;i<2;i++){
			fscanf(a," %d %s %d\n", &B[j].item[i].id, B[j].item[i].nama, &B[j].item[i].jum);
		}
		fscanf(a, "\n");
		j++;
	}while(!feof(a));
	fclose(a);
	printf("\n\tBarang Yang Tersedia\n");
	printf("\tId\tNama Barang\tJumlah\n");
	c=fopen("stock.txt", "r");
	i=0;
	do{
		fscanf(c, "%d %s %d",&A[i].id, A[i].nama, &A[i].jum," \n");
		printf("\t%d\t%s\t\t%d\n",A[i].id, A[i].nama, A[i].jum);
		i++;
	}while(!feof(c));
	fclose(c);
	
	//Get Time Now
	time_t now;
    time(&now);

 	struct tm *local = localtime(&now);
 	B[j].ct.day= local->tm_mday;            // get day of month (1 to 31)
    B[j].ct.month = local->tm_mon + 1;      // get month of year (0 to 11)
    B[j].ct.year = local->tm_year + 1900;   // get year since 1900
 	
 	
	//input user
	B[j].id_re=j;
	printf("\n\tMasukkan Nama Recipient : ");
	scanf("%s", &B[j].nama_re);
	barang1 :
	printf("\n\tMasukkan id Barang ke-1 yang ingin ditambahkan : ");
	scanf("%d",&id1);
	for(k=0;k<=i;k++){
		if(i-1<id1){
			printf("\n\tId Barang Tidak Valid\n\t");
			system("pause");
			goto barang1;
		}else{
			B[j].item[0].id=0;
			for(l=0; l<=20; l++){
				B[j].item[0].nama[l]=A[id1].nama[l];	
			}
			validate1 : 
			printf("\n\tBarang yang anda pilih : %s", A[id1].nama);
			printf("\n\tMasukkan Jumlah Barang : ");
			scanf("%d",&juml);
			//Handle Jumlah
			if(juml>A[id1].jum){
				printf("\n\tJumlah tidak valid atau melebihi Stok\n\t");
				system("pause");
				system("cls");
				goto validate1;
			}else{
				A[id1].jum=A[id1].jum-juml;
				B[j].item[0].jum=juml;
				
			}
		}
		break;
	}
	
	
	barang2 :
	printf("\n\tMasukkan id Barang ke-2 yang ingin ditambahkan : ");
	scanf("%d",&id2);
	for(k=0;k<=i;k++){
		if(i-1<id2){
			printf("\n\tId Barang Tidak Valid\n\t");
			system("pause");
			goto barang2;
		}else{
			B[j].item[1].id=1;
			
			for(l=0; l<=20; l++){
				B[j].item[1].nama[l]=A[id2].nama[l];	
			}
			validate2 : 
			printf("\n\tBarang yang anda pilih : %s", A[id2].nama);
			printf("\n\tMasukkan Jumlah Barang : ");
			//handle Jumlah
			scanf("%d",&juml);
			if(juml>A[id2].jum){
				printf("\n\tJumlah tidak valid atau melebihi Stok\n\t");
				system("pause");
				system("cls");
				goto validate2;
			}else{
				A[id2].jum=A[id2].jum-juml;
				B[j].item[1].jum=juml;
			}
		}
		break;
	}
	
	b=fopen("recipient.txt","a");
	fprintf(b, "\n%d %s %d %d %d",B[j].id_re, B[j].nama_re, B[j].ct.day, B[j].ct.month, B[j].ct.year);
	for(i=0;i<2;i++){
		fprintf(b," %d %s %d", B[j].item[i].id, B[j].item[i].nama, B[j].item[i].jum);
	}
	fclose(b);
	l=0;
	d=fopen("stock.txt","w");
		do{
			fprintf(d,"%d %s %d", A[l].id, A[l].nama, A[l].jum);
			l++;
			if(l<i){
				fprintf(d,"\n");
			}
		}while(l<=i-1);
	fclose(d);
	system("pause");
}
