#include <stdio.h>

struct Node{
    int data;
    struct Node* link;
};
typedef struct Node node;
node* top;

void create(){
    if(top==NULL){
        int n;
        printf("Enter the value to be pushed: ");
        scanf("%d",&n);
        push(n);
    }
    else
        printf("\nStack Already Exists\n");
}

void push(int data){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    if (!temp){
        printf("\nHeap Overflow");
    }

    temp->data = data;
    temp->link = top;

    top = temp;
}

int isEmpty(){
    return (top == NULL);
}

int peek(){
    if (!isEmpty())
        return top->data;
    else
        printf("Stack Empty!!");
}

void pop(){
    node* temp;

    if (top == NULL){
        printf("\nStack Underflow\n");
    }
    else{
        temp=top;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}

void display(){
    node* temp;

    if (top == NULL){
        printf("\nStack Underflow");
    }
    else{
        temp = top;
        while (temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->link;
        }
    }
}

void delete_stack(){
    if(top==NULL){
        printf("Stack Underflow!!!!!");
    }
    else{
        while(top!=NULL){
            pop();
        }
    }
}

int main(){
    int ch,n;
    do{
        printf("\nEnter 1 to create a stack: \nEnter 2 to push an element\nEnter 3 to pop an element: \nEnter 4 to delete the stack: \nEnter 5 to display the stack: \nEnter 6 to display the top most element: \nEnter 7 to exit: ");
        scanf("%d",&ch);
        if(ch==1)
        create();
        else if(ch==2){
            printf("\nEnter the value to be pushed: ");
            scanf("%d",&n);
            push(n);
        }
        else if(ch==3)
            pop();
        else if(ch==4)
            delete_stack();
        else if(ch==5)
            display();
        else if(ch==6)
        printf("\nTop element is %d \n",peek());
    }
    while(ch!=7);
}
