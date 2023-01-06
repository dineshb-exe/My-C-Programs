#include<stdio.h>
#include<string.h>

const int M=7;
const int N=21;
void accept(char a[M][N]){
    int i;
    printf("Enter %d words: \n",M);
    for(i=0;i<M;i++)
    gets(a[i]);
}
void display(char a[M][N]){
    int i;
    for(i=0;i<M;i++){
        printf("%s \t",a[i]);
    }
    printf("\n");
}
void bubbleSort(char a[M][N], int size){
    char temp[N];
    int i,j;
    for(i=size-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(strcmp(a[j-1],a[j])>0){
                strcpy(temp,a[j-1]);
                strcpy(a[j-1],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
}
int main(){
    char x[M][N];
    accept(x);
    printf("Array Before Sorting: \n");
    display(x);
    bubbleSort(x,M);
    printf("Array after Sorting: \n");
    display(x);
}
