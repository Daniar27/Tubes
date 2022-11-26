#include <stdio.h>
#include <stdlib.h>
#include "..\Daniar\main.h"
#include <windows.h>

void about(){
	system("cls");
	system("COLOR 6");
	printf("\t===============================\n");
	printf("\tTentang Penggunaan Aplikasi ini\n");
	printf("\t===============================\n");
	printf("\t1. Stock management\n");
	printf(" \t- Admin dapat menambah data stock barang\n\t- struct barang sendiri memiliki id, nama, jumlah\n \t- admin dapat mengedit data stock\n \t- admin dapat delete data stock\n");
	printf("\t2. Recipient management\n");
	printf("\t- admin dapat menambah data recipient\n \t- struct recipient sendiri memiliki id_re, nama_re, time, item\n \t- item sendiri struct bertipe stock disini dibatasi 2 barang\n \t- admin dapat mengosongkan laporan dan menghapus file laporan (perlu validasi password)\n");
	system ("pause");
}

