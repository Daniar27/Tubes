#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "main.h"

void DestroyReport(){
	char validasi;
	char pass[20], password[20];
	int CheckPsw, v, count, r;
	FILE *file;
	FILE *file1;
	printf("\tApakah anda yakin untuk menghapus laporan data recipient(data tidak bisa dipulihkan)(y/n) : ");fflush(stdin);
	scanf("%c",&validasi);
	if(validasi=='y'||validasi=='Y'){
		v=1;
		count=2;
		file = fopen("auth.txt", "r");
		fscanf(file,"  %s",password);
		fclose(file);
		pass :
		printf("\t\tMasukkan Password : ");
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
			r=remove("recipient.txt");
			if(r==0){
				printf("\n\treport berhasil dikosongkan\n\t");
				system("pause");
			}else{
				printf("\n\tDelete gagal\n\t");
				system("pause");
			}
			
		}
	}
}
