#include<stdio.h>
typedef struct{
    char name[21];
    int rno;
    int age;
    float marks[6];
}student;

const int N=2;

void name14(student s1[N]){
    int c=0;
    printf("Students of the age 14: \n");
    while(c<N){
        if(s1[c].age==14){
            puts(s1[c].name);
            printf("\n");
        }
        c++;
    }
}
void nameeven(student s1[N]){
    int c=0;
    printf("Students having even roll numbers: \n");
    while(c<N){
        if((s1[c].rno)%2==0){
            puts(s1[c].name);
            printf("\n");
        }
        c++;
    }
}
void details(int n,student s1[N]){
    int j,ck=1;
    for(j=0;j<N&&ck==1;j++){
        if(n==s1[j].rno){
            int i;
            printf("Name: ");
            puts(s1[j].name);
            printf("\nAge: %d", s1[j].age);
            printf("\nRoll No.: %d",s1[j].rno);
            for(i=0;i<6;i++){
                printf("\nMark of sub %d: %f",i+1,s1[j].marks[i]);
            }
            ck=0;
        }
    }
}

int main(){
    student s[N];
    int i,j;
    char x;
    for(i=0;i<N;i++){
        scanf("%c",&x);
        printf("Enter the name of the student: ");
        gets(s[i].name);
        printf("Enter the roll no.: ");
        scanf("%d",&s[i].rno);
        printf("Enter the age: ");
        scanf("%d",&s[i].age);
        printf("Enter the marks: \n");
        for(j=0;j<6;j++){
            scanf("%f",&s[i].marks[j]);
        }
    }
    int n1;
    printf("Enter the roll number of the student whose details will be printed: ");
    scanf("%d",&n1);
    name14(s);
    nameeven(s);
    details(n1,s);
}
