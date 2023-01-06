#include<stdio.h>
struct nodec{
    char op;
    struct nodec* next;
};
typedef struct nodec nodec;

nodec* top=NULL;

void pushc(char v){
    nodec* tmp;
    tmp=(nodec*)malloc(sizeof(nodec));
    if(tmp==NULL){
        printf("Stack Overflow!!!\n");
    }
    else{
        tmp->op=v;
        tmp->next=top;
        top=tmp;
    }
}

char popc(){
    if(top==NULL){
        printf("Stack Underflow!!\n");
        char v=0;
        return v;
    }
    else{
        char v;
        nodec* tmp=top;
        v=top->op;
        top=top->next;
        free(tmp);
        return v;
    }
}

int main(){
    char *buffer,junk,v;
    int n,ch,i=0;
    printf("Enter the maximum capacity of the buffer: ");
    scanf("%d",&n);
    buffer=(char*)malloc(n*sizeof(char));
    scanf("%c",&junk);
    printf("Enter the expression in infix format: ");
    gets(buffer);
    printf("\nPostFix Expression: ");
    while(buffer[i]!=0){
        if((buffer[i]>=65&&buffer[i]<=91)||(buffer[i]>=97&&buffer[i]<=123))
            printf("%c ",buffer[i]);
        else{
            if(top==NULL||buffer[i]=='('){
                pushc(buffer[i]);
            }
            else{
                if(buffer[i]=='^'){
                    while(top!=NULL&&top->op=='^'){
                        v=popc();
                        printf("%c",v);
                    }
                    pushc('^');
                }
                else if(buffer[i]=='+'||buffer[i]=='-'){
                    while((top!=NULL)&&(top->op=='+'||top->op=='-'||top->op=='*'||top->op=='/'||top->op=='%'||top->op=='^'))
                        printf("%c ",popc());
                    pushc(buffer[i]);
                }
                else if(buffer[i]=='*'||buffer[i]=='/'||buffer[i]=='%'){
                    while((top!=NULL)&&(top->op=='*'||top->op=='/'||top->op=='%'||top->op=='^'))
                        printf("%c ",popc());
                    pushc(buffer[i]);
                }
                else if(buffer[i]==')'){
                    while(top->op!='('){
                        printf("%c ",popc());
                    }
                    if(top->op=='('){
                        v=popc();
                    }
                }
            }
        }
        i++;
    }
    while(top!=NULL){
        printf("%c ",popc());
    }
    free(buffer);
}
