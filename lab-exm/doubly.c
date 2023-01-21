#include<stdio.h>
#include<stdlib.h>


struct node{

	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;


void insertBeg(void){

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter a number to insert : ");
	scanf("%d",&temp->data);
	temp->prev = NULL;
	temp->next = NULL;
		
	if(head == NULL){
		head = temp;
	}
	else {
		head->prev = temp;
		temp->next = head;
		head  = temp;
		
	}

}


void insertMiddle(){

	int pos;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter a number to insert : ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	temp->prev = NULL;

	printf("After which node do you want to insert : ");
	scanf("%d",&pos);
	
	struct node *ptr = head,*postptr;

	if(head == NULL)
		printf("Cannot delete, list is empty\n\n");
	else {

		while(ptr->data != pos ){
			
			ptr = ptr->next;

		}

		if(ptr != NULL){
		postptr = ptr->next;
		

		temp->next = ptr->next ;
		ptr->next = temp;
		temp->prev = ptr;
		postptr->prev = temp;
		}
		}
	

}

void deleteBeg(void){


	struct node *ptr = head;

	if(ptr == NULL)
		printf("Cannot delete , list is empty\n\n");
	else if (ptr->next == NULL){
			head = NULL;
			free(ptr);
	}
	else {

		head = head->next;
		head->prev = NULL;
		free(ptr);
		}

}


void search(int s ){


	int found  = -1,count = 0;

	struct node *ptr = head ;

	if(ptr == NULL)
		printf("Cannot search , list is empty \n\n");
	else {
		while(ptr != NULL){

			if(ptr->data == s)
				found = count;
			ptr = ptr->next;
			count++;
		}

		if(found < 0)
			printf("Element not found!!\n");
		else{
			printf("Element found at position %d\n\n",found);
			}
			

	}

}

void display(void){

	struct node* ptr = head;
	
	if(ptr == NULL)
		printf("List is empty!\n\n");
	else {

		while(ptr != NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
		}

		printf("\n");
	}
}

int main(){



	int choice , s;
	do {
		printf("Enter a choice :\n0)Exit\n\n1)Insert beg\n\n2)Insert Middle\n\n3)Delete Beg\n\n4)Search\n\n5)Display\n\n-> ");
		scanf("%d",&choice);
		switch(choice){

			case 0 : {
					exit(0);
				}
			case 1 : {
					insertBeg();
					break;

					}
			case 2 : {

					insertMiddle();
					break;
				}

			case 3 : {

					deleteBeg();
					break;
				}
			case 4 : {

					printf("Enter an element to search : ");
					scanf("%d",&s);
					search(s);
					break;
				}
			case 5 : {
					display();
					break;
				}
			default : {

				printf("wrong choice !\n");	
				}
		}

	}while(choice != 0);

}
