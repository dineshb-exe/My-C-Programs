#include<stdio.h>

struct node{
    char name[31];
    int cs;
    struct node* next;
};
typedef struct node node;
int main(){
    int i;
    node *blue=NULL,*nn=NULL,*t=NULL;
    //Assumption: Each team has 11 members;
    nn=(node*)malloc(sizeof(node));
    if(nn==NULL){
        printf("Memory Allocation Failed!!!");
    }
    else{
        printf("Enter the name of the player: ");
        gets(nn->name);
        nn->cs=0;
        nn->next=NULL;
        blue=nn;
        t=nn;
    }
    for(i=1;i<11;i++){
        nn=(node*)malloc(sizeof(node));
        if(nn==NULL){
            printf("Memory Allocation Failed!!!");
        }
        else{
            printf("Enter the name of the player: ");
            gets(nn->name);
            nn->cs=0;
            nn->next=NULL;
            t->next=nn;
            t=nn;
        }
    }
    int f=1;
    char cap[31];
    printf("Enter the name of the captain of the blue team: ");
    gets(cap);
    t=blue;
    while(f==1&&t!=NULL){
        if(strcmp(t->name,cap)==0){
            t->cs=1;
            f=0;
        }
        t=t->next;
    }
    t=blue;
    i=1;
    while(t!=NULL){
        printf("%d: ",i);
        printf("%s",t->name);
        if(t->cs==1)
            printf(" (c)");
        printf("\n");
        t=t->next;
        i++;
    }
    node *red=NULL, *nr=NULL, *t2=NULL;
    nr=(node*)malloc(sizeof(node));
    if(nr==NULL){
        printf("Memory Allocation Failed!!!");
    }
    else{
        do{
            printf("Enter the name of the captain: ");
            gets(nr->name);
        }
        while(nr->name[0]!='A');
        nr->cs=1;
        nr->next=NULL;
        red=nr;
        t2=nr;
    }
    t=blue->next;
    node *t3=blue;
    for(i=1;i<11;i++){
        if(i%2==0){
            nr=(node*)malloc(sizeof(node));
            if(nr==NULL){
                printf("Memory Allocation Failed!!!");
            }
            else{
                do{
                    printf("Enter the name of the player: ");
                    gets(nr->name);
                }
                while(i==9&&nr->name[0]!='Z');
                nr->cs=0;
                nr->next=NULL;
                t2->next=nr;
                t2=nr;
                t=t->next;
                t3=t3->next;
            }

        }
        else{
            t2->next=t;
            t2=t;
            t3->next=t->next;
            t2->next=NULL;
            t=t->next;
        }
        t=t->next;
        t3=t3->next;
        printf("Yayyyyy");
    }
    t=red;
    i=1;
    while(t!=NULL){
        if(i==2||i==5||i==7||i==10){
            printf("%d: ",i);
            printf("%s",t->name);
            if(t->cs==1)
                printf(" (c)");
            printf("\n");
        }
        t=t->next;
        i++;
    }
    i=0;
    t=red;
    printf("\nPositions of Players with S as starting letter: \n");
    while(t!=NULL){
        if(t->name[0]=='S'){
            printf("%d \n",i);
        }
        i++;
        t=t->next;
    }
    i=1;
    t2=blue;
    t3=blue;
    while(1<=11){
        if(i%2!=0){
            t=red;
            red=red->next;
            free(t);
        }
        else{
            t=red;
            t3->next=t;
            red=red->next;
            t->next=t2;
        }
        t2=t2->next;
        if(i>1)
            t3=t3->next;
        i++;
    }
    while(blue!=NULL){
        t=blue;
        blue=blue->next;
        free(t);
    }

}
