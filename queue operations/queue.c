#include<stdio.h>
#define N 10
int q[N];
int front = -1, rear = -1;

void enq(void){
	
	int x;
	printf("Enter the data: ");
	scanf("%d",&x);
	if(rear == N -1 )
		printf("Overflow\n");
	else if(front == -1 && rear == -1){
		front = rear = 0;
		q[front] = x;
		}
	else {
		rear++;
		q[rear] = x;
	}
}

void deq(void){
	int x;
	if(front == -1 && rear == -1)
		printf("Underflow\n");
	else if(front == rear)
		front = rear = -1;
	else {
		x = q[front];
		printf("Dequeued element is %d\n",x);
		front++;
		}
	}
void top(void){
	int x;
	if(front == -1 && rear ==-1)
		printf("Queue is empty\n");
	else {
		x = q[front];
		printf("Top element is %d\n",x);
	}
}

void display(void){
	int i;
	if(front == -1 && rear == -1)
		printf("Queue is empty\n");
	else {
		for(i = front ; i <= rear; i++)
			printf("%d\t",q[i]);
		printf("\n");
		}
}

void main(){
	int choice;
	do {
		printf("Enter a choice : \n1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n\n");
	
	scanf("%d",&choice);

	switch(choice){
		case 1 : {
			enq();
			break;
			}
		case 2: {
			deq();
			break;
			}
		case 3: {
			top();
			break;
			}
		case 4: {
			display();
			break;
			}
		default: {
			printf("Wrong input\n");
			}
	}
	
	}while( choice != 0);
}
