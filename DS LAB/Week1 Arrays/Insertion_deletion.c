#include<stdio.h>
#include<stdlib.h>

int *arr, pos, c, n, v, d;

void add()
{
    printf("\nEnter number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements: \n");
    arr=(int*)calloc(n,sizeof(int));
    for (c = 0; c < n; c++)
    {
        scanf("%d",&arr[c]);
    }
}

void del()
{
    printf("\nEnter the element to delete: ");
    scanf("%d",&d);
    for(c = 0; c < n;c++)
    {
        if(arr[c]==d)
            pos=c;
    }
    for(c=pos;c<n-1;c++)
    {
        arr[c]=arr[c+1];
    }
    n--;
    printf("\nResultant array is: ");
    for (c = 0; c < n; c++)
        printf("%d ",arr[c]);
}

void insert()
{
    printf("\nEnter the location(not index) where you wish to insert an element(1 - %d): ",n+1);
    scanf("%d",&pos);
    printf("Enter the value to insert: ");
    scanf("%d",&v);
    for (c = n - 1; c >= pos - 1; c--)
    {
        arr[c+1] = arr[c];
    }
    arr[pos-1] = v;
    printf("\nResultant array is: ");
    for (c = 0; c <= n; c++)
        printf("%d ",arr[c]);
    n++;
}

void menu()
{
    int x;
    do
    {
        printf("\n1. Insert an element.");
        printf("\n2. Delete an element.");
        printf("\n3. Exit.");
        printf("\nChoose Your Option : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insert(); break;
            case 2: del(); break;
            case 3: exit(0);
            default : menu();
        }
    }while(1);
}

int main()
{
    system("cls");
    add();
    menu();
    getch();
    free(arr);
    return 0;
}
