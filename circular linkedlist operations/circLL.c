#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node *head = NULL , *current = NULL;

void insertBeg(void){

	int data;
	printf("Enter a number to insert : ");
	scanf("%d",&data);

	struct node *temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		current = temp;
		temp->next = head;
	}
	else {
		temp->next = head;
		head = temp;
		current->next = temp;
	}
}

void insertEnd(void){

	int data;
	printf("Enter a number to insert : ");
	scanf("%d",&data);

	struct node *temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		current = temp;
		temp->next = head;
	}
	else {
		current->next = temp;
		current = temp;
		current->next = head;
	}
}

void insertInBet(void){

	int data,pos,found = -1;
	printf("Enter a number to insert : ");
	scanf("%d",&data);
	printf("After what number you want to insert : ");
	scanf("%d",&pos);
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *ptr = head, *check = head;
	if(ptr == NULL){
		head = temp;
		current = temp;
		temp->next = head;
	}
	else{
		while(check->next != head){
			if(check->data == pos)
				found = 0;
			check = check->next;
		}
		if(check->data == pos)
			found = 0;

		if(found < 0 ){
			printf("Invalid position\n\n");
			free(temp);
		}
		else {
			while(ptr->data != pos){
				ptr = ptr->next;
			}
			if(ptr->next == head){
				ptr->next = temp;
				current = temp;
				current->next = head;
			}
			else {
				temp->next = ptr->next;
				ptr->next = temp;
			}
		}
	}

}

void deleteBeg(void){

	struct node *preptr = head,*ptr = head;

	if(preptr == NULL)
		printf("The list is empty\n\n");
	else if(preptr->next == head) {
		head = NULL;
		current = NULL;
		printf("Deleted number is %d\n\n",preptr->data);
		free(preptr);
	}
	else{
		ptr = preptr->next;
		head = ptr;
		current->next = head;
		printf("Deleted number is %d\n\n",preptr->data);
		free(preptr);
	}	
}

void deleteEnd(void){
	struct node *ptr = head ,*preptr = head;

	if(preptr == NULL)
		printf("The list is empty\n\n");
	else if (preptr->next == head){
		head = NULL;
		current = NULL;
		printf("Deleted number is %d\n\n",preptr->data);
		free(preptr);
	}
	else {
		while(ptr->next != head){
			preptr = ptr;
			ptr = ptr->next;
		}
		current = preptr;
		current->next = head;
		printf("Deleted number is %d\n\n",ptr->data);
		free(ptr);
	}
}

void deleteInBet(void){

	int pos,found = -1;
	printf("Which number you want to delete : ");
	scanf("%d",&pos);

	struct node *preptr,*ptr = head,*check = head;

	if(ptr == NULL)
		printf("The list is empty\n\n");
	else if(ptr->data == pos){
		if(ptr->next == head){
			head = NULL;
			current = NULL;
			printf("The deleted number is %d\n\n",ptr->data);
			free(ptr);
		}
		else {
			head = ptr->next;
			current->next = head;
			printf("The deleted number is %d\n\n",ptr->data);
			free(ptr);
		}
	}

	else {
		while(check->next != head){
			if(check->data == pos){
				found = 0;
			}
			check = check->next;
		}
		if(check->data == pos)
			found = 0;

		if(found < 0 )
			printf("%d is not present in the list\n\n");
		else {
			while(ptr->data != pos){
				preptr = ptr;
				ptr = ptr->next;
			}	
			if(ptr->next == head){
				current = preptr;
				preptr->next = head;
				printf("The deleted number is %d\n\n",ptr->data);
				free(ptr);
			}
			else{
				preptr->next = ptr->next;
				printf("The deleted number is %d\n\n",ptr->data);
				free(ptr);
			}
		}
	}
}

void search(void){

	int search,found = -1,i = 1;
	printf("Enter a number to search : ");
	scanf("%d",&search);

	struct node *ptr = head;
	if(ptr == NULL)
		printf("The list is empty\n\n");
	else {
		while(ptr->next != head){
			if(ptr->data == search){
				printf("Number found at position %d\n\n",i);
				found = 0;
			}
			ptr = ptr->next;
			i++;
		}
		if(ptr->data == search)
			printf("Number found at position %d\n\n",i);
	}
	if(found < 0)
		printf("Element not present in list\n\n");

}

void display(void){
	struct node *ptr = head;

	if(ptr == NULL)
		printf("The list is empty\n\n");
	else{	
		while(ptr->next != head){
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("%d\n\n",ptr->data);
	}
}

void main(){
	int choice;

	do{
		printf("Enter a choice : \n1.Insert at beginning\n2.Insert at end \n3.Insert in between\n4.Delete from start\n5.Delete from end\n6.Delete from in between\n7.Search\n8.Display\n\n-> ");
		scanf("%d",&choice);

		switch(choice){
			case 0 : {
					 printf("Exiting!\n");
					 exit(0);
				 }
			case 1 : {
					 insertBeg();
					 break;

				 }
			case 2 : {
					 insertEnd();
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
					 deleteEnd();
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
			default : {
					  printf("Wrong input!\n");
					  break;
				  }
		}
	}while(choice != 0 );
}


