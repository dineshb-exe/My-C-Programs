#include <stdio.h>
#include <stdlib.h>

#define INT_MIN 0

struct Stack {
    int top;
    int capacity;
    int* array;
};
typedef struct Stack Stack;
// function to create a stack of given capacity. It initializes size of
// stack as 0
Stack* createStack(int capacity){
    Stack* stack1 = (Stack*)malloc(sizeof(Stack));
    stack1->capacity = capacity;
    stack1->top = -1;
    stack1->array = (int*)malloc(stack1->capacity * sizeof(int));
    return stack1;
}

int isFull(Stack* s1){
    return s1->top == s1->capacity - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s1, int item){
    if (isFull(s1))
        return;
    s1->array[++s1->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* s1){
    if (isEmpty(s1))
        return INT_MIN;
    return s1->array[s1->top--];
}

int peek(Stack* s1){
    if (isEmpty(s1))
        return INT_MIN;
    return s1->array[s1->top];
}

void delete_stack(Stack *s1){
    while(!isEmpty(s1)){
        pop(s1);
    }
    printf("Stack Deleted!!!");
}

int main(){
    int ch,n;
    Stack *s;
    do{
        printf("\nEnter 1 to create a stack: \nEnter 2 to push an element\nEnter 3 to pop an element: \nEnter 4 to display the top most element: \nEnter 5 to delete the stack \nEnter 6 to exit: ");
        scanf("%d",&ch);
        if(ch==1){
            int size;
            printf("Enter the size of stack: ");
            scanf("%d",&size);
            s=createStack(size);
            printf("\n Stack Created!!");
        }
        else if(ch==2){
            printf("\nEnter the value to be pushed: ");
            scanf("%d",&n);
            push(s,n);
        }
        else if(ch==3)
            pop(s);
        else if(ch==4)
        printf("\nTop element is %d \n",peek(s));
        else if(ch==5)
            delete_stack(s);
    }
    while(ch!=6);
}
