#include <stdio.h>
#include "main.h"

void register_admin(){
	FILE *file;
	char user[20], pass[20];
	
	printf("\tRegister Menu\n");
	printf("\n\tUsername : ");
	scanf("%s",user);
	printf("\n\tPassword : ");
	scanf("%s",pass);
	file=fopen("auth.txt", "a");
	fprintf(file,"\n%s %s",user, pass);
	fclose(file);
	
}

