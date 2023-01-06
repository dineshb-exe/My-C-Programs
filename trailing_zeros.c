#include<stdio.h>

long fact(int n){
    long fac=1;
    int j;
    for(j=1;j<=n;j++){
        fac*=j;
    }
    return fac;
}
int main(){
    int n1;
    printf("Enter a number: ");
    scanf("%d",&n1);
    int i=0;
    long f=fact(n1);
    printf("%d\n",f);
    while(f%10==0){
        i++;
        f/=10;
    }
    printf("The number of trailing zeros is %d",i);
}
