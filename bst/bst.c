#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left;
	struct node *right;
};


struct node* insert(struct node *startNode , int key){

	if(startNode == NULL){
		startNode = (struct node*)malloc(sizeof(struct node));
		startNode->key = key;
		startNode->left = NULL;
		startNode->right = NULL;
		
	}
	else if (key < startNode->key)
		startNode->left = insert(startNode->left,key);
	else 
		startNode->right = insert(startNode->right,key);

	return  startNode;
}

int getRootData(struct node* root){
	if(root == NULL)
		return -1;
	else 
		return (root->key);
}

int getMinKey(struct node* root){

	if(root == NULL )
		return -1;
	else {
		while(root != NULL && root->left != NULL)
			root = root->left;
		return root->key;
	}
}

int getMaxKey(struct node* root){

	if(root == NULL ) 
		return -1;
	else {
		while ( root != NULL && root->right != NULL)
			root = root->right;
		return root->key;
	}

}

void preOrder(struct node *root){
	if(root == NULL)
		return;
	printf("%d\t",root->key);
	preOrder(root->left);
	preOrder(root->right);
}
	
void inOrder(struct node *root){
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d\t",root->key);
	inOrder(root->right);
}

void postOrder(struct node *root){
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d\t",root->key);
}
struct node* deleteKey(struct node* root,int delete){

	if(root == NULL)
		return NULL;
	else if(delete < root->key)
		root->left = deleteKey(root->left,delete);
	else if(delete > root->key)
		root->right = deleteKey(root->right,delete);
	else {
		if(root->left == NULL && root->right == NULL)
			return NULL;
		else if(root->right == NULL){

			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		struct node* temp = root->right;
		while(temp != NULL && temp->left != NULL)
			temp = temp->left;
		root->key = temp->key;
		root->right = deleteKey(root->right,temp->key);
	}
	return root;
}

int searchKey(struct node* root, int search){

	if(root == NULL)
		return -1;
	else if(root->key == search)
		return 1;
	else if(search < root->key)
		searchKey(root->left,search);
	else
		searchKey(root->right,search);

}




void main(){

	int choice,key,rootData,minKey,maxKey,search,delete;
	struct node *root = NULL,*searchResult ;

	do{
		printf("Enter a choice :\n0.Exit\n1.Insert a node\n2.Pre-order\n3.In-order\n4.Post-order\n5.Root\n6.Min key\n7.Max key\n8.Delete key\n9.Search Key\n\n-> ");
		scanf("%d",&choice);
		switch(choice){
			case 0 : {
					 printf("Exititng!\n\n");
					 exit(0);
				 }
			case 1 : {
					 printf("Enter a number to insert : ");
					 scanf("%d",&key);
	      				 root = insert(root,key);
					 break;
				 }
			case 2 : {
					 printf("Pre-order :\t");
					 preOrder(root);
					 printf("\n\n");
					 break;
				 }
			case 3 : {
					 printf("In-order :\t");
					 inOrder(root);
					 printf("\n\n");
					 break;
				 }
			case 4 : {
					 printf("Post-order :\t");
					 postOrder(root);
					 printf("\n\n");
					 break;
				 }
			case 5 : {
					 rootData = getRootData(root);
					 if(rootData > 0)
					 	printf("The root  is %d\n\n",rootData);
					 else 
						 printf("The bst is empty\n\n");
					 break;
				 }
			case 6: {
					minKey = getMinKey(root);
					if(minKey > 0 )
						printf("The min key is : %d\n\n",minKey);
					else 
						printf("The bst is empty\n\n");
					break;

				}
			case 7 : {
					 maxKey = getMaxKey(root);
					 if(maxKey > 0 )
						 printf("The max key is : %d\n\n",maxKey);
					 else 
						 printf("The bst is empty\n\n");
					 break;
				 }
			case 8 : {
					 printf("Enter a key to delete : ");
					 scanf("%d",&delete);
					 root =  deleteKey(root,delete);
	      				 break;
				 }
			case 9 : {
					 printf("Enter a key to search : ");
					 scanf("%d",&search);

					 searchResult = searchKey(root,search);

					 if(searchResult == -1)
						 printf("Element not present in bst!\n\n");
					 else 
						 printf("key found !!");
					 break;
				 }
	
			default : {
					  printf("Wrong input!\n\n");
					  break;
				  }
		}
	}while(choice != 0);

}
