#include<stdio.h>
#include<stdlib.h>
struct nodec{
    char b;
    struct nodec* next;
};
typedef struct nodec nodec;

nodec* top=NULL;

void pushc(char v){
    nodec* tmp=NULL;
    tmp=(nodec*)malloc(sizeof(nodec));
    if(tmp==NULL){
        printf("Stack Overflow!!");
    }
    else{
        tmp->b=v;
        tmp->next=top;
        top=tmp;
    }
}
char popc(){
    if(top==NULL){
        printf("Stack Underflow!!");
        char v='\0';
        return v;
    }
    else{
        char v;
        v=top->b;
        nodec*tmp=top;
        top=top->next;
        free(tmp);
        return v;
    }
}

int main(){
    top=NULL;
    int n,i=0,ch=1;
    char *buffer,junk;
    printf("Enter the size of the buffer: ");
    scanf("%d",&n);
    buffer=(nodec*)malloc(n*sizeof(char));
    scanf("%c",&junk);
    printf("Enter a buffer of parentheses: ");
    gets(buffer);
    while(buffer[i]!=0&&ch==1){
        if(buffer[i]=='('||buffer[i]=='{'||buffer[i]=='['){
            pushc(buffer[i]);
        }
        else if(buffer[i]==')'){
            char v1;
            v1=popc();
            if(v1!='('){
                printf("\nERROR");
                ch=0;
            }
        }
        else if(buffer[i]==']'){
            char v1;
            v1=popc();
            if(v1!='['){
                printf("\nERROR\n");
                ch=0;
            }
        }
        else if(buffer[i]=='}'){
            char v1;
            v1=popc();
            if(v1!='{'){
                printf("\nERROR");
                ch=0;
            }
        }


        i++;
    }
    if(ch==1&&top==NULL){
        printf("\nParenthesis match: Perfect");
    }
    else{
        printf("\nParenthesis not matched perfectly!!");
    }
    if(top!=NULL){
        nodec*t=top;
        while(top!=NULL){
            t=top;
            top=top->next;
            free(t);
        }
    }
    free(buffer);
}
