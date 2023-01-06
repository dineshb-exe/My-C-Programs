#include<stdio.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
typedef struct node node;
node* calcMid(node* head, node* tail){
    if(head==NULL||head==tail)
        return head;
    else{
        node* temp=head;
        node* temp2=head;
        while(temp2->next!=NULL){
            temp=temp->next;
            temp2=(temp2->next)->next;
        }
        return temp;
    }
}
void insert(node** head,node **tail, int* s1){
    node* h=*head;
    node* t=*tail;
    int s=*s1;
    node *n;
    int p,val;
    printf("Enter 1 to insert at front!! \nEnter 2 to insert at the back!! \nEnter 3 to insert at desired position");
    scanf("%d",&p);
    if(p==1){
        n=(node* )malloc(sizeof(node));
        if(n==NULL){
            printf("Memory Allocation Failed!");
        }
        else{
            int d;
            printf("Enter a value to be inserted ");
            scanf("%d",&val);
            n->data=val;
            n->prev=NULL;
            n->next=h;
            h=n;
            if(t==NULL)
                t=h;
        }
    }
    else if(p==2){
        n=(node*)malloc(sizeof(node));
        if(n==NULL){
            printf("Memory Allocation Failed!");
        }
        else{
            n->prev=t;
            printf("Enter a value to be inserted: ");
            scanf("%d",&val);
            n->data=val;
            n->next=NULL;
            t=n;
            if(h==NULL)
                h=t;
        }
    }
    else{
        n=(node*)malloc(sizeof(node));
        if(n==NULL){
            printf("Memory Allocation Failed!");
        }
        else{
            if(h==NULL){
            int d;
            printf("Enter a value to be inserted ");
            scanf("%d",&val);
            n->data=val;
            n->prev=NULL;
            n->next=h;
            h=n;
            if(t==NULL)
                t=h;
            }
            else{
                node* temp;
                temp=h;
                int i;
                printf("Enter the index where the value is to be inserted: ");
                scanf("%d",&i);
                if(i==s/2){
                    temp=calcMid(h,t);
                    printf("Enter a value: ");
                    scanf("%d",&val);
                    n->data=val;
                    n->prev=temp->prev;
                    n->next=temp;
                    (temp->prev)->next=n;
                    temp->prev=n;
                }
                else{
                    int j=0;
                    temp=h;
                    while(j<i&&temp->next!=NULL){
                        if(j==i){
                            printf("Enter a value: ");
                            scanf("%d",&val);
                            n->prev=temp->prev;
                            n->next=temp;
                            (temp->prev)->next=n;
                            temp->prev=n;
                        }
                        j++;
                        temp=temp->next;
                    }
                }
            }
        }
    }
}

int main(){
    node** h2, **t2;
    *h2=&h1;
    *t2=&t1;
    int i1,s1;
    printf("Enter the size of the list: ");
    scanf("%d",&s1);
    for(i1=0;i1<s1;i1++)
    insert(&h2,&t2,&s1);
    node *c,*f;
    c=*h2;
    while(c!=NULL){
        printf("%d",c->data);
        c=c->next;
    }
    c=*h2;
    while(c!=NULL){
        f=c;
        c=c->next;
        free(f);
    }
}
