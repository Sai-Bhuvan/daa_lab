#include <stdio.h>
int visited[10];
void bfs(int source,int graph[10][10],int n){
    int u,v;
    int q[10],r=-1,f=0;
    for(int i=0;i<n;i++){
        visited[i]=0;
        
    }
    visited[source]=1;
    q[++r]=source;
    
    while(r>=f){
        u=q[f++];
        printf("%d ",u);
        for(int v=0;v<n;v++){
            if(graph[u][v]==1 && visited[v]==0){
                q[++r]=v;
                visited[v]=1;
            }
        }
    }
}


void main() {
  int graph[10][10]={
      {0,1,0,1,0,0},
      {1,0,1,0,1,0},
      {0,1,0,0,0,1},
      {1,0,0,0,1,0},
      {0,1,0,1,0,1},
      {0,0,1,0,1,0}
  };
  bfs(0,graph,6);
}
