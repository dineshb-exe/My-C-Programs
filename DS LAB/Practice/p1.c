#include<stdio.h>

int main(){
    FILE *fp;
    int k=65;
    fp=fopen("Sample.txt","r+");
    putw(k,fp);
    printf("%d",k);
    fclose(fp);
}
