#include<stdio.h>

int partition(int *arr,int l,int h){
    int pivot=l;
    int too_big_index=l+1;
    int too_small_index=h;
    do{
        while(arr[too_big_index]<=arr[pivot]){
            ++too_big_index;
        }
        while(arr[too_small_index]>arr[pivot]){
            --too_small_index;
        }
        if(too_big_index<too_small_index){
            int t=arr[too_big_index];
            arr[too_big_index]=arr[too_small_index];
            arr[too_small_index]=t;
        }
    }while(too_small_index>too_big_index);
    int t2=arr[pivot];
    arr[pivot]=arr[too_small_index];
    arr[too_small_index]=t2;
    return too_small_index;
}
void QuickSort(int *a,int l,int h){
    if(l<h){
        int p=partition(a,l,h);
        QuickSort(a,l,p-1);
        QuickSort(a,p+1,h);
    }
}
int main(){
    int *a1=NULL,n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    a1=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Enter an element: ");
        scanf("%d",&a1[i]);
    }
    printf("The array before Sorting!!: ");
    for(i=0;i<n;i++){
        printf("%d ",a1[i]);
    }
    printf("\n");
    QuickSort(a1,0,n-1);
    printf("The array after Sorting!!: ");
    for(i=0;i<n;i++){
        printf("%d ",a1[i]);
    }
    free(a1);
}
