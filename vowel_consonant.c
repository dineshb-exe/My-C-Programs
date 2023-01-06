#include<stdio.h>
int main(){
    char str1[21];
    int v=0,c=0;
    int i=0;
    gets(str1);
    for(;str1[i]!='\0';i++){
        if(str1[i]=='A'||str1[i]=='a'||str1[i]=='E'||str1[i]=='e'||str1[i]=='I'||str1[i]=='i'||str1[i]=='O'||str1[i]=='o'||str1[i]=='U'||str1[i]=='u')
            v++;
        else if(((str1[i]>='A'&&str1[i]<='Z')||(str1[i]>='a'&&str1[i]<='z'))&&(str1[i]!='A'||str1[i]!='a'||str1[i]!='E'||str1[i]!='e'||str1[i]!='I'||str1[i]!='i'||str1[i]!='O'||str1[i]!='o'||str1[i]!='U'||str1[i]!='u'))
            c++;
    }
    printf("No. of consonants: %d\nNo. of vowels: %d\n",c,v);
}
