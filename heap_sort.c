#include <stdio.h>
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heapify(int a[],int n,int i)
{
    int largestIndex=i;
    int leftIndex=2*i+1;
    int rightIndex=2*i+2;
    
    if(leftIndex<n && a[leftIndex]>a[largestIndex])
    {
        largestIndex=leftIndex;
    }
    if(rightIndex<n && a[rightIndex]>a[largestIndex])
    {
        largestIndex=rightIndex;
    }
    if(largestIndex!=i)
    {
        swap(&a[i], &a[largestIndex]);
        heapify(a,n,largestIndex);
    }
}
void maxHeap(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    
    printf("................max Heap tree............\n");
    for(int i=0;i<n;i++)
    {
        printf("   %d",a[i]);
    }
}
void heapSort(int a[], int n)
{
    
    for(int i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
    
}
int main()
{
    int a[]={1,12,9,5,6,10};
    int n=sizeof(a)/sizeof(int);
    maxHeap(a,n);
    heapSort(a,n);
    
    printf("\n................Sorted list............\n");
    for(int i=0;i<n;i++)
    {
        printf("   %d",a[i]);
    }

    return 0;
}
