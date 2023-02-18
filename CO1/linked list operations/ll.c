#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
typedef struct node node;
node* head = NULL;

void insertBeg(){

  node *temp = (node*)malloc(sizeof(node));
	printf("Enter a number : ");
	scanf("%d",&temp->data);
	temp->next = head;
	head = temp;

}
void insertInBet(){

	int pos,found = 0;
  node *temp = (node*)malloc(sizeof(node));

	printf("Enter a number to insert : ");
	scanf("%d",&temp->data);
	printf("After what element you want to insert : ");
	scanf("%d",&pos);
	temp->next = NULL;

  if(!head) head = temp;
  else {
    node *ptr = head;
    while(ptr->next){
      if(ptr->data == pos){
        found = 1;
        temp->next = ptr->next;
        ptr->next = temp;
        break;
      }ptr = ptr->next;
    }

    if(ptr->data == pos ){ ptr->next = temp; found = 1; }
  }
  if(!found)
    printf("the entered number is not present in the list!\n");
}

void insertEnd(){

  node *temp = (node*)malloc(sizeof(node));
  printf("Enter a number : ");
	scanf("%d",&temp->data);
	temp->next = NULL;

	if(!head) head = temp;
	
  else{
    node *ptr = head;
		while(ptr->next){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void deleteBeg(){

	if(!head) printf("Linked list is empty!\n");
	
  else {
    node *ptr = head;
		head = head->next;
    printf("deleted number is %d\n",ptr->data);
		free(ptr);
	}
}
void deleteInBet(){
	
  int pos,found = 0;
	printf("Which element you want do delete : ");
	scanf("%d",&pos);
	
  if(!head) printf("Linked list is empty!\n");
  else if(head->data == pos) {
    found = 1;
    node *ptr = head;
    head = head->next;
    printf("deleted number is %d\n",ptr->data);
    free(ptr);
  }
  else {
    node *ptr = head ,*preptr = head;
    while(ptr->next){
      if(ptr->data == pos){
       found = 1;
       preptr->next = ptr->next;
       printf("deleted number is %d\n",ptr->data);
       free(ptr);
       break;
      }
      preptr = ptr;
      ptr = ptr->next;
    }

    if( ptr->data == pos ){ 
      preptr->next = NULL;
      printf("deleted number is %d\n",ptr->data); 
      free(ptr);
    }
	}
  if(!found)
    printf("entred number is not present in the list!\n");
}

void deleteLast(){

	node *ptr = head,*preptr = head;
	if(!ptr)
		printf("Linked list is empty!\n");
	else {
		while(ptr->next){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
    printf("deleted number is %d\n",ptr->data);
		free(ptr);
	}
}

void search(){

	int search,found = 0,i = 1;
	printf("Enter a number to search : ");
	scanf("%d",&search);

	node *temp = head;
	if(!temp) printf("Linked list empty!\n");
	
  else {
		while(temp){
			if(temp->data == search){
				printf("Element found at position %d\n",i);
				found = 1;
			}
			temp = temp->next;
			i++;
		}
	}
	if(!found)
		printf("Element not present in list!\n");
}
void display(){
	
	node *temp = head;

	if(!temp)
		printf("Linked list is empty\n");
	else{
	while(temp){
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



