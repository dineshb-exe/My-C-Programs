#include<stdio.h>
void printWithcomma(long num);

int digitCalc(long n){
    int i=0;
    while(n>0){
        n/=10;
        i++;
    }
    return i;
}

int main(){
    long n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printWithcomma(n);
}
void printWithcomma(long n){
    int b=digitCalc(n);
    return;
}
