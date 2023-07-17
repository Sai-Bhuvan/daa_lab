#include <stdio.h>
#include<time.h>

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1];
    int R[n2];
    
    for(i=0;i<n1;i++){
        L[i]=arr[low+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+j+1];
    }
    
    i=0;j=0;k=low;
    while(i<n1 && j<n2){
        if(L[i]>R[j]){
            arr[k]=R[j];
            j++;
        }else{
            arr[k]=L[i];
            i++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;k++;
    }
    
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() {
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i]=rand()%100;
    }
    clock_t start,end;
    start=clock();
    mergesort(arr,0,100-1);
    end=clock();
    for(int i=0;i<100;i++){
        printf("%d ",arr[i]);
    }
    printf("\n%lf\n",(double)(end-start)/1000);
}
