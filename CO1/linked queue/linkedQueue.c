#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node *front = NULL , *rear = NULL;


void enqueue(){

	int data;
	printf("Enter a number : ");
	scanf("%d",&data);

	struct node *ptr = rear;
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(rear == NULL){
		front = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
		
}

void dequeue(){

	struct node *ptr = front,*temp = front;
	if(temp == NULL)
		printf("Underflow!\n");
	else {
		temp = temp->next;
		front = temp;
		free(ptr);
	}
	
}

void top(){

	struct node *temp = front;

	if(temp == NULL)
		printf("Linked list is empty\n");
	else{
		printf("%d\n",temp->data);

	}

}
void display(){

	struct node *temp = front;

	if(temp == NULL)
		printf("Linked list is empty\n");
	else{
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
	}

}
void main(){

	int choice,data,pos;
	do{

	printf("Enter a choice : \n1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n\n");
	scanf("%d",&choice);

	switch(choice){
		case 1 : {
				 enqueue();
				 break;
			 }
		case 2: {
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
				  printf("Wrong input\n");
			  }
	}
}while(choice != 0 );
}



