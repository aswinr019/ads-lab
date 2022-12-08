#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

struct node* insert(struct node *startNode , int data){
	struct node *temp;
	if(startNode == NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}
	else if (data < startNode->data)
		startNode->left = insert(startNode->left,data);
	else 
		startNode->right = insert(startNode->right,data);

	return  temp;
}

void preOrder(struct node *root){
	if(root == NULL)
		return;
	printf("%d\t",root->data);
	preOrder(root->left);
	preOrder(root->right);
}
	
void inOrder(struct node *root){
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d\t",root->data);
	inOrder(root->right);
}

void postOrder(struct node *root){
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d\t",root->data);
}
void main(){

	int choice,data;
	do{
		printf("Enter a choice :\n0.Exit\n1.Insert a node\n2.Pre-order\n3.In-order\n4.Post-order\n\n-> ");
		scanf("%d",&choice);
		switch(choice){
			case 0 : {
					 printf("Exititng!\n\n");
					 exit(0);
				 }
			case 1 : {
					 printf("Enter a number to insert : ");
					 scanf("%d",&data);
	      				 root = insert(root,data);
					 break;
				 }
			case 2 : {
					 printf("Pre-order : ");
					 preOrder(root);
					 printf("\n");
					 break;
				 }
			case 3 : {
					 printf("In-order : ");
					 inOrder(root);
					 printf("\n");
					 break;
				 }
			case 4 : {
					 printf("Post-order : ");
					 postOrder(root);
					 printf("\n");
					 break;
				 }
			default : {
					  printf("Wrong input\n");
					  break;
				  }
		}
	}while(choice != 0);

}
