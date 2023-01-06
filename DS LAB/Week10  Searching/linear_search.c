#include<stdio.h>

struct node{
    int d;
    struct node* next;
};
typedef struct node node;

int search(node* h, int v){
    node* t=h;
    int ch=0,i=-1;
    while(t!=NULL&&ch==0){
        //Comparison is done for every element in the list.
        //Best Case Time Complexity: O(1) if the first element is the element we require
        //Worst Case Time Complexity: O(n) if the last element is the element we need/ The element is absent
        if(t->d==v){
            ch=1;
        }
        i++;
        t=t->next;
    }
    if(ch==0)
        i=-1;
    return i;
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
    printf("\nThe elements: ");
    while(t!=NULL){
        printf("%d \t",t->d);
        t=t->next;
    }
    printf("\n");
    int v1;
    printf("Enter the number to search for: ");
    scanf("%d",&v1);
    int flag=search(head,v1);
    if(flag==-1){
        printf("Element Unavailable!!\n");
    }
    else{
        printf("Element exists at position %d",flag);
    }
    t=head;
    while(t!=NULL){
        head=t;
        t=t->next;
        free(head);
    }
}
