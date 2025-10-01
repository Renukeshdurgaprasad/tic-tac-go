#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#ifdef _WIN32
#include<windows.h>
#define sleep(ms) Sleep(ms)
#else
#include<unistd.h>
#define sleep(ms) usleep(ms*1000)
#endif
int choice=1;
char box[9]={'1','2','3','4','5','6','7','8','9'};
void winClear(){
	#ifdef _WIN32
	 system("cls");
	#else
	 system("clear");
	#endif
}
void drawboard(){
	winClear();
	printf("\n\t\t\t\tTIC - TAC - TOE \n\n");
	if(choice==1)
	  printf("\t\t\t player 1- 'X'  player 2 -\'O' \n\n");
	else
	  printf("\t\t\t Computer - 'X'  player -\'O' \n\n");
	int i=0;
	printf("\n\t\t\t\t ___ ___ ___");
	for (i=0;i<9;i+=3){
		printf("\n\t\t\t\t|   |   |   |\n");
		printf("\t\t\t\t| %c | %c | %c |\n",box[i],box[i+1],box[i+2]);
		printf("\t\t\t\t|___|___|___|");
	}
	printf("\n");
	 
}