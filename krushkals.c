#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int p[10];
int parent(int x){
    while(x!=p[x]){
        x=p[x];
    }return x;
}

void kruskal(int graph[10][10],int n){
    int u,v;
    for(int i=0;i<n;i++) p[i]=i;
    int ne=0;
    int sum=0;
    while(ne<n-1){
        int min=999;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]<min){
                    min=graph[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        
        if(parent(v)!=parent(u)){
            p[v]=u;sum+=graph[u][v];
            printf("connect %d --> %d =%d \n",u,v,graph[u][v]);
            ne++;
        }
         graph[u][v]=999;
        graph[v][u]=999;   
    }
    printf("cost of mst is %d ",sum);
}

void main(){
    int graph[10][10]={
        {0 ,30, 40, 999, 999, 999},
        {30 ,0 ,50 ,10, 999, 999},
        {40 ,50 ,0, 999, 20 ,999},
        {999, 10, 999, 0 ,60, 80},
        {999, 999 ,20 ,60 ,0, 70},
        {999, 999, 999 ,80, 70 ,0}
    };
    kruskal(graph,6);
}
