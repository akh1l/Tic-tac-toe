/*
   My first mini project: TIC TAC TOE game
   completed on 30th march 2014
   akh1l
 */

#include<stdio.h>
#include<stdlib.h>
#define AND &&      /* macros are used for better understanding of the program, all appearances of AND will be replaced by && and similarly for OR*/
#define OR ||
char pos[10]={"         "};/* 9 spaces are given so that in the beginning each grid has a blank(space)*/
int block,n,turn=0;         /*They are declared globally, so that they are available throughout the execution of the program i.e in all different functions*/
void player1();
void player2();
void check();
void printboard();


int main()
{
	system("clear"); 
	printf("\n");
	printf("      |     |     \n");
	printf("      |     |     \n");
	printf(" _____|_____|_____\n");
	printf("      |     |     \n");
	printf("      |     |     \n");
	printf(" _____|_____|_____\n");
	printf("      |     |     \n");
	printf("      |     |     \n");
	printf("      |     |     \n");
	printf("\nPlayer 1 is 'O' and Player 2 is 'X'\n");
	for(n=0;n<9;n++)   /*It is set to 9 because the maximum number of input is 9.*/
	{
		if(turn%2==0)  /*turn is used to decide who will be playing next.*/
		{
			player1();
			check();
			turn++;
		}
		else
		{
			player2();
			check();
			turn++;
		}
	}
	printf("\n\t\t\t\t\tIt's a TIE\n");
	return 0;
}

void player1()
{
        printf("\nPlayer 1 Enter the block no:");
	scanf("%d",&block);

	if((block>9)||(block<1))
	{
		printf("Invalid block\n");   /* if the block number is invalid, the function calls itself again(recursion) so that same player can enter again.*/
		player1();
	}

	else if(pos[block-1]==' ') /* to check the that the grid has blank space ( if there is 'x' or 'o' already in its place then it cannot be replaced )*/
	{
		pos[block-1]='O';
		printboard();
	}
	else
	{
		printf("invalid block");
		player1();   /*when a value is tried to replace with another then a message is displayed and the function calls itself again(recursion) so that same player can enter.*/
	}

}

void player2()
{
        printf("\nPlayer 2 Enter the block no:");
	scanf("%d",&block);

	if((block>9)||(block<1))
	{
		printf("Invalid block\n");
		player2();
	}

	else if(pos[block-1]==' ')
	{
		pos[block-1]='X';
		printboard();
	}
	else
	{
		printf("invalid block");
		player2();
	}

}


void check() 
{
	if(
			((pos[0]==pos[1]) AND (pos[1]==pos[2]) AND (pos[2]=='O')) OR /* first horizontal line*/
			((pos[3]==pos[4]) AND (pos[4]==pos[5]) AND (pos[5]=='O')) OR /* second horizontal line*/
			((pos[6]==pos[7]) AND (pos[7]==pos[8]) AND (pos[8]=='O')) OR /* third horizontal line*/
			((pos[0]==pos[3]) AND (pos[3]==pos[6]) AND (pos[6]=='O')) OR /* first vertical line*/
			((pos[1]==pos[4]) AND (pos[4]==pos[7]) AND (pos[7]=='O')) OR /* second vertical line*/
			((pos[2]==pos[5]) AND (pos[5]==pos[8]) AND (pos[8]=='O')) OR /* third vertical line*/
			((pos[0]==pos[4]) AND (pos[4]==pos[8]) AND (pos[8]=='O')) OR /* top left to bottom right (diagonal)*/
			((pos[2]==pos[4]) AND (pos[4]==pos[6]) AND (pos[6]=='O'))    /* top right to bottom left (diagonal)*/
	  )
	{
		printf("\n\t\t\t\t\tPLAYER 1 WON\n");
		exit(0);
	}
	else
		if(
				((pos[0]==pos[1]) AND (pos[1]==pos[2]) AND (pos[2]=='X')) OR /* first horizontal line*/
				((pos[3]==pos[4]) AND (pos[4]==pos[5]) AND (pos[5]=='X')) OR /* second horizontal line*/
				((pos[6]==pos[7]) AND (pos[7]==pos[8]) AND (pos[8]=='X')) OR /* third horizontal line*/
				((pos[0]==pos[3]) AND (pos[3]==pos[6]) AND (pos[6]=='X')) OR /* first vertical line*/
				((pos[1]==pos[4]) AND (pos[4]==pos[7]) AND (pos[7]=='X')) OR /* second vertical line*/
				((pos[2]==pos[5]) AND (pos[5]==pos[8]) AND (pos[8]=='X')) OR /* third vertical line*/
				((pos[0]==pos[4]) AND (pos[4]==pos[8]) AND (pos[8]=='X')) OR /* top left to bottom right (diagonal)*/
				((pos[2]==pos[4]) AND (pos[4]==pos[6]) AND (pos[6]=='X'))    /* top right to bottom left (diagonal)*/
		  )
		{
			printf("\n\t\t\t\t\tPLAYER 2 WON\n");
			exit(0);
		}
}
void printboard()
{
	system("clear"); /*Used to clear the screen, In windows OS replace "clear" by "cls" */
	printf("\n");
	printf("      |     |     \n");
	printf("   %c  |  %c  |  %c \n",pos[0],pos[1],pos[2]);
	printf(" _____|_____|_____\n");
	printf("      |     |     \n");
	printf("   %c  |  %c  |  %c \n",pos[3],pos[4],pos[5]);
	printf(" _____|_____|_____\n");
	printf("      |     |    \n");
	printf("   %c  |  %c  |  %c \n",pos[6],pos[7],pos[8]);
	printf("      |     |     \n");
}
