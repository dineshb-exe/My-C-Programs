#include<stdio.h>
#include<string.h>
int main(){
    char str[21];
    int i,ck=1;
    printf("Enter the string: ");
    gets(str);
    for(i=0;i<strlen(str)&&ck==1;i++){
        if(str[i]!=str[strlen(str)-1-i])
            ck=0;
    }
    if(ck==1)
        printf("%s is a palindrome!!",str);
    else
        printf("%s is not a palindrome!!",str);
}
