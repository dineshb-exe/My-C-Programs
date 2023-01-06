#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int count;

struct node
{
	char name[20];
	int accno;
	float balance;
	struct node *next;
};

typedef struct node queue;

queue *ptr, *f=NULL, *r=NULL, *fd=NULL, *rd=NULL;

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
		printf("\n\nEnter The Account Holder Name: ");;
		scanf(" %[^\n]",ptr->name);
		printf("\nEnter The Account Number: ");
		scanf("%d",&ptr->accno);
		printf("\nEnter The Balance Amount: ");
		scanf("%f",&ptr->balance);
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
	    del=f->accno;
		f=f->next;
		ptr->next=NULL;
		count--;
		free(ptr);
		printf("\nAccount Number %d Has Been Successfully DeQueued!",del);
	}
}

void display()
{
	ptr=fd;
	if(!ptr)
	{
		printf("\nQueue Underflow! \nTry Again Later After Inserting New Elements.");
	}
	else
	{
		printf("\nQueue Elements: \n");
		while(ptr->next!=NULL)
		{
			printf("\nAccount Holder Name: %s",ptr->name);
			printf("\nAccount Number: %d",ptr->accno);
			printf("\nAccount Balance: %f",ptr->balance);
			printf("\n========================================");
			ptr=ptr->next;
		}
		printf("\nAccount Holder Name: %s",ptr->name);
        printf("\nAccount Number: %d",ptr->accno);
        printf("\nAccount Balance: %f",ptr->balance);
        printf("\n========================================");
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
        printf("\n=========================================");
		printf("\nFront Element: ");
		printf("\n=========================================");
        printf("\nAccount Name: %s",ptr->name);
        printf("\nAccount Number: %d",ptr->accno);
        printf("\nBalance: %f",ptr->balance);
        printf("\n=========================================");
	}
}

void withdraw()
{
    queue *p=f;
    if(!p)
    {
        printf("\nError Occurred.");
    }
    else
    {
        float change;
        printf("\nEnter the amount to withdraw: "); scanf("%f",&change);
        p->balance-=change;
        f=f->next;
        queue* newnode=(queue*)malloc(sizeof(queue));
        ptr=newnode;
        if(!ptr)
        {
            printf("\nQueue Overflow! \nTry Again Later:( ");
        }
        else
        {
            ptr=p;
            ptr->next=NULL;
            if(!fd)
                fd=ptr;
            else
                rd->next=ptr;
            rd=ptr;
        }
    }
}

void deposit()
{
    queue *p=f;
    if(!p)
    {
        printf("\nError Occurred.");
    }
    else
    {
        float change;
        printf("\nEnter the amount to deposit: "); scanf("%f",&change);
        p->balance+=change;
        f=f->next;
        queue* newnode=(queue*)malloc(sizeof(queue));
        ptr=newnode;
        if(!ptr)
        {
            printf("\nQueue Overflow! \nTry Again Later:( ");
        }
        else
        {
            ptr=p;
            ptr->next=NULL;
            if(!fd)
                fd=ptr;
            else
                rd->next=ptr;
            rd=ptr;
        }
    }
}

int menu(int n)
{
	int op,i=0;
	do
	{
	    if(i!=n)
        {
            front();
            printf("\n1. Withdraw.");
            printf("\n2. Deposit.");
        }
		printf("\n3. Display Done Operations.");
		printf("\n4. Exit.");
		printf("\nEnter Your Option: ");
		scanf("%d",&op);
		switch(op)
		{
		    case 1: withdraw(); i++; break;
		    case 2: deposit(); i++; break;
		    case 3: display(); break;
		    case 4: exit(0); break;
		    default: printf("\nInvalid.");
		}
    }while(1);
	return 0;
}

int main()
{
    int n=0,i=0;
    printf("\nEnter the number of customers in the queue: "); scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        enqueue();
    }
	menu(n);
	getch();
    return 0;
}
