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