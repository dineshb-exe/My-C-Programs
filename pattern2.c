#include<stdio.h>

int main(){
    int n,i,j;
    printf("Enter a number: ");
    scanf("%d",n);
    for(i=0;i<n;i++){
        print("%d",i);
        for(j=i;j>0;j--)
        printf("%d",j);
        for(j=2;j<n;j++)
        printf("%d",j);
        printf("\n");
    }
}
