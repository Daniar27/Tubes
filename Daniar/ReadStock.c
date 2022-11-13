#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"

//read stock
int ReadStock(int b){
	FILE *a;
	int pilih;
	int j=0;
	int c=0;

	system("cls");
	printf("=========================================\n");
	printf("\tAplikasi Manajemen Inventory\n");
	printf("=========================================\n");
	printf("\n");
	printf("\tId\tNama Barang\tJumlah\n");
	a=fopen("stock.txt", "r");
	do{
		fscanf(a, "%d %s %d",&A[j].id, A[j].nama, &A[j].jum," \n");
		printf("\t%d\t%s\t\t%d\n",A[j].id, A[j].nama, A[j].jum);
		j++;
	}while(!feof(a));
	fclose(a);
	printf("\n\n");
	printf("\tPilih\n\t1.Add Stock\n\t2.Edit Stock\n\t3.Delete Stock\n");
	printf("\n\tPilihan Anda (1-3)\n\t(0) untuk kembali ke menu utama : ");
	scanf("%d", &pilih);	
	if(pilih==0){
		return b;
	}
	else if(pilih==1){
		AddStock(c,j);
		if(c==0){
			return b;
		}
	}
	else if(pilih==2){
		EditStock(c,j);
		if(c==0){
			return b;
		}
	}
	else if(pilih==3){
		DeleteStock(c,j);
		if(c==0){
			return b;
		}
	}
}

//Create Stock
int AddStock(int c,int j){
	FILE *a;
	system("cls");
	A[j].id=j;
	printf("\n\tMasukkan Nama Barang : ");
	scanf("%s", &A[j].nama);
	printf("\tMasukkan Jumlah Barang : ");
	scanf("%d", &A[j].jum);
	a=fopen("stock.txt","a");
	fprintf(a,"\n%d %s %d", A[j].id, A[j].nama, A[j].jum);
	fclose(a);
	return c;
}

//Edit Stock
int EditStock(int c, int j){
	FILE *a;
	int id,i;
	int k=0;
	printf("\n\tMasukkan id barang yang ingin di edit : ");
	scanf("%d", &id);
	for(i=0;i<=id;i++){
		if(id==A[i].id){
			system("cls");
			printf("\t%d\t%s\t\t%d\n",A[i].id, A[i].nama, A[i].jum);
			printf("\t\n Masukkan Nama Barang yang baru : ");
			scanf("%s", &A[i].nama);
			printf("\t\n Masukkan Jumlah Barang yang baru : ");
			scanf("%d", &A[i].jum);
			a=fopen("stock.txt","w");
			do{
				fprintf(a,"%d %s %d", A[k].id, A[k].nama, A[k].jum);
				k++;
				if(k<=j-1){
					fprintf(a,"\n");
				}
			}while(k<=j-1);
			fclose(a);
		}
		else{
			continue;
		}
	}
	return c;
}

//Delete Stock
DeleteStock(int c, int j){
	FILE *a;
	int id,i;
	int k=0;
	int l=0;
	printf("\n\tMasukkan id barang yang ingin dihapus : ");
	scanf("%d",&id);
	if(id < 0 || id > j){
        printf("Invalid position! Please enter position between 1 to %d", j);
    }
    else{
    	for(i=id; i<j; i++)
        {
            for(l=0;l<20;l++){
            	A[i].nama[l]=A[i+1].nama[l];
			}
            A[i].jum = A[i+1].jum;
        }
        j--;
        a=fopen("stock.txt","w");
		do{
			fprintf(a,"%d %s %d", A[k].id, A[k].nama, A[k].jum);
			k++;
			if(k<=j-1){
				fprintf(a,"\n");
			}
		}while(k<=j-1);
		fclose(a);
	}
}

