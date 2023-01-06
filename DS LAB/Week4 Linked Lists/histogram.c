#include<stdio.h>
struct node1{
    int data;
    struct node1* next;
};
typedef struct node1 node1;
struct node2{
    int d;
    int freq;
    struct node2* next;
};
typedef struct node2 node2;

int main(){
    node1 *h1=NULL,*t=NULL,*n1=NULL;
    node2 *h2=NULL,*t2=NULL,*n2=NULL,*t3=NULL;
    int i,s,v;
    printf("Enter the size");
    scanf("%d",&s);
    for(i=0;i<s;i++){
        printf("Enter the value: ");
        n1=(node1*)malloc(sizeof(node1));
        if(n1==NULL){
            printf("Memory Allocation Failed!! ");
            i--;
        }
        else{
            scanf("%d",&v);
            n1->data=v;
            n1->next=NULL;
            if(h1==NULL){
                h1=n1;
            }
            else{
                t->next=n1;
            }
            t=n1;
        }
    }
    for(t=h1;t!=NULL;t=t->next){
        n2=(node2*)malloc(sizeof(node2));
        if(n2==NULL){
            printf("Memory Allocation Failed!!! ");
        }
        else{
            if(h2==NULL){
                n2->d=t->data;
                n2->freq=1;
                n2->next=NULL;
                h2=n2;
                t2=h2;
            }
            else{
                t3=h2;
                int f1=1;
                while(t3!=NULL&&f1==1){
                    if(t3->d==t->data)
                        f1=0;
                    t3=t3->next;
                }
                if(f1==1){
                    n2->d=t->data;
                    n2->freq=1;
                    n2->next=NULL;
                    t2->next=n2;
                    t2=n2;
                }
                else{
                    t3=h2;
                    while(t3!=t2->next){
                        if(t3->d==t->data)
                            t3->freq=t3->freq+1;
                        t3=t3->next;
                    }
                    free(n2);
                }
            }
        }
    }
    t2=h2;
    printf("\nValue: Frequency:");
    while(t2!=NULL){
        printf("%d\t%d",t2->d,t2->freq);
        t2=t2->next;
        printf("\n");
    }
    t=h1;
    while(h1){
        t=h1;
        h1=h1->next;
        free(t);
    }
    while(h2){
        t3=h2;
        h2=h2->next;
        free(t3);
    }
}
