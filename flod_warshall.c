#include <stdio.h>

int min(int a,int b){
    return a>b?b:a;
}

void disp(int arr[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void warshall(int arr[10][10],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
}

void floyd(int arr[10][10],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
}

void main(){
    int arr[10][10]={
        {0,1,0,0},
        {0,0,0,1},
        {0,0,0,0},
        {1,0,1,0}
    };
    warshall(arr,4);
    disp(arr,4);
    
    int ar[10][10]={
        {0,999,3,4},
        {2,0,999,999},
        {999,7,0,1},
        {6,999,999,0}
    };
    floyd(ar,4);
    disp(ar,4);
}
