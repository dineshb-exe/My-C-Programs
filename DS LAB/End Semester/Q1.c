#include<stdio.h>
#include<string.h>


struct time1{
    float h;
    int m;
    int s;
};
typedef struct time1 time;

struct lib_entry{
    char name1[21];
    time t;
    int e;
};

typedef struct lib_entry entry;

const int N=5;

entry q[5];
int f=-1,r=-1;

void create(entry e){
    if(f==-1){
        f+=1;
        r+=1;
        strcpy(q[r].name1,e.name1);
        q[r].t.h=e.t.h;
        q[r].t.m=e.t.m;
        q[r].t.s=e.t.s;
    }
    else{
        printf("Queue Already Exists!!\n");
    }
}
void enqueue(entry e){
    if(r==N-1){
        printf("Queue Overflow\n");
    }
    else{
        r=r+1;
        strcpy(q[r].name1,e.name1);
        q[r].t.h=e.t.h;
        q[r].t.m=e.t.m;
        q[r].t.s=e.t.s;
        if(f==-1){
            f+=1;
        }
    }
}
entry dequeue(){
    entry e1;
    if(f==-1){
        printf("Queue Empty!!\n");
        strcpy(e1.name1,"Not Found");
        e1.t.h=-1;
        e1.t.m=-1;
        e1.t.s=-1;
    }
    else{
        strcpy(e1.name1,q[f].name1);
        e1.t.h=q[f].t.h;
        e1.t.m=q[f].t.m;
        e1.t.s=q[f].t.s;
        if((f==N-1&&f==r)||f==r){
            f=-1;
            r=-1;
        }
        else{
            f+=1;
        }
    }
    return e1;
}
void display(){
    if(f>-1){
        int temp=f;
        int i=1;
        printf("\n");
        while(temp<=r){
            printf("Record %d: %s \nTime of Issue: %d : %d :%d \n",i,q[temp].name1,q[temp].t.h,q[temp].t.m,q[temp].t.s);
            temp++;
            i++;
        }
    }
    else{
        printf("Queue Empty!!");
    }
}
int main(){
    entry e1[N],e2,ex;
    strcpy(ex.name1,"Unknown");
    ex.t.h=-1;
    ex.t.m=-1;
    ex.t.s=-1;
    int ch;
    int j;
    char junk;
    for(j=0;j<N;j++){
        scanf("%c",&junk);
        printf("Enter the name of the book number%d : ",j+1);
        gets(e1[j].name1);
        printf("Enter the hour part of the time: ");
        scanf("%f",&e1[j].t.h);
        printf("Enter the minute part of the time: ");
        scanf("%d",&e1[j].t.m);
        printf("Enter the seconds part of the time: ");
        scanf("%d",&e1[j].t.s);
        e1[j].e=0;
    }
    for(j=0;j<N;j++){
        e1[j].t.h+=(e1[j].t.m/60)+(e1[j].t.s/60);
    }
    do{
        printf("MENU:\nPress 1 to create a queue\nPress 2 to add any element into the queue\nPress 3 to process the front most element\nPress 4 to view the recently processed record\nPress 5 to display all the values in the queue\nPress 6 to exit\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1){
            int min1=e1[0].t.h,min_index=0;
            for(j=0;j<5;j++){
                if(e1[j].t.h<min1&&e1[j].e==0){
                    min_index=j;
                    min1=e1[j].t.h;
                    e1[j].e=1;
                }
            }
            e1[j].e=1;

            create(e1[min_index]);
        }
        else if(ch==2){
            int min1=e1[0].t.h,min_index=0;
            for(j=0;j<5;j++){
                if(e1[j].t.h<min1&&e1[j].e==0){
                    min_index=j;
                    min1=e1[j].t.h;
                    e1[j].e=1;
                }
            }
            e1[j].e=1;

            enqueue(e1[min_index]);
            printf("Record Inserted: %s Time of entry: %d : %d : %d\n",e1[min_index].name1,e1[min_index].t.h,e1[min_index].t.m,e1[min_index].t.s);
        }
        else if(ch==3){
            ex=dequeue();
        }
        else if(ch==4){
            printf("Recent Record: %s Time of entry: %d : %d : %d\n",ex.name1,ex.t.h,ex.t.m,ex.t.s);
        }
        else if(ch==5){
            printf("\nRecords currently present in the queue\n");
            display();
            printf("\n");
        }
        printf("\n");
    }while(ch>0&&ch<=5);
}
