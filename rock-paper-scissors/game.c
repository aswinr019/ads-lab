#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char options[3][9] = { "Rock", "Paper", "Scissors" };

int generateComputerChoice(void){


	int random;
	//seeding 
	srand( time(NULL) );
	random = (rand() % 3 )+1;
	return random ;
}

void  printChoices(int uChoice , int cChoice){


	if ( uChoice == 0 )
		return;

	// printf("Your choice : ");
	//  if ( uChoice == 1 )
	// 	 printf("Rock\n");
	//  else if ( uChoice == 2 )
	// 	 printf("Paper\n");
	//  else if ( uChoice == 3 )
	// 	 printf("Scissors\n");
	//  printf("Computer choice : ");
	//   if( cChoice == 1 )
	// 	  printf("Rock\n");
	//   else if ( cChoice == 2 )
	// 	  printf("Paper\n");
	//   else if ( cChoice == 3 )
	// 	  printf("Scissors\n");

	// printf("Your choice  ");
	// printf("%s\n",options[uChoice - 1]);
	// printf("Computer choice  ");
	// printf("%s\n",options[cChoice - 1]);

	printf("Your choice\t\tComputer choice\n");
	printf("-----------\t\t----------------\n");
	printf("%s\t\t\t%s\n\n",options[uChoice - 1],options[cChoice - 1]);


}

void compareChoices(int uChoice , int cChoice){

	if ( uChoice == 0 )
		return;

	  //draw
        else if ( uChoice == cChoice )
                printf("That's a draw\n\n");

        //user choice rock vs computer
        else if ( uChoice == 1 && cChoice == 2)
                printf("You loose!\n\n");
        else if ( uChoice == 1 && cChoice == 3 )
                printf("You won!!\n\n");

        //user choice paper vs computer
        else if ( uChoice == 2 && cChoice == 1 )
                printf("You won!!\n\n");
        else if ( uChoice ==2 && cChoice == 3 )
                printf("You loose\n\n");

        //user choice scissors vs computer
        else if ( uChoice == 3 && cChoice == 1 )
                printf("You loose\n\n");
        else if ( uChoice == 3 && cChoice == 2 )
                printf("You won!!\n\n");
        else {
                printf("%d%d\n",uChoice,cChoice);
                printf("Input error!!!!\n\n");
        }

}
int main(){


	int userChoice , computerChoice;


	do{
		printf("Enter a choice : \n0.Exit\n1.Rock\n2.Paper\n3.Scissors\n\n-> ");
		scanf("%d",&userChoice);

		if( userChoice == 0 || userChoice > 3){
			printf("Exiting....\n");
			exit(0);
		}

		computerChoice = generateComputerChoice();

		printChoices(userChoice,computerChoice);
		
		compareChoices(userChoice,computerChoice);

	}while(userChoice != 0 );

	printf("Exiting...\n");




}
