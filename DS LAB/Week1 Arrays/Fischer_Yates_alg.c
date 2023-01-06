#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

const int N=10;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void shuffle(int* a,int size){
    int i,j;
    srand(time(NULL));
    for(i=size-1;i>0;i--){
        j=rand()%(i+1);
        swap(&a[i],&a[j]);
    }
}

void display(int *a, int size){
    int i;
    printf("\nThe elements of the array are as follows:\n");
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    int *arr;
    int i1,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    for(i1=0;i1<n;i1++){
        printf("Enter a number: ");
        scanf("%d",&arr[i1]);
    }
    shuffle(arr,n);
    display(arr,n);
    free(arr);
}
