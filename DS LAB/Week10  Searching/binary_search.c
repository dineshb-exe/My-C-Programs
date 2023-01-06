#include<stdio.h>

int search(int *a,int l,int h, int v){
    if(l<=h){
        int mid=(l+h)/2;
        if(v==a[mid]){
            return mid;
        }
        else if(v>a[mid]){
            return search(a,mid+1,h,v);
        }
        else{
            return search(a,l,mid-1,v);
        }
    }
    else
        return -1;
}
int main(){
    int *arr=NULL,n,i,v;
    printf("Enter the number of elements to be placed in the array!!!");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
        if(i>0&&arr[i]<arr[i-1])
            i--;
    }
    printf("Enter a value to be searched: ");
    scanf("%d",&v);
    int f=search(arr,0,n-1,v);
    if(f==-1){
        printf("Element not found!!!");
    }
    else{
        printf("Element located in index %d ",f);
    }
    free(arr);
}
