#include<stdio.h>
const int N=100;
int main(){
    int i,id[N], sal[N],ck=0, id1;
    for(i=0;i<N;i++){
        printf("Enter the Employee ID: ");
        scanf("%d",&id[i]);
        printf("Enter the salary corresponding to that Employee ID: ");
        scanf("%d",&sal[i]);
    }
    printf("Enter the Employee ID whose salary is to be printed: ");
    scanf("%d",&id1);
    i=0;
    while(ck==0){
        if(id1==id[i]){
            printf("Salary ")
        }

    }
}
