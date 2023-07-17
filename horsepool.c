#include <stdio.h>
#include<string.h>

char text[]="JIM_IS_NEAR_MY_HOUSE_DA";
char pattern[]="NEAR";
char stable[128];
int m,n;

void shiftable(){
    m=strlen(pattern);
    n=strlen(text);
    for(int i=0;i<=127;i++) stable[i]=m;
    for(int i=0;i<m-2;i++) stable[pattern[i]]=m-i-1;
}

int horsepool(){
    int i=m-1;
    while(i<=n-1){
        int k=0;
        while(k<=m-1 && pattern[m-1-k]==text[i-k]) k++;
        if(k==m) return i-m+1;
        else i+=stable[text[i]];
    }
    return -1;
}

void main(){
    shiftable();
    printf("%d ",horsepool());
}
