#include<stdio.h>
#define N 10
int stack[N];
int top = -1;

void push(void){
	int x;
	printf("Enter a number to push : ");
	scanf("%d",&x);
	if(top == N-1)
		printf("Overflow\n");
	else {
		top++;
		stack[top] = x;
	}
}

void pop(void){
	int x;
	if(top == -1)
		printf("Underflow\n");
	else {
		x= stack[top];
		top--;
		printf("The popped element is %d\n",x);
	}
}
void topp(void){
	if(top ==-1)
		printf("Stack is empty\n");
	else 
		printf("top : %d\n",stack[top]);
}

void display(void){
	int i;
	if(top == -1)
		printf("Stack is empty\n");
	else {
		printf("Stack elements are: ");
		for(i = top ; i >= 0; i--)
			printf("%d\t",stack[i]);
		printf("\n");
	}
}

void main(){
	int choice;
	do{
	printf("Enter the choice : \n1.Push\n2.Pop\n3.Top\n4.Display\n\n");
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
		case 3: {
				topp();
				break;
			}
		case 4: {
				display();
				break;
			}
		default:{
				printf("Default choice \n");
			}
	}
}while(choice != 0);
}
