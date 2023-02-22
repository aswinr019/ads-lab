#include<stdio.h>

#define MAX 10

void dfs(int graph[MAX][MAX],int vc,int start){

	int stack[MAX];
	int visited[MAX];
	int top = -1;

	stack[++top] = start;
	visited[start] = 1;

	while(top >= 0 ){
		int current = stack[top--];
		printf("%d\t",current);

		for(int i = 0; i < vc ; i++){

			if(graph[current][i] && !visited[i]){
				stack[++top] = i;
				visited[i] = 1;		
		}	
	}
	}
}

int main(){


	int graph[MAX][MAX];
	int n,start;
	printf("enter the number of vertex : ");
	scanf("%d",&n);
	printf("enter the adj matrix in order : ");
	for(int i = 0;i < n ; i++){
		for(int j = 0; j < n; j++)
			scanf("%d",&graph[i][j]);
	}
	printf("enter start vertex : ");
	scanf("%d",&start);

	if(n > 0 ){
		printf("dfs order :\t");
		dfs(graph,n,start);
		printf("\n");
	}
	return 0;
}
