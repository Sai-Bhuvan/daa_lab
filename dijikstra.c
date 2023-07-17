#include <stdio.h>

int visited[10],dist[10];

void disik(int graph[10][10],int source,int n){
    int u,v;
    for(int i=0;i<n;i++){
        visited[i]=0;
        dist[i]=graph[source][i];
    }
    visited[source]=0;
    for(int ne=0;ne<n-1;ne++){
        int min=99;
        for(int i=0;i<n;i++){
            if(visited[i]==0 && dist[i]<min){
                u=i;
                min=dist[i];
            }
        }
        visited[u]=1;
        for(v=0;v<n;v++){
            if(visited[v]==0 && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
        
    }
}

void main() {
    // Write C code here
    // printf("Hello world");

    // return 0;
    int graph[10][10]={
        {0,80,20,999,999},
        {80,0,10,30,999},
        {20,10,0,90,60},
        {999,30,90,0,10},
        {999,999,60,10,0}
    };
    disik(graph,0,5);
    
   
    for(int i=0;i<5;i++){
        printf("%d --> %d =%d \n",0,i,dist[i]);
    }
}
