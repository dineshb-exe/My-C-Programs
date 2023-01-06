#include<stdio.h>
const int N=21;
int main(){
    char ch[N],c;
    int i,count=0;
    printf("Enter the string: ");
    gets(ch);
    printf("Enter a character: ");
    scanf("%c",&c);
    for(i=0;ch[i]!=0;i++){
        if(ch[i]==c)
            count++;
    }
    printf("The frequency of %c is: %d",c,count);
}
