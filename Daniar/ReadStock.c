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
	printf("\tId\tNama Barang\t\tJumlah\n");
	a=fopen("stock.txt", "r");
	do{
		fscanf(a, "%d %s %d",&A[j].id, A[j].nama, &A[j].jum," \n");
		printf("\t%d\t%s\t\t\t%d\n",A[j].id, A[j].nama, A[j].jum);
		j++;
	}while(!feof(a));
	fclose(a);
	printf("\n\n");
	printf("\tPilih\n\t1.Add Stock\n\t2.Edit Stock\n\t3.Delete Stock\n");
	printf("\n\tPilihan Anda (1-3)\n\t(0) untuk kembali ke menu utama : ");
	scanf("%d", &pilih);	
	if(pilih==0){
		return pilih;
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
	char nama[20];
	char validasi[20]="-";
	int id,i,l;
	int k=0;
	printf("\n\tMasukkan id barang yang ingin di edit : ");
	scanf("%d", &id);
	for(i=0;i<=id;i++){
		if(id==A[i].id){
			system("cls");
			printf("\t%d\t%s\t\t%d\n",A[i].id, A[i].nama, A[i].jum);
			printf("\t\n Masukkan Nama Barang yang baru (gunakan - jika tidak ingin mengubah nama barang) : ");
			scanf("%s", &nama);
			if(strcmp(A[i].nama,nama)==0||strcmp(nama, validasi)==0){
			}else{
				snprintf(A[i].nama, sizeof(A[i].nama), "%s", nama);
			}
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
	FILE *file;
	char validasi, password[20], pass[20];
	int id,i,v,count,CheckPsw;
	int k=0;
	int l=0;
	printf("\n\tMasukkan id barang yang ingin dihapus : ");
	scanf("%d",&id);
	fflush(stdin);
	if(id < 0 || id > j){
        printf("\n\tInvalid id! Please enter id between 1 to %d\n", j);
        system("pause");
    }
    else{
    	printf("\tApa anda yakin ingin menghapus data %s ?(y/n) : ", A[id].nama);
    	scanf("%c",&validasi);
    	if(validasi=='y'||validasi=='Y'){
    	v=1;
		count=2;
		file = fopen("auth.txt", "r");
		fscanf(file,"  %s",password);
		fclose(file);
		pass :
		printf("\n\t\tMasukkan Password : ");
		scanf("%s",pass);
		CheckPsw=strcmp(pass,password);
		if(CheckPsw!=0){
			if(v<3){
				printf("\t\tPassword anda salah, tersisa %d kali kesempatan\n\t",count);
				count--;
				v++;
				goto pass;
			}else{
				printf("\t\tAnda telah salah 3 kali dalam input password !!\n\t");
				system("pause");
			}
		}else{
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
			return 0;
			
			}
		}
		else if(validasi=='n'||validasi=='N'){
			return 0;
		}
    	
	}
}
