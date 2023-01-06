#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
int main(){
    int *a,s,i,f2,j=1;
    printf("Enter the size: ");
    scanf("%d",&s);
    a=(int*)malloc(s*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<s;i++)
        scanf("%d",&a[i]);
    node *h=NULL,*n=NULL, *t=NULL,*ts=NULL;
    for(i=0;i<s;i++){
        n=(node*)malloc(sizeof(node));
        if(n==NULL){
            printf("Memory Allocation Failed!!! ");
            i--;
        }
        else{
            n->data=a[i];
            n->next=NULL;
            if(h==NULL)
                h=n;
            else{
                t->next=n;
            }
            t=n;
        }
    }
    node *sh,*t2,*t3;
    sh=(node*)malloc(sizeof(node));
    if(sh==NULL){
        printf("Memory Allocation Failed!!");
    }
    else{
        sh->data=h->data;
        sh->next=NULL;
        ts=h->next;
        t3=sh;
        for(i=1;i<s;i++){
            n=(node*)malloc(sizeof(node));
            f2=1;
            for(t2=sh;t2!=NULL&&f2==1;){
                if(t2->data==ts->data)
                    f2=0;
                t2=t2->next;
            }
            if(f2==1){
                n->data=a[i];
                n->next=NULL;
                t3->next=n;
                t3=n;
                j++;
            }

            ts=ts->next;
        }
        i=0;
        t3=sh;
        printf("List after removal of duplicates: \n");
        while(t3!=NULL){
            printf("%d \t",t3->data);
            t3=t3->next;
            printf("\t");
        }
    }
}
