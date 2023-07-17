#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}

void napsack(int w[],int p[],int n,int m){
    int v[10][10];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) v[i][j]=0;
            else if(j<w[i]) v[i][j]=v[i-1][j];
            else
             v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
        }
    }
    
    printf("%d is max profit",v[n][m]);
    int profit=v[n][m];
    printf("\n");
    for(int i=n;i>0 && profit>0;i--){
        if(v[i][m]!=v[i-1][m]){
            printf("%d-->%d \n",w[i],p[i]);
            profit-=p[i];
            m-=w[i];
        }
    }
}

void main(){
    int w[]={0,1,2,3,3,2};
    int p[]={0,40,5,10,80,60};
    int m=7;
    int n=5;
    napsack(w,p,n,m);
}
