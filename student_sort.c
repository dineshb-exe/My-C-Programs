#include<stdio.h>

typedef struct{
    char name[21];
    int rno;
    int midterm[3];
    int finale;
}student;

const int N=5;

void BubbleSort(char x[N][21],int size){
    char temp[21];
    for(i=N-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(strcmp(x[j-1],x[j])>0){
                strcpy(temp,x[j-1]);
                strcpy(x[j-1],x[j]);
                strcpy(x[j],temp);
            }
        }
    }
}

int main(){
    student s1[N];
    for(i=0;i<N;i++){
        printf("Enter the details of student %d",i+1);
        gets(s1[i].name);
        scanf("%d",s1[i].rno);
        for(j=0;j<N;j++){
            scanf("%d",&s1.[i].midterm[j]);
        }
        scanf("%d")
    }

}
