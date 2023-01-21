#include<stdio.h>
#include<stdlib.h>


struct node{
int key;
struct node *left;
struct node *right;
};

struct node* insert(struct node *start,int key){

	if(start == NULL ){
		start = (struct node*)malloc(sizeof(struct node));
		start->key = key;
		start->left = NULL;
		start->right = NULL;
	}
	else if( key < start->key){

		start->left = insert(start->left,key);
}	
	else  
		start->right = insert(start->right,key);

	return start;
	

}

void preOrder(struct node* root){

	if(root == NULL)
		return;
	printf("%d\t",root->key);
	preOrder(root->left);
	preOrder(root->right);
}


void inOrder(struct node* root){

	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d\t",root->key);
	inOrder(root->right);

}

void postOrder(struct node* root){

	if(root == NULL)
		return;
	
	postOrder(root->left);
	postOrder(root->right);
	printf("%d\t",root->key);

}


int search(struct node *root,int s){
	if(root == NULL)
		return -1;
	else if(root->key == s)
		return 1;
	else if (s < root->key)
		search(root->left,s);
	else 
		search(root->right,s);

}



int main(){

	int choice,n,s,r;
	struct node *root = NULL;
	
	do{
		printf("Enter a choice : 0)Exit\n\n1)Insert\n\n2)preOrder\n\n3)InOrder\n\n4)PostOrder\n\n5)Search\n\n-> ");
	scanf("%d",&choice);
	switch(choice){

		case 0: {
				exit(0);

		}
		case 1 : {
			printf("Enter a number to insert : ");
			scanf("%d",&n);
			root = insert(root,n);
			break;
		}
		case 2:{
			preOrder(root);
			printf("\n");
			break;
			}
		case 3 :{
			
			inOrder(root);
			printf("\n");
			break;
			}
			case 4 :{
			
				postOrder(root);
				printf("\n");
			break;
			}
			case 5 :{
			
				printf("Enter a number to search : ");
				scanf("%d",&s);
				r = search(root,s);
				if(r < 0)
					printf("Key not found!\n\n");
				else 
					printf("Key found\n\n");
			break;
			}
		default : {

				printf("Wrong choice!\n\n");
			}
	}

	}while(choice !=0);


}

