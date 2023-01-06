#include<stdio.h>
const int N=10;
int main(){
    int a[N];
    int i;
    printf("Enter the elements: ");
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
        while(a[i]<0||a[i]>=100){
            printf("Enter again: ");
            scanf("%d",&a[i]);
        }
    }
    int max=a[0];
    for(i=1;i<N;i++){
        if(a[i]>max)
            max=a[i];
    }
    printf("All numbers except maximum value(s) are: \n");
    for(i=0;i<N;i++){
        if(a[i]!=max)
            printf("%d\n",a[i]);
    }
}
