#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node* top = NULL;
void push(){

	int data;
	printf("Enter a number : ");
	scanf("%d",&data);

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	temp->next = top;
	top = temp;

}

void pop(){

	struct node *ptr = top,*temp = top;
	if(temp == NULL)
		printf("Underflow!\n");
	else {
		temp = temp->next;
		top = temp;
		free(ptr);
	}
	
}
void topp(){

	struct node *temp = top;

	if(temp == NULL)
		printf("Linked list is empty\n");
	else{
		printf("%d\n",temp->data);

	}

}
void display(){

	struct node *temp = top;

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

	int choice;
	do{

	printf("Enter a choice : \n1.Push\n2.Pop\n3.Top\n4.Display\n\n");
	scanf("%d",&choice);

	switch(choice){
		case 1 : {
				 push();
				 break;
			 }
		case 2: {
				pop();
				break;
			}
				case 3 : {
				 topp();
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



