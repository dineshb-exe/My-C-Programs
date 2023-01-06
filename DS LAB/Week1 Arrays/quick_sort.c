#include<stdio.h>
const int N=10;
void swap(int ar[N],int a,int b){
    ar[a]+=ar[b];
    ar[b]=ar[a]-ar[b];
    ar[a]-=ar[b];
}
void quicksort(int arr[N],int f, int l){
    if(f<l){
        int pivot=arr[f],i=f,j=l;
        while(i<j){
            while(arr[i]<=pivot&&i<l){
                i++;
            }
            while(arr[j]<=pivot&&j>f){
                j--;
            }
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,f,j-1);
        quicksort(arr,f,j-1);
        quicksort(arr,j+1,l);
    }
}
int main(){
    int i,a[N];
    for(i=0;i<N;i++){
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
    quicksort(a,0,N-1);
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
}
