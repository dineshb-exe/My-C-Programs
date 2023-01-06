
#include<stdio.h>
const int N=10;
int main(){
    int a[N][N],b[N][N],r1,r2,c1,c2,i,j,k;
    do{
        printf("Enter the number of rows of matrix 1(Max Limit: %d):",N);
        scanf("%d",&r1);
    }
    while(r1>N);
    do{
        printf("Enter the number of columns of matrix 1 (Max Limit: %d): ",N);
        scanf("%d",&c1);
    }
    while(c1>N);
    do{
        printf("Enter the number of rows of matrix 2 (Max Limit: %d): ",N);
        scanf("%d",&r2);
    }
    while(r2>N);
    do{
        printf("Enter the number of columns of matrix 2 (Max Limit: %d): ",N);
        scanf("%d",&c2);
    }
    while(c2>N);
    if(r2!=c1){
        printf("Multiplication cannot be done!!!!");
    }
    else{
        printf("Enter the elements of the 1st Matrix: \n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter the elements of the 2nd Matrix: \n");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                scanf("%d",&b[i][j]);
            }
        }
        int c[r1][c2];
        for(i=0;i<r1;i++){
            for(j=0;j<r2;j++){
                c[i][j]=0;
            }
        }
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                for(k=0;k<r2;k++){
                    c[i][j]+=(a[i][k]*b[k][j]);
                }
            }
        }
        printf("Resultant Matrix: \n");
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++)
                printf("%d\t",c[i][j]);
            printf("\n");
        }
    }
}
