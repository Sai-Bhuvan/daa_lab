#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
   int pivot=low,i=low+1,j=high;
   while(i<j)
   {
       while(a[i]<=a[pivot])   i++;
       while(a[j]>a[pivot])    j--;
       if(i<j)
       {
           int temp=a[i];
           a[i]=a[j];
           a[j]=temp;
       }
   }
   int temp=a[pivot];
   a[pivot]=a[j];
   a[j]=temp;
   return j;
 
}
void divide(int a[],int low, int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        divide(a,low,j-1);
        divide(a,j+1,high);
    }
}

int main()
{
    int a[10000];
    clock_t start,end;
    
    printf("\n random generated item \n");
    for(int i=0;i<100;i++)
    {
        a[i]=rand()%1000;
        printf("  %d",a[i]);
    }
    start=clock();
    divide(a,0,100-1);
    end=clock();
    printf("\n sortd list of  item \n");
    for(int i=0;i<100;i++)
    {
        printf("  %d",a[i]);
    }
    
    double final=(double)(end-start)/1000;
    printf("\n Algorithm time =%f",final);
    return 0;
}
