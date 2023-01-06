#include<stdio.h>
const int N=6;
int main(){
    int a[N][N],i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j)
                a[i][j]=0;
            else if(i<j)
                a[i][j]=1;
            else
                a[i][j]=-1;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(j!=0&&(a[i][j]==0||a[i][j]==1))
            printf(" ");
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
