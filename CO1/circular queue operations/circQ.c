#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int cq[SIZE];
int rear = -1 , front = -1;

void enqueue(void){

	int data;
	printf("Enter a number to insert : ");
	scanf("%d",&data);

	if((rear+1)%SIZE == front)
		printf("Overflow!\n");
	else if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		cq[rear] = data;
	}
	else {
		rear = (rear+1)%SIZE;
		cq[rear] = data;
	}
}


void dequeue(void){

	int data;
	if(front == -1 && rear == -1 )
		printf("Undeflow!\n\n");
	else if(front == rear){
		
		data = cq[front];
		front = -1;
		rear = -1;
		printf("Dequeued number is %d\n\n",data);
	}
	else {
		data = cq[front];
		front = (front+1)%SIZE;
		printf("Dequeued number is %d\n\n",data);
	}
}

void top(void){

	if(front == -1 && rear == -1)
		printf("Underflow!\n\n");
	else 
		printf("Top number is %d\n\n",cq[front]);
}

void display(void){

	if(front == -1 && rear == -1)
		printf("Underflow!\n\n");
	else{
		for(int i = front ; i <= rear ; i++)
			printf("%d\t",cq[i]);
		printf("\n\n");
	}
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
