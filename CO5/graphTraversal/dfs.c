
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void DFS(int graph[MAX][MAX], int start, int vertexCount) {

    bool visited[vertexCount];
    for (int i = 0; i < vertexCount; i++) visited[i] = false;
    
    int stack[vertexCount];
    int top = -1;
    
    stack[++top] = start;
    visited[start] = true;
    while (top >= 0) {
       
        int current = stack[top--];
        printf("%d\t", current);

        for (int i = vertexCount-1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}


int main() {

    int choice,i,j,start,vertexCount = 0;
    int graph[MAX][MAX];   

                printf("Enter the number of vertex in the graph: ");
                scanf("%d",&vertexCount);

                printf("Enter the adjacency matrix in order: ");
                for(i = 0; i < vertexCount ; i++){

                    for (j = 0 ; j < vertexCount; j++){
                        scanf("%d",&graph[i][j]);
                    }
                }

                if(vertexCount > 0 ){
                    printf("Enter the start vertex: ");
                    scanf("%d",&start);
                    printf("Graph elements are : ");
                    DFS(graph,start,vertexCount);
                    printf("\n\n");
                }
                else
                {
                    printf("Can not perform depth first traversal in an empty graph!\n\n");
                }


}
