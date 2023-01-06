#include<stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int m=2*n-1;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<n-i;j++)
        printf(" ");
        for(;j<n;j++)
        printf("1 ");
        printf("\n");
    }
    for(i=n-1;i>0;i--){
        for(j=0;j<n-i;j++)
        printf(" ");
        for(;j<n;j++)
        printf("1 ");
        printf("\n");
    }
}
