#include<stdio.h>
int main(){
    char str1[100],str2[50],str3[50];
    printf("Enter a string: ");
    gets(str1);
    int i=0,j=0,k=0;
    while(str1[i]!='\0'){
        if(i%2==0){
            str2[j]=str1[i];
            j++;
        }
        else{
            str3[k]=str1[i];
            k++;
        }
        i++;
    }
    str2[j]=0;
    str3[k]=0;
    printf("Characters in the odd indices: %s\n",str3);
    printf("Characters in the even indices: %s\n",str2);
}
