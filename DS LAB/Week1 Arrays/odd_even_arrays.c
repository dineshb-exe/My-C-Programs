#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void indices()
{
    char s[80], s1[40]="", s2[40]="";
    int a=0,b=0,i;
    printf("\nEnter a string: "); scanf(" %[^\n]",s); //fgets(s,80,stdin);
    for(i=0;i<strlen(s);i++)
    {
        if(i%2!=0)
            s1[a++]=s[i];
        else
            s2[b++]=s[i];
    }
    printf("\nString from Odd Indices: %s",s1);
    printf("\nString from Even Indices: %s",s2);
}

void values()
{
    int arr[20];
    int n=0,i=0;
    printf("\nEnter the no. integers: "); scanf("%d",&n);
    printf("\nEnter the values: ");
    for(i=0;i<n;i++)
    {
        printf("\nElement %d: ",i+1); scanf("%d",&arr[i]);
    }
    printf("\nOdd Values: \n");
    for(i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            printf("%d\t",arr[i]);
        }
    }
    printf("\nEven Values: \n");
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            printf("%d\t",arr[i]);
        }
    }
}

int main()
{
    int choice=0;
    do
    {
        printf("\n1. Split Odd - Even Indices (Char Array)");
        printf("\n2. Split Odd - Even Values (Integer Array)");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: indices(); getch(); break;
            case 2: values(); getch(); break;
            case 3: exit(0); break;
            default: printf("\nInvalid."); getch();
        }
    }while(1);
    return 0;
}
