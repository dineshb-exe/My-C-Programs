#include<stdio.h>

struct node{
    struct node* lc;
    int data;
    struct node* rc;
};

typedef struct node node;

node* r=NULL;

node* create_node(int d){
    node* n=(node*)malloc(sizeof(node));
    n->data=d;
    n->lc=NULL;
    n->rc=NULL;
    return n;
}

void insert(int d){
    node* n=NULL;
    if(r==NULL){
        r=create_node(d);
        printf("Tree Created");
        return;
    }
    else{
        int i=0,j=0;
        node*t =r;
        printf("%d",t->data);
        while(t!=NULL){
            if(t->lc!=NULL)
                t=t->lc;
            else
            t=t->rc;
            i++;
        }
        t=r;
        while(t!=NULL){
            if(t->rc!=NULL)
                t=t->rc;
            else
                t=t->lc;
            j++;
        }
        if(i>j){
            t=r;
            t=t->rc;
            int ch=0;
            while(ch!=1){
                if(t->lc==NULL){
                    n=(node*)malloc(sizeof(node));
                    if(n==NULL){
                        printf("Memory Allocation Failed!!!");
                    }
                    else{
                        n->data=d;
                        n->lc=NULL;
                        n->rc=NULL;
                        t->lc=n;
                        ch=1;
                    }
                }
                else if(t->rc==NULL){
                    n=(node*)malloc(sizeof(node));
                    if(n==NULL){
                        printf("Memory Allocation Failed!!!");
                    }
                    else{
                        n->data=d;
                        n->lc=NULL;
                        n->rc=NULL;
                        t->rc=n;
                        ch=1;
                    }
                }
                else{
                    t=t->lc;
                }
            }
        }
        else{
            t=r;
            t=t->lc;
            int ch=0;
            while(ch!=1){
                if(t->lc==NULL){
                    n=(node*)malloc(sizeof(node));
                    if(n==NULL){
                        printf("Memory Allocation Failed!!!");
                    }
                    else{
                        n->data=d;
                        n->lc=NULL;
                        n->rc=NULL;
                        t->lc=n;
                        ch=1;
                    }
                }
                else if(t->rc==NULL){
                    n=(node*)malloc(sizeof(node));
                    if(n==NULL){
                        printf("Memory Allocation Failed!!!");
                    }
                    else{
                        n->data=d;
                        n->lc=NULL;
                        n->rc=NULL;
                        t->rc=n;
                        ch=1;
                    }
                }
                else{
                    t=t->lc;
                }

            }
        }
    }
}

void inOrderTraversal(){
    if(r==NULL){
        printf("No Val\n");
    }
    else{
        inOrderTraversal(r->lc);
        printf("%d\t",r->data);
        inOrderTraversal(r->rc);
    }
}

int main(){
    node* r=NULL;
    int c;
    do{
        printf("Enter 1 to insert a value: \nEnter 2 to display: \nEnter 3 to exit: ");
        scanf("%d",&c);
        if(c==1){
            int x;
            printf("Enter a value to be inserted!!  ");
            scanf("%d",&x);
            insert(x);
        }
        else if(c==2){
            printf("The tree: \n");
            inOrderTraversal();
        }
        printf("\n");
    }
    while(c==1||c==2);
}
