#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int q[5],front=-1,rear=-1,n=5;

void enqueue()
{
	int x;
	printf("\nEnter Integer To Be Inserted : ");
	scanf("%d",&x);
	if(rear==n-1)
    {
		printf("\nQueue Overflow! \nTry Again Later:( ");
    }
	else if(rear==-1)
	{
		front=rear=0;
		q[rear]=x;
        printf("\nElement Has Been Inserted! ");
	}
	else
	{
		rear++;
		q[rear]=x;
        printf("\nElement Has Been Inserted! ");
	}
}
void dequeue()
{
	int del;
	if(front==-1)
		printf("\nQueue Underflow! \nTry Again Later:( ");
	else
	{
		del=q[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
        printf("\nThe Element Deleted Is: %d\n",del);
	}
}
void display()
{
	printf("\nThe Queue Is: \n");
	for(int i=front;i<rear;i++)
		printf("%d ",q[i]);
	printf("%d\n",q[rear]);
}
void menu()
{
	int op;
	do
	{
		printf("\nQueue Operations: ");
		printf("\n1.EnQueue.");
		printf("\n2.DeQueue.");
		printf("\n3.Display Queue.");
		printf("\n4.Exit.");
		printf("\nEnter Your Option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: exit(0); break;
			default: printf("\nInvalid.");
		}
	}while(1);
}
int main()
{
	menu();
	getch();
	return 0;
}
