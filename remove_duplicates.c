#include<stdio.h>
const int N=10;
int main(){
    int a[N],b[N],t=-1,ck,i,j;
    printf("Enter the numbers of the array: \n");
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<N;i++){
        if(t==-1){
            b[++t]=a[i];
        }
        else{
            ck=1;
            for(j=0;j<=t&&ck==1;j++){
                if(b[j]==a[i])
                ck=0;
            }
            if(ck==1)
                b[++t]=a[i];
        }
    }
    printf("The array after removal of duplicates: \n");
    for(i=0;i<=t;i++){
        printf("%d \t",b[i]);
    }
}
