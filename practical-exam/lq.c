#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *next;
};


typedef struct node node;

node *front = NULL,*rear = NULL;


void enqueue(void){
	node *temp = (node*)malloc(sizeof(node));
	
	printf("Enter a char to insert :");
	scanf("%s",&temp->data);
	//temp->data = 'a';
	temp->next = NULL;

	if(!rear) {
		front = temp;
		rear = temp;
	}else {
		rear->next = temp;
		rear = rear->next;	
	}
}

void dequeue(void){
	
	if(!front){rear = NULL; printf("empty linked queue\n\n");}
	else{
		node *ptr = front;
		front = front->next;
		printf("deleted char is %c\n",ptr->data);
		free(ptr);
		}
}

void display(void){
	
	if(!front) printf("empty linked queue\n");
	else { 
		node *ptr = front;
		while(ptr){
			printf("%c\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
		
	}
}


int main(){

	int choice;
	do{
		printf("Enter a choice :\n0.exit\n1.insert\n2.delete\n3.display\n\n->   ");
		scanf("%d",&choice);

		switch(choice){
			case 0 :{
					printf("exiting...\n");
					exit(0);
					break;			
				}
				case 1 :{
	
					enqueue();
					break;			
				}
				case 2 :{
					dequeue();
					break;			
				}
				case 3 :{
					display();
					break;
								
				}
				default : { printf("wrong choice \n");}
				
		}
	}while(choice != 0);
}






