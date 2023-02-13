#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
void insertBeg(){

	int data;
	printf("Enter a number : ");
	scanf("%d",&data);

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	temp->next = head;
	head = temp;

}
void insertInBet(){

	int data,pos,found = -1;
	printf("Enter a number to insert : ");
	scanf("%d",&data);
	printf("After what element you want to insert : ");
	scanf("%d",&pos);
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *ptr = head, *check = head;
	if(ptr == NULL){
		head = temp;
	}
	else{
		while(check != NULL){

			if(check->data == pos)
				found = 0;
			check = check->next;
		}

		if(found < 0 ){
			printf("Invalid position\n");
			free(temp);
	}
		else {

		while(ptr->data != pos){
			ptr = ptr->next;
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
	}
}

void insertLast(){

	int data;
	printf("Enter a number : ");
	scanf("%d",&data);
	struct node *ptr = head;
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(head == NULL)
		head = temp;
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void deleteBeg(){

	struct node *ptr = head,*temp = head;
	if(temp == NULL)
		printf("Underflow!\n");
	else {
		temp = temp->next;
		head = temp;
		free(ptr);
	}
}
void deleteInBet(){
	int pos,found = -1;
	printf("Which element you want do delete : ");
	scanf("%d",&pos);

	struct node *ptr = head,*check = head,*temp;

	if(ptr == NULL)
		printf("Underflow!\n");
	else {
		while(check != NULL){
			if(check->data == pos){
				found = 0;
			}
			check = check->next;
		}

		if(found < 0 )
			printf("%d is not present in the list\n",pos);
		else {

		while(ptr->data != pos){
			temp = ptr;
			ptr = ptr->next;
		}

		temp->next = ptr->next;
		free(ptr);
	}
	}

}

void deleteLast(){

	struct node *ptr = head,*preptr = head;
	if(ptr == NULL)
		printf("Underflow!\n");
	else {
		while(ptr->next != NULL){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
		free(ptr);
	}
}
void search(){

	int search,found = -1,i = 1;

	printf("Enter a number to search : ");
	scanf("%d",&search);

	struct node *temp = head;
	if(temp == NULL)
		printf("Linked list empty\n");
	else {
		while(temp != NULL){
			if(temp->data == search){
				printf("Element found at position %d\n",i);
				found = 0;
			}
			temp = temp->next;
			i++;
		}
	}
	if(found < 0)
		printf("Element not present in list\n");
}
void display(){
	
	struct node *temp = head;

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

	printf("Enter a choice : \n1.Insert at beginning\n2.Insert at end \n3.Insert in between\n4.Delete from start\n5.Delete from end\n6.Delete from in between\n7.Search\n8.Display\n\n-> ");
	scanf("%d",&choice);

	switch(choice){
		case 1 : {
				 insertBeg();
				 break;
			 }
		case 2: {
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
		case 5: {
				deleteLast();
				break;
			}
		case 6: {
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
				  printf("Wrong input\n");
			  }
	}
}while(choice != 0 );
}



