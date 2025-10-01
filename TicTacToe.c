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
int check(){
	int i=0;
	for (i=0;i<9;i+=3){
		if(box[i]==box[i+1] && box[i+1]==box[i+2])
		 return 1;
	}
	for(i=0;i<3;i++){
		if(box[i]==box[i+3] && box[i+3]==box[i+6])
		 return 1;
	}
	if (box[0]==box[4] && box[4]==box[8])
	 return 1;
	if (box[2]==box[4] && box[4]==box[6])
	 return 1;
	for (i=0;i<9;i++)
	 {
	 	if(box[i]!='X' && box[i]!='O')
	 	 return -1;
	 }
	 return 0;
}
int findMove(char s){
	int i;
	for (i=0;i<9;i+=3){
		if(box[i]==s && box[i+1]==s && isdigit( box[i+2]))
		 return i+2;
		if(box[i]==s && box[i+2]==s && isdigit( box[i+1]))
		 return i+1;
		 if(box[i+2]==s && box[i+1]==s && isdigit( box[i]))
		 return i;
	}
	for(i=0;i<3;i++){
		if(box[i]==s && box[i+3]==s && isdigit( box[i+6]))
		 return i+6;
		if(box[i]==s && box[i+6]==s && isdigit( box[i+3]))
		 return i+3;
		 if(box[i+6]==s && box[i+3]==s && isdigit( box[i]))
		 return i;
		
	}
	if(box[0]==s && box[4]==s && isdigit(box[8]))
	 return 8;
	 	if(box[0]==s && box[8]==s && isdigit(box[4]))
	 return 4;
		if(box[8]==s && box[4]==s && isdigit(box[0]))
	 return 0;
	 	if(box[2]==s && box[4]==s && isdigit(box[6]))
	 return 6;
	 	if(box[6]==s && box[4]==s && isdigit(box[2]))
	 return 2;
	 	if(box[2]==s && box[6]==s && isdigit(box[4]))
	 return 4;
	return -1;
}
int ComputerMove(){
	int move=findMove('X');
	if(move!=-1)
	 return move;
	move=findMove('O');
	if (move!=-1)
    return move;
    if (isdigit(box[4]))
     return 4;
    int cor[]={0,2,6,8};
    int count=0,i;
    int arr[4];
    for(i=0;i<4;i++){
    	if (isdigit(box[cor[i]])){
    		arr[count]=cor[i];
    		count+=1;
		}
	}
	if (count!=0)
	 return arr[rand()%count];
	int sid[]={1,3,5,7};
	int arri[4];
	for(i=0;i<4;i++){
    	if (isdigit(box[sid[i]])){
    		arri[count]=sid[i];
    		count+=1;
		}
	}
	return arri[rand()%count];	
}
void playerVSplayer(){
	int player=1,con=1,valid=0;
	int i=0;
	for (i=0;i<9;i++)
	 box[i]=(i+1)+'0';
	while(valid==0){
		printf("\n\tenter the  player 1 or player 2 to start the game (1/2): ");
	scanf("%d",&player);
	if(player==1 || player==2)
	 valid=1;
	 else{
	 	printf("\n\t    enter the valid number(1 or 2)!\n");
	 }
	}
	valid=0;
	
	int status=-1;
	int pos;
	drawboard();
	do{
		player=(player%2)?1:2;
		printf("\n\n\t\t\t  player %d enter your sqaure:",player);
		scanf("%d",&pos);
		if (pos>=1 && pos<=9 && box[pos-1]==(pos+'0'))
		 box[pos-1]= player==1?'X':'O';
		else{
			printf("\n\t\t   invalid  choice player %d enter the valid choice!\n",player);
			getchar();
			getchar();
			continue;
		}
		player++;
		status=check();
		drawboard();
	}while(status==-1);
	printf("\n\t\t\t   ------------------------");
	if (status==1){
		 printf("\n\t\t\t    \aplayer %d is the winner\n",--player);
	}
	else
	 printf("\n\t\t\t\t \aMatch is draw\n");
	printf("\t\t\t   ------------------------\n");
	getchar();
	getchar();
	winClear();

	
}
void playerVScomputer(){
	int status=-1,lastMove;
	int pos;
	drawboard();
	int move=1;
	do{
		printf("\n\t\t\t\t PLAYER MOVE");
	do{
		printf("\n\n\t\t\t     Enter your square : ");
	scanf("%d",&pos);
	if (pos>=1 && pos<=9 && box[pos-1]==(pos+'0')){
		 box[pos-1]='O';
		 move=0;
	}
	 else{
	 	printf("\n\t\t\tinvalid choice.. enter the valid choice !");
	 	move=1;
	 	getchar();
	 	getchar();
	 	
	 }
	  
	}while(move==1);
	status=check();
	drawboard();
	lastMove=1;
	if(status!=-1)
	 break;
	 printf("\n\n\t\t\t\tCOMPUTER MOVE.... ");
	   sleep(3000);
		int comMove=ComputerMove();
		box[comMove]='X';
		status=check();
	drawboard();
		lastMove=2;
	}while(status==-1);
	if(status==1){
		if(lastMove==1)
		 printf("\n\n\t\t\t \aCongratulations ,You Won ..!");
		else
		  printf("\n\n\t\t\t \aComputer Won .., better luck next time !");
	}
	else{
		printf("\n\n\t\t\t \aIt's Draw .., better luck next time !");
	}
	sleep(50);
	getchar();
	getchar();
	winClear();	
	
}
int main(){
	int valid=0;
	do{
		int i;
		for(i=0;i<9;i++)
		 box[i]=(i+1)+'0';
		printf("\n\t\t\t--------------------------------");
   sleep(100);
   printf("\n\t\t\t|  WELCOME TO TIC - TAC - TOE  |");
   sleep(100);
   printf("\n\t\t\t--------------------------------\n");
   sleep(500);
   printf("\n\t\t   1) PLAYER VS PLAYER    2) COMPUTER VS PLAYER \n");
   printf("\n\t\t\t\t    3)  EXIT \n");
   while(valid==0){
   	 printf("\n\t\t\t    Enter your choice:");
   scanf("%d",&choice);
   if(choice==1 || choice==2 || choice==3)
    valid=1;
   else{
   	printf("\nenter the valid choice !\n");
   }
   }
   valid=0;
   winClear();
   if(choice==1)
    playerVSplayer();
   else if (choice==2)
    playerVScomputer();
  else{
  	printf("\n\t\t\t THANK YOU FOR PLAYING THE GAME \n");
  	 printf("\n\t\t\t  EXITING FROM  THE GAME...!\n\n\n");
  }
  	
	}while(choice!=3);
	
}

