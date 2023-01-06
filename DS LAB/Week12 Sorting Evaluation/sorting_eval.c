//Sri:
//B. Dinesh, 195002031
#include<stdio.h>
#include<string.h>
const int M=5;
const int N=10;

struct time1{
    int h;
    int m;
    int s;
};
typedef struct time1 time1;
int p2=0;
void SelectionSort(char a[M][N]){
    int i,j,p=0;
    for(i=0;i<M-1;i++){
        int mi=i;
        for(j=i;j<M;j++){
            if(strcmp(a[j],a[mi])<0)
                mi=j;
            p++;
        }
        char temp[N];
        strcpy(temp,a[i]);
        strcpy(a[i],a[mi]);
        strcpy(a[mi],temp);
    }
    printf("Number of key operations: %d",p);
}
int partition(char x[M][N],int l, int h){
    int pivot=l;
    int tbi=l+1;
    int tsi=h;
    do{
        while(strcmp(x[tbi],x[pivot])<=0){
            ++tbi;
        }
        while(strcmp(x[tsi],x[pivot])>0){
            ++tsi;
        }
        if(tbi<tsi){
            char temp[N];
            strcpy(temp,x[tbi]);
            strcpy(x[tbi],x[tsi]);
            strcpy(x[tsi],temp);
        }
    }while(tsi>tbi);
    char t2[N];
    strcpy(t2,x[pivot]);
    strcpy(x[pivot],x[tsi]);
    strcpy(x[tsi],t2);
    return tsi;
}
void QuickSort(char x[M][N],int l,int h){
    p2++;
    if(l<h){
        int p=partition(x,l,h);
        QuickSort(x,l,p-1);
        QuickSort(x,p+1,h);
    }
}
int main(){
    char a1[M][N],b[M][N];
    int i,j;
    for(i=0;i<M;i++){
        printf("Enter the slot timing: ");
        gets(a1[i]);
    }
    for(i=0;i<M;i++)
    strcpy(b[i],a1[i]);
    printf("\nBefore Sorting using Selection Sort: ");
    for(i=0;i<M;i++){
        printf("\nSlot Timing for Person %d: ",i+1);
        puts(a1[i]);
    }
    SelectionSort(a1);
    printf("\nAfter Sorting using Selection Sort: ");
    for(i=0;i<M;i++){
        printf("\nSlot Timing for Person %d: ",i+1);
        puts(a1[i]);
    }
    printf("\nBefore Sorting using Quick Sort: ");
    for(i=0;i<M;i++){
        printf("\nSlot Timing for Person %d: ",i+1);
        puts(b[i]);
    }
    QuickSort(b,0,M-1);
    printf("\nAfter Sorting using Quick Sort: ");
    for(i=0;i<M;i++){
        printf("\nSlot Timing for Person %d: ",i+1);
        puts(b[i]);
    }
    printf("\nNumber of recursions of Quick Sort: %d",p2);
}
