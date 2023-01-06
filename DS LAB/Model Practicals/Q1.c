//Sri:
#include<stdio.h>

struct node{
    int d;
    struct node* next;
};
typedef struct node node;

node* head=NULL;

void create(){
    int num,i;
    printf("Enter the number of elements you want on the list: ");
    scanf("%d",&num);
    node* t=head,*n=NULL;
    for(i=1;i<=num;i++){
        n= (node*)malloc(sizeof(node));
        if(n!=NULL){
            printf("Enter a number: ");
            scanf("%d",&(n->d));
            n->next=NULL;
            if(i==1){
                head=n;
            }
            else{
                t->next=n;
            }
            t=n;
        }
        else{
            printf("Memory Allocation Failed!\n");
        }
    }
}

node* findmax(node* h){
    node* t=h;
    node* max=h;
    if(h!=NULL){
        while(t!=NULL){
            if(t->d>max->d){
                max=t;
            }
            t=t->next;
        }
    }
    else{
        printf("List Empty!!\n");
    }
    return max;
}

void insert1(node* h){
    node* n=(node*)malloc(sizeof(node));
    if(n==NULL){
        printf("Error: Unable to allocate memory!!\n");
    }
    else{
        printf("Enter the value: \n");
        scanf("%d",&(n->d));
        node* m=findmax(h);
        n->next=m->next;
        m->next=n;
    }
}

node* findmin(node* h){
    node* t=h;
    node* min=h;
    if(h!=NULL){
        while(t!=NULL){
            if(t->d<min->d){
                min=t;
            }
            t=t->next;
        }
    }
    else{
        printf("List Empty\n");
    }
    return min;
}

void del(node* h){
    int v;
    node *m=findmin(h);
    if(m!=h){
        node* t1=h;
        while(t1->next!=m){
            t1=t1->next;
        }
        if(t1!=h){
            node* t2=h;
            while(t2->next!=t1){
                t2=t2->next;
            }
            t2->next=m;
            v=t1->d;
            t1->next=NULL;
            free(t1);
            printf("%d deleted\n",v);
        }
        else{
            head=m;
            v=t1->d;
            t1->next=NULL;
            free(t1);
            printf("%d deleted\n",v);
        }
    }
    else{
        printf("The minimum element is found in the 1st value. There is no node before that to be deleted\n");
    }
}

void display(node* h){
    node*t=h;
    if(h==NULL){
        printf("List Empty!!\n");
    }
    else{
        printf("\n");
        while(t!=NULL){
            printf("%d->",t->d);
            t=t->next;
        }
        printf("\n");
    }
}

int main(){
    int c;
    do{
        printf("Enter 1 to create a list\nEnter 2 to insert a value\nEnter 3 to delete\nEnter 4 to display existing values\nEnter 5 to exit: ");
        scanf("%d",&c);
        if(c==1){
            if(head==NULL){
                create();
            }
            else{
                printf("List already exists!!\n");
            }
        }
        else if(c==2){
            if(head!=NULL){
                insert1(head);
                printf("Number inserted\n");
            }
            else{
                printf("List Empty\n");
            }
        }
        else if(c==3){
            if(head!=NULL){
                del(head);
            }
            else{
                printf("List is empty\n");
            }
        }
        else if(c==4){
            display(head);
        }
    }while(c>0&&c<5);

    node* temp=head;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}
