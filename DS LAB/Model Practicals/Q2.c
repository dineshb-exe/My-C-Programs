//Sri:
#include<stdio.h>
#include<string.h>
struct emp_issue{
    char ename[21];//Employee Name
    char edesc[21];//Employee Description
    char eissue[250];//Issue
};
typedef struct emp_issue issue;

struct node{
    issue d;
    struct node* next;
};
typedef struct node node;

node* fm=NULL,*rm=NULL;
node* f1=NULL,*r1=NULL;
node* f2=NULL,*r2=NULL;
node* f3=NULL,*r3=NULL;

void enqueue(node** f, node** r,issue x){
    node* n=(node*)malloc(sizeof(node));
    if(n){
        strcpy(n->d.ename,x.ename);
        strcpy(n->d.edesc,x.edesc);
        strcpy(n->d.eissue,x.eissue);
        n->next=NULL;
        if(*f==NULL){
            *f=n;
            *r=n;
        }
        else{
            (*r)->next=n;
            (*r)=n;
        }
    }
    else{
        printf("Queue Overflow!!");
    }
}

void dequeue(node**f,node**r,issue *x){
    if(f){
        node* n=*f;
        strcpy(x->ename,(*f)->d.ename);
        strcpy(x->edesc,(*f)->d.edesc);
        strcpy(x->eissue,(*f)->d.eissue);
        (*f)=(*f)->next;
        free(n);
        if((*f)==NULL)
            (*r)=NULL;
    }
    else{
        printf("Queue Underflow");
    }
}

int main(){
    char c,junk;
    do{
        scanf("%c",&junk);
        printf("Press 1 if you have any issue\nPress 2 to return the first issue in the queue\nPress 3 to segregate the issues\nPress 4 to view segregated issues\nPress 5 to exit: ");
        scanf("%c",&c);
        if(c=='1'){
            issue x;
            scanf("%c",&junk);
            printf("Enter the name of the employee: ");
            gets(x.ename);
            printf("Enter the description of the employee: ");
            gets(x.edesc);
            printf("Enter the issue: ");
            gets(x.eissue);
            enqueue(&fm,&rm,x);
        }
        else if(c=='2'){
            issue x1;
            dequeue(&fm,&rm,&x1);
            printf("\nEmployee Name: ");
            puts(x1.ename);
            printf("Employee Description: ");
            puts(x1.edesc);
            printf("Employee Issue: ");
            puts(x1.eissue);
        }
        else if(c=='3'){
            printf("Categories");
        }
        else if(c=='4'){
            printf("Categories");
        }
    }while(c>'0'&&c<'5');
    issue x;
    while(fm!=0){
        dequeue(&fm,&rm,&x);
    }
}
