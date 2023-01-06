#include<stdio.h>
#include<string.h>

struct node{
    char d;
    struct node* next;
};
typedef struct node node;
int main(){
    char str1[20];
    int i;
    printf("Enter the string: ");
    gets(str1);
    node *n1=NULL,*n2=NULL,*t1=NULL,*t2=NULL,*h1=NULL,*h2=NULL;
    for(i=0;i<strlen(str1);i++){
        n1=(node*)malloc(sizeof(node));
        n2=(node*)malloc(sizeof(node));
        if(n1==NULL||n2==NULL){
            printf("Memory allocation Failed!!!");
        }
        else{
            n1->d=str1[i];
            n2->d=str1[i];
            n1->next=NULL;
            n2->next=NULL;
            if(i==0){
                h1=n1;
                h2=n2;
            }
            else{
                t1->next=n1;
                t2->next=n2;
            }
            t1=n1;
            t2=n2;

        }

    }
    //Reversal of the second list
    t2=h2;
    node* t3=h2->next;
    h2=h2->next;
    t2->next=NULL;
    while(h2!=NULL){
        h2=h2->next;
        t3->next=t2;
        t2=t3;
        t3=h2;
    }
    h2=t2;
    t1=h1;
    t2=h2;
    int f=1;
    while(t1!=NULL&&t2!=NULL&&f==1){
        if(t1->d!=t2->d){
            f=0;
        }
        t1=t1->next;
        t2=t2->next;
    }
    if(f==1)
        printf("The given string is a palindrome!!!! ");
    else
        printf("The given string is not a palindrome!!! ");
    t1=h1;
    t2=h2;
    while(h1!=NULL){
        t1=h1;
        h1=h1->next;
        free(t1);
    }
    while(h2!=NULL){
        t2=h2;
        h2=h2->next;
        free(t2);
    }

}
