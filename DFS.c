#include <stdio.h>
#include <stdlib.h>

int visited[10] = {0,0,0,0,0,0,0,0,0,0},graph[10][10], vertices;

void DFS(int start){
	
	int i,j;
	
	
	if(visited[start] == 0){
		
		visited[start] = 1;
		
			printf(" %d",start);
			
		i = start;
		
			for(j = 0 ; j < vertices  ; j++){
					
				if(graph[i][j] == 1)
					DFS(j);
					
			}
	}
	
}


int main(){
	
	int i,j,start;
	
		printf("\nEnter No of Vertices ");
		scanf("%d",&vertices);
		
		printf("\nEnter Adjancency Matrix : ");
		for(i = 0; i < vertices ; i++){
			for(j = 0; j < vertices ; j++){
				
				scanf("%d",&graph[i][j]);
				
			}
		}
		
		printf("\nEnter Element to start DFS at : ");
		scanf("%d",&start);
		
			DFS(start);
			
		return 0;
		
	}
	
	
