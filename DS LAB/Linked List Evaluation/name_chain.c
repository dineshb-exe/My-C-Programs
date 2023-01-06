#include<stdio.h>
#include<string.h>
struct node{
    char data;
    struct node* next;
};
typedef struct node node;
int sizecalc(node* head){
    int i=0;
    node* temp=head;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
}
void Sort(node* head,int s){
    node* temp1=head;
    while(temp1!=NULL){
        printf("%c\t",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
    int i,j;
    node* i1,*j1;
    char x;
    i1=head;
    j1=head;
    for(i=0;i<s;i--){
        for(j=0;j<s-1-i;j++){
           if((j1->data)>(j1->next)->data){
                x=j1->data;
                j1->data=(j1->next)->data;
                (j1->next)->data=x;
            }
            j1=j1->next;
        }
        i1=i1->next;
    }
    node* temp2=head;
    while(temp2!=NULL){
        printf("%c\t",temp2->data);
        temp2=temp2->next;
    }
}
int main(){
    char *name,junk;
    int len,i,j=1,f1=0,f2=0;
    do{
        printf("Enter the length of your name (inclusive of initials): ");
        scanf("%d",&len);
    }
    while(len<=6);//Ensuring that the length of the name is at least 6
    len++;
    scanf("%c",&junk);
    name=(char *)malloc((len)*sizeof(char));
    do{
        f1=0;
        printf("Enter the name without full stops/spaces!!: ");
        gets(name);
        for(i=0;i<len;i++){
            if(name[i]=='.'||name[i]==' ')
            f1=1;
        }
    }
    while(f1==1||strlen(name)<7);
    printf("\nName Chain: ");
    puts(name);
    node *h=NULL,*n=NULL, *t=NULL,*ts=NULL;
    for(i=0;i<strlen(name);i++){
        n=(node*)malloc(sizeof(node));
        if(n==NULL){
            printf("Memory Allocation Failed!!! ");
            i--;
        }
        else{
            n->data=name[i];
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
    if(sh==NULL)
        printf("Memory Allocation Failed!! ");
    else{
        sh->data=h->data;
        sh->next=NULL;
        ts=h->next;
        t3=sh;
        for(i=1;i<strlen(name);i++){
            n=(node*)malloc(sizeof(node));
            f2=1;
            for(t2=sh;t2!=NULL&&f2==1;){
                if(t2->data==ts->data)
                    f2=0;
                t2=t2->next;
            }
            if(f2==1){
                n->data=name[i];
                n->next=NULL;
                t3->next=n;
                t3=n;
                j++;
            }

            ts=ts->next;
        }
        i=0;
        int j2=0;
        t3=sh;
        while(t3!=NULL){
            printf("%c \t",t3->data);
            t2=h;
            j2=0;
            while(t2!=NULL){
                if(t2->data==t3->data)
                printf("%d\t",j2);
                j2++;
                t2=t2->next;
            }
            t3=t3->next;
            printf("\n");
        }
    }
    //Printing Only the Distinct Vowels present Name List
    node *vow=h;
    int i2=0;
    printf("\nDistinct Vowels in List\n ");
    while(vow!=NULL){
        if(vow->data=='A'||vow->data=='E'||vow->data=='I'||vow->data=='O'||vow->data=='U'||vow->data=='a'||vow->data=='e'||vow->data=='i'||vow->data=='o'||vow->data=='u')
            printf("%c POS: %d",vow->data,i2);
        i2++;
        printf("\n");
        vow=vow->next;
    }
    //Assuming the name starts with the initial
    node *nini=h->next;
    printf("Name without Initial!!: ");
    while(nini!=NULL){
        printf("%c",nini->data);
        nini=nini->next;
    }
    printf("\n");
    //Sort
    Sort(h->next,sizecalc(h->next));
    free(name);
    t2=h;
    t3=NULL;
    while(t2!=NULL){
        t3=t2;
        t2=t2->next;
        free(t3);
    }
    t2=sh;
    while(t2!=NULL){
        t3=t2;
        t2=t2->next;
        free(t3);
    }
}
