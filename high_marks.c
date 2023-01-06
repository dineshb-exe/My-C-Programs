#include<stdio.h>
const int M=2;
const int N=6;
int main(){
    int a[M][N],i,j;
    for(i=0;i<M;i++){
        printf("Enter the marks for student %d: \n",i+1);
        for(j=0;j<N;j++){
           printf("Subject %d: ",j+1);
           scanf("%d",&a[i][j]);
        }
    }
    int max_mark=a[0][0],i1=0,j1=0;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++)
        if(a[i][j]>max_mark){
            max_mark=a[i][j];
            i1=i;
            j1=j;
        }
    }
    printf("The maximum marks %d is scored by student %d in subject %d",max_mark,i1+1,j1+1);
}
