#include<stdio.h>

const int N=10;

int main(){
    int a[N],i,temp,temp2;
    printf("Enter the elements: ");
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<N;i++){
        if(i==0)
            temp=a[i];
        else
            temp=temp2;
        if(i==0)
            a[i]=a[N-1];
        else
            a[i]=temp;
        if(i!=N-1)
            temp2=a[i+1];
        else
            temp2=a[0];
    }
    printf("Rotated array: ");
    for(i=0;i<N;i++)
        printf("%d \t",a[i]);
}
