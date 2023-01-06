#include<stdio.h>
#include<stdlib.h>

struct node{
    char name[21];
    struct node* next;
};
typedef struct node node;

node* head=NULL;
void create(){
    if(head==NULL){
        node* n=(node*)malloc(sizeof(node));
        if(n){
            char junk;
            scanf("%c",&junk);
            printf("Enter the name: ");
            gets(n->name);
            n->next=NULL;
            head=n;
            printf("List created!!\n");
        }
    }
    else{
        printf("List already exists\n");
    }
}
void insert(){
    if(head==NULL){
        create();
    }
    else{
        node*t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        node*n=(node*)malloc(sizeof(node));
        if(n){
            char junk;
            scanf("%c",&junk);
            printf("Enter the name: ");
            gets(n->name);
            n->next=NULL;
            t->next=n;
            t=n;
            printf("Item Inserted!!\n");
        }
    }
}
void display(){
    if(head!=NULL){
        node*t=head;
        int i=1;
        while(t!=NULL){
            printf("Name: %d",i);
            puts(t->name);
            i++;
            t=t->next;
        }
    }
    else{
        printf("List does not exist!!\n");
    }
}

int main(){
    int ch;
    head=NULL;
    do{
        printf("Enter 1 to create a list\nEnter 2 to insert an element\nEnter 3 to display\nEnter 4 to quit: ");
        scanf("%d",&ch);
        if(ch==1){
            create();
        }
        else if(ch==2){
            insert();
        }
        else if(ch==3){
            display();
        }

    }while(ch>0&&ch<4);
}
