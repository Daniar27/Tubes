#ifndef main_H
#define main_H
int CheckAuth;
int Opsi;
typedef struct Stock{
	int id;
	char nama[20];
	int jum;
}Stok[100];
typedef struct Recipient{
	int id_re;
	char *nama_re;
	struct Stock item[100];
}Re[100];

struct Stock A[100];

//auth
int auth();

//stock management
int MainMenu();
int ReadStock(int b);
int AddStock(int c, int j);
int EditStock(int c, int j);
int DeleteStock(int c, int j);


#endif
