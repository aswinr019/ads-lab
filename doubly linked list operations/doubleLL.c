#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;

void insertBeg(void){

	int data;
	printf("Enter a number : ");
	scanf("%d",&data);
	struct node *ptr;
	struct node *temp = ( struct node* )malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if(head == NULL){
		temp->next = head;
		head = temp;
	}
	else{
		ptr = head;
		temp->next = head;
		ptr->prev = temp;
		head = temp;
	}
}

void insertLast(void){

	int data;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter a number : ");
	scanf("%d",&data);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if(head == NULL)
		head = temp;
	else {
		struct node *ptr = head;

		while(ptr->next !=NULL){
			ptr = ptr->next;
		}

		ptr->next = temp;
		temp->prev = ptr;
	}
}

void insertInBet(void){

	int data,pos,found = -1;
	printf("Enter a number to insert : ");
	scanf("%d",&data);
	printf("After what number you want to insert : ");
	scanf("%d",&pos);

	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	struct node *ptr = head, *check = head,*postptr;

	if(ptr == NULL)
		head = temp;
	else {
		while(check != NULL){
			if(check->data == pos)
				found = 0;
			check = check->next;
		}
		if(found < 0){

			printf("Invalid position\n\n");
			free(temp);
		}
		else {
			while(ptr->data != pos){
				ptr = ptr->next;
			}
			postptr = ptr->next;
			temp->next = postptr;
			temp->prev = ptr;
			ptr->next = temp;
			postptr->prev = temp;
		}
	}
}

void deleteBeg(void){

	struct node *ptr , *preptr = head;

	if(preptr == NULL)
		printf("List is empty\n\n");
	else if(preptr->next == NULL){
		printf("The deleted number is %d\n\n",preptr->data);
		free(preptr);
		head = NULL;
	}
	else {
		ptr = preptr->next;
		ptr->prev = NULL;
		head = ptr;
		printf("The deleted number is %d\n\n",preptr->data);
		free(preptr);
	}

}

void deleteLast(void){

	struct node *preptr , *ptr = head;

	if(ptr == NULL)
		printf("List is empty\n\n");
	else if(ptr->next == NULL){
		printf("The deleted number is %d\n\n",ptr->data);
		free(ptr);
		head = NULL;
	}
	else {
		while(ptr->next != NULL){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
		printf("The deleted number is %d\n\n",ptr->data);
		free(ptr);
	}
}

void deleteInBet(void){

	int pos,found = -1;
	printf("Which element you want to delete : ");
	scanf("%d",&pos);

	struct node *ptr = head , *check = head , *preptr,*postptr;
	if(ptr == NULL)
		printf("List is empty\n\n");
	else {
		while(check != NULL){
			if(check->data == pos)
				found = 0;
			check = check->next;
		}

		if(found < 0)
			printf("%d is  not present in the list\n\n");
		else {
			if(ptr->next == NULL){
				printf("The deleted number is %d\n\n",ptr->data);
				free(ptr);
				head = NULL;
			}
			else{
			while(ptr->data != pos ){
				preptr = ptr;
				ptr = ptr->next;
			}
			postptr = ptr->next;
			preptr->next = postptr;
			postptr->prev = preptr;
			printf("The deleted number is %d\n\n",ptr->data);
			free(ptr);
			}
		}
	}
}

void search(void){

	int s,found = -1,pos = 1;
	printf("Enter a number to search : ");
	scanf("%d",&s);

	struct node *ptr = head;
	if(ptr == NULL)
		printf("List is empty\n\n");
	else {
		while(ptr != NULL){
			if(ptr->data == s){
				printf("Number found at position %d\n",pos);
				found = 0;
			}
			ptr = ptr->next;
			pos++;
		}

		if(found < 0 )
			printf("Number not present in list\n\n");
		printf("\n\n");
	}

}

void display(void){

	struct node *ptr = head;

	if(ptr == NULL)
		printf("List is empty\n\n");
	else {
		while(ptr != NULL){

			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n");
	}

}

void reverse_display(){


	struct node *ptr = head;

	if(ptr == NULL)
		printf("List is empty\n\n");
	else {
		while(ptr->next != NULL){
			ptr = ptr->next;
		}

		while( ptr->prev != NULL){
			printf("%d\t",ptr->data);
			ptr = ptr->prev;
		
		}
		printf("%d\t",ptr->data);
		printf("\n\n");
	}
}


void main(){


	int choice;

	do{

		printf("Enter a choice :\n0.Exit\n1.Insert in beginning\n2.Insert at end\n3.Insert in between\n4.Delete from beginning\n5.Delete from end\n6.Delete from in between\n7.Search\n8.Display\n9.Reverse Display\n\n-> ");
		scanf("%d",&choice);
		switch(choice){

			case 0 :{
					exit(0);
				}
			case 1 : {
					 insertBeg();
					 break;
				 }
			case 2 : {
					 insertLast();
					 break;
				 }
			case 3 : {
					 insertInBet();
					 break;
				 }
			case 4 : {
					 deleteBeg();
					 break;
				 }
			case 5 : {
					 deleteLast();
					 break;
				 }
			case 6 : {
					 deleteInBet();
					 break;
				 }
			case 7 : {
					 search();
					 break;
				 }
			case 8 : {
					 display();
					 break;
				 }
			case 9: {
					reverse_display();
					break;
				}
			default : {
					  printf("Wrong input\n");
				  }
		}
	}while(choice != 0);

}




