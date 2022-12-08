#include<stdio.h>
#define SIZE 10
int cq[SIZE];
int rear = -1 , front = -1;

void enqueue(void){

}

void dequeue(void){

}

void top(void){

}

void display(void){

}

void main(){

	int choice;
	do{
		printf("Enter a choice : \n1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n\n-> ");
		scanf("%d",&choice);

		switch(choice){
			case 0 : {
					 printf("Exitting...\n\n");
					 exit(0);
				 }
			case 1 : {
					 enqueue();
					 break;
				 }
			case 2 : {
					 dequeue();
					 break;
				 }
			case 3 : {
					 top();
					 break;
				 }
			case 4 : {
					 display();
					 break;
				 }
			default : {
					  printf("Wrong input\n\n");
				  }
		}
	}while(choice != 0 );
}
