#include<stdio.h>
const int N=10;
int main(){
    int a[N];
    int i;
    printf("Enter all elements: \n");
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    int pos;
    do{
        printf("Enter the position where the new element is to be added: (Choose from 0-%d): ",N-1);
        scanf("%d",&pos);
    }
    while(pos<=0||pos>=N-1);
    printf("Enter the new element: ");
    scanf("%d",&a[pos]);
    printf("Contents of the array: ");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]);

}
