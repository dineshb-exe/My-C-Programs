#include<stdio.h>
const int M=20;
const int N=60;
int main(){
    char str[M][N];
    int i,j,k,ck=1,wc=0,cc=0;
    printf("Enter a paragraph: ");
    for(i=0;i<M&&ck==1;i++){
        gets(str[i]);
        wc++;
        for(k=0;str[i][k]!=0;k++){
            if(str[i][k]==' ')
                wc++;
        }
        for(k=0;str[i][k]!=0;k++){
            if(str[i][k]!=' ')
                cc++;
        }
        if(str[i][0]==0)
            ck=0;
    }
    printf("The number of lines, words and characters in the paragraph are: %d %d %d",i-1,wc-1,cc-i+1);
}
