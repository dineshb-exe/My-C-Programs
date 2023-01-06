#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void merge(struct node* a, struct node* l1, struct node* f2, struct node* l2,int size){
    struct node *i=a,*j=f2;
    int k=0;
    int *temp;
    temp=(int *)calloc(size,sizeof(int));
    while(i!=l1->next&&j!=l2->next){
        if(i->data<j->data){
            temp[k]=i->data;
            i=i->next;
            k++;
        }
        else{
            temp[k]=j->data;
            j=j->next;
            k++;
        }

    }
    while(i!=l1->next){
        temp[k]=i->data;
        i=i->next;
        k++;
    }
    while(j!=l2->next){
        temp[k]=j->data;
        j=j->next;
        k++;
    }
    i=a;
    int j1=0;
    while(i!=NULL&&j1<k){
        i->data=temp[j1];
        i=i->next;
        j1++;
    }
    free(temp);
    return;
}

void merge_split(struct node* a,struct node *l, int size){
    if(a!=l){
        int j,m;
        m=(size-1)/2;
        struct node* x=a;
        for(j=1;j<=m;j++){
            x=x->next;
        }
        int size2=size/2;
        struct node* x1=x->next;
        merge_split(a,x,size2);
        merge_split(x1,l,size-size2);
        merge(a,x,x1,l,size);
        return;
    }
    else{
        return;
    }
}

int main(){
    struct node *head, *tail,*temp;
    int ch,d,n,i;
    struct node* newNode;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    head=(struct node*)malloc(sizeof(struct node));
    if(!head){
        printf("Memory Allocation Failed!!!");
    }
    else{
        printf("Enter the number: ");
        scanf("%d",&d);
        head->data=d;
        head->next=NULL;
        temp=head;
    }
    for(i=1;i<n;i++){
        newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL){
            printf("Memory Allocation Failed!!!");
            i--;
        }
        else{
            printf("Enter the number: ");
            scanf("%d",&d);
            newNode->data=d;
            newNode->next=NULL;
            temp->next=newNode;
            temp=newNode;
            if(i==n-1){
                tail=temp;
                tail->next=NULL;
            }
        }
    }
    printf("Contents of the array before sorting: \n");
    struct node* t,*t1;
    for(i=0;i<n;i++){
        if(i==0){
            t=head;
        }
        printf("%d\t",t->data);
        t=t->next;
    }
    merge_split(head,tail,n);
    printf("\nContents of the array after sorting: \n");
    for(i=0;i<n;i++){
        if(i==0){
            t=head;
        }
        printf("%d\t",t->data);
        t1=t;
        t=t->next;
        free(t1);
    }

}
