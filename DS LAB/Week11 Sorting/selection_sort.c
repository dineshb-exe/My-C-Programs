#include<stdio.h>

struct node{
    int d;
    struct node* next;
};

typedef struct node node;

void swap1(int *a,int *b){
    (*a)+=(*b);
    (*b)=(*a)-(*b);
    (*a)=(*a)-(*b);
}

int Sorted(node* h){
    node* t=h;
    int ch=1;
    while(t!=NULL&&ch==1){
        if(t->next!=NULL){
            if(t->d>(t->next)->d)
                ch=0;
        }
        t=t->next;
    }
    return ch;
}

void SelectionSort(node *h){
    node* t=h;
    int ch2=0;
    while(t->next!=NULL&&ch2==0){
       node* min=t;
       node* t2=t->next;
       while(t2!=NULL){
            if(t2->d<min->d)
                min=t2;
            t2=t2->next;
       }
       swap1(&min->d,&t->d);
       t=t->next;
       ch2=Sorted(h);
    }
}

int main(){
    int n1;
    node* head=NULL,*t=NULL, *n=NULL;
    printf("Enter the number of elements: ");
    scanf("%d",&n1);
    int j=0;
    head=(node*)malloc(sizeof(node));
    if(head!=NULL){
        printf("Enter an element: ");
        scanf("%d",&head->d);
        head->next=NULL;
        t=head;
        for(j=1;j<n1;j++){
            n=(node*)malloc(sizeof(node));
            if(n!=NULL){
                printf("Enter a number: ");
                scanf("%d",&n->d);
                n->next=NULL;
                t->next=n;
                t=n;
            }
            else{
                printf("Memory Allocation Failed!!");
                j--;
            }
        }
    }
    else{
        printf("Memory Allocation Failed!!! ");
    }
    t=head;
    printf("\nThe elements before sorting: ");
    while(t!=NULL){
        printf("%d ",t->d);
        t=t->next;
    }
    printf("\n");
        t=head;
    SelectionSort(head);
    t=head;
    printf("\nThe elements after sorting: ");
    while(t!=NULL){
        printf("%d ",t->d);
        t=t->next;
    }
    printf("\n");
    while(t!=NULL){
        head=t;
        t=t->next;
        free(head);
    }
}
