#ifndef main_H
#define main_H
int CheckAuth;
int Opsi;
//Stock
typedef struct Stock{
	int id;
	char nama[20];
	int jum;
}Stok[100];

//date
typedef struct Time{
	int day,month,year;
}Date;

//Recipient
typedef struct Recipient{
	int id_re;
	char nama_re[40];
	struct Time ct;
	struct Stock item[2];
}Re[100];

struct Stock A[100];
struct Recipient B[100];

//auth
int auth();

//menu
int MainMenu();
int Help();

//stock management
int ReadStock(int b);
int AddStock(int c, int j);
int EditStock(int c, int j);
int DeleteStock(int c, int j);

//Recipient Management
int RecipientMenu();
void AddRecipient(int x);
int ShowRecipient();
int InfoRecipient(int a);
int DeleteRecipient();
void DestroyReport();


#endif
