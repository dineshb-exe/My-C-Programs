#include<stdio.h>

const int N=3;

int main(){
    int a[N][N], b[N][N];
    int *pa=a, *pb=b;
    int i,j;
    int *pc;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            *((*pc+i)+j)=*(*(pa+i)+j)+*(*(pb+i)+j);
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d",*(*(pc+i)+j));
        }
    }
}
