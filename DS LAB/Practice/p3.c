#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 7

int push(char stack[max][80], int *top, char data[80])
{
      if(*top == max -1)
            return(-1);
      else
      {
            *top = *top + 1;
            strcpy(stack[*top], data);
            return(1);
      }
}
int pop(char stack[max][80], int *top, char data[80])
{
      if(*top == -1)
            return(-1);
      else
      {
      	    *top = *top - 1;
            strcpy(data, stack[*top]);
            *top = *top - 1;
            return(1);
      }
}
int precedence(char element[20])
{
    if(strcmp(element,"red")==0)
        return(1);
    else if(strcmp(element,"orange")==0)
        return(2);
    else if(strcmp(element,"yellow")==0)
        return(3);
    else if(strcmp(element,"green")==0)
        return(4);
    else if(strcmp(element,"blue")==0)
        return(5);
    else if(strcmp(element,"indigo")==0)
        return(6);
    else if(strcmp(element,"violet")==0)
        return(7);
}
void sortrings(char stack[max][80], int *top)
{
	int count=0,i,j;
	char s[20];
	char arr[max][20];
	char temp[20];
	for(i=*top;i>=0;i--)
	{
		strcpy(arr[i],stack[i]);
		//printf("%s",arr[i]);
		//printf("\n");
		*top=*top-1;
		count++;
	}
	//printf("%d",count);

	for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
			if(precedence(arr[i])<precedence(arr[j]))
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);
            }
        }
    }
	for(i=count;i>=0;i--)
	{
		strcpy(stack[*top], arr[i]);
		*top = *top + 1;
}
}


int display(char stack[max][80], int *top)
{
	if(*top == -1)
        return(-1);
    else{
	    int i;
	    for(i=*top-1;i>=0;i--)
	    {
		    printf("%s",stack[i]);
		    printf("\n");
	    }
	}
	return(1);
}

int main()
{
      char stack[max][80], nm[80];
      int top,ch,reply;
      top = -1;   // Initialize Stack
      printf("\tMENU\n");
      printf("1. PUSH\n");
      printf("2. POP\n");
      printf("3. DISPLAY\n");
      printf("4. EXIT\n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            switch (ch)
            {
                  case 1 : // push
                        printf("\nEnter string : ");
                        scanf("%s",nm);
                        reply = push(stack,&top,nm);
                        if(reply == -1)
                              printf("\n Stack is Full.\n");
                        else
                              printf("'%s' is Pushed in Stack.\n\n",nm);
                  break;
                  case 2 : // pop
                        reply = pop(stack,  &top,nm);
                        if(reply == -1)
                              printf("\n Stack is Empty \n");
                        else
                              printf("Popped string is : %s\n",nm);
                              printf("\n");
                  break;
                  case 3:
                  	    sortrings(stack,&top);
                  	    display(stack,&top);
                  break;
                  case 4 :
                        exit(0);
                  default:
                        printf("Invalid operation \n");
            }
      }
      return 0;
}
