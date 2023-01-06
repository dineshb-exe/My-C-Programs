#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int count;

struct node
{
	int data;
	struct node *next;
};
typedef struct node queue;

queue *ptr, *f=NULL, *r=NULL;

void enqueue()
{
	queue* newnode=(queue*)malloc(sizeof(queue));
	ptr=newnode;
	if(!ptr)
	{
		printf("\nQueue Overflow! \nTry Again Later:( ");
	}
	else
	{
		printf("\nEnter The Data: ");;
		scanf("%d",&ptr->data);
		ptr->next=NULL;
		if(!f)
			f=ptr;
		else
			r->next=ptr;
		r=ptr;
		count++;
		printf("\nElement Inserted Into Queue Successfully!");
	}
}

void dequeue()
{
	ptr=f;
	int del;
	if(!ptr)
	{
		printf("\nQueue Underflow! \nTry Again Later:( ");
	}
	else
	{
	    del=f->data;
		f=f->next;
		ptr->next=NULL;
		count--;
		free(ptr);
		printf("\n%d Has Been Successfully Deleted!",del);
	}
}

void display()
{
	ptr=f;
	if(!ptr)
	{
		printf("\nQueue Underflow! \nTry Again Later After Inserting New Elements.");
	}
	else
	{
		printf("\nQueue Elements: ");
		while(ptr)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}

void front()
{
    ptr=f;
    if(!ptr)
	{
		printf("\nQueue Underflow! \nTry Again Later After Inserting New Elements.");
	}
	else
	{
		printf("\n Front Element: ");
        printf("%d ",ptr->data);
	}
}

void rear()
{
    ptr=r;
    if(!ptr)
	{
		printf("\nQueue Underflow! \nTry Again Later After Inserting New Elements.");
	}
	else
	{
		printf("\n Rear Element: ");
		printf("%d ",ptr->data);
	}
}

void isempty()
{
    ptr=f;
    if(!ptr)
    {
        printf("\nYes, the Queue is Empty.");
    }
    else
    {
        printf("\nNo, the Queue is not Empty. It has %d elements.",count);
    }
}

int menu()
{
	int op;
	do
	{
		printf("\nQueue Operations: ");
		printf("\n1. EnQueue.");
		printf("\n2. DeQueue.");
		printf("\n3. Display Queue.");
		printf("\n4. Display Front.");
		printf("\n5. Display Rear.");
		printf("\n6. Is The Queue Empty?");
		printf("\n7. Exit.");
		printf("\nEnter Your Option: ");
		scanf("%d",&op);
		switch(op)
		{
		    case 1: enqueue(); break;
		    case 2: dequeue(); break;
		    case 3: display(); break;
		    case 4: front(); break;
		    case 5: rear(); break;
		    case 6: isempty(); break;
		    case 7: exit(0); break;
		    default: printf("\nInvalid.");
		}
    }while(1);
	return 0;
}
int main()
{
	menu();
	getch();
    return 0;
}
