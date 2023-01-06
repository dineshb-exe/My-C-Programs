#include<stdio.h>
struct node{
    int coef;
    int exp;
    struct node* next;
};

typedef struct node pn;

int degree(pn* p){
    pn* t=p;
    int max= p->exp;
    while(t!=NULL){
        if(t->exp>max)
            max=t->exp;
        t=t->next;
    }
    return max;
}

int main(){
    pn *p1=NULL,*p2=NULL,*t1=NULL,*n1=NULL,*t2=NULL;
    int flag1=1,i=0;
    while(flag1==1){
        if(i==0){
            n1=(pn*)malloc(sizeof(pn));
            if(n1){
                printf("Enter the coefficient of the x term: ");
                scanf("%d",&n1->coef);
                printf("Enter the exponent of the x term: ");
                scanf("%d",&n1->exp);
                n1->next=NULL;
                t1=n1;
                p1=n1;
            }
            else{
                i--;
            }
        }
        else{
            n1=(pn*)malloc(sizeof(pn));
            if(n1){
                printf("Enter the coefficient of the x term: ");
                scanf("%d",&n1->coef);
                printf("Enter the exponent of the x term: ");
                scanf("%d",&n1->exp);
                n1->next=NULL;
                t1->next=n1;
                t1=n1;
            }
            else{
                i--;
            }
        }
        printf("Do you want to continue entering the terms? Press 1 for YES and 0 for NO: ");
        scanf("%d",&flag1);
        i++;
    }
    i=0,flag1=1,n1=NULL;
    while(flag1==1){
        if(i==0){
            n1=(pn*)malloc(sizeof(pn));
            if(n1){
                printf("Enter the coefficient of the x term: ");
                scanf("%d",&n1->coef);
                printf("Enter the exponent of the x term: ");
                scanf("%d",&n1->exp);
                n1->next=NULL;
                t1=n1;
                p2=n1;
            }
            else{
                i--;
            }
        }
        else{
            n1=(pn*)malloc(sizeof(pn));
            if(n1){
                printf("Enter the coefficient of the x term: ");
                scanf("%d",&n1->coef);
                printf("Enter the exponent of the x term: ");
                scanf("%d",&n1->exp);
                n1->next=NULL;
                t1->next=n1;
                t1=n1;
            }
            else{
                i--;
            }
        }
        printf("Do you want to continue entering the terms? Press 1 for YES and 0 for NO: ");
        scanf("%d",&flag1);
        i++;
    }
    t1=p1;
    while(t1!=NULL){
        printf("Coef: %d Exp: %d\n",t1->coef,t1->exp);
        t1=t1->next;
    }
    t1=p1;
    t2=p2;
    int d1=degree(p1);
    int d2=degree(p2);
    if(d2>d1)
        i=d2;
    else
        i=d1;
    int flag2=1,flag3=1;
    while(i>=0){
        flag2=1;
        flag3=1;
        t1=p1;
        while(flag2==1&&t1!=NULL){
            if(t1->exp==i){
                flag2=0;
                continue;
            }
            t1=t1->next;
        }
        t2=p2;
        while(flag3==1&&t2!=NULL){
            if(t2->exp==i){
                flag3=0;
                continue;
            }
            t2=t2->next;
        }
        if(flag2==0&&flag3==0){
            t1->coef+=t2->coef;
            flag2=0;
        }
        if(i==2)
            printf("\n%d\n",flag2);
        else if(flag3==0&&flag2!=0){
            pn* t=p1;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=t2;
            if(p2==t2)
            p2=t2->next;
            t2->next=NULL;
        }
        i--;
    }
    t1=p1;
    while(t1!=NULL){
        printf("Coef: %d Exp: %d\n",t1->coef,t1->exp);
        t1=t1->next;
    }
    t2=p2;
    t1=p1;
    while(p1!=NULL){
        t1=p1;
        p1=p1->next;
        free(t1);
    }
    t1=p2;
    while(p2!=NULL){
        t1=p2;
        p2=p2->next;
        free(t1);
    }
}
