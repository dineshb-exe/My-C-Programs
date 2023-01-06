#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flagred=0,flagblue=0,flagviolet=0;

struct node
{
    char name[20];
    struct node *next;
};

typedef struct node team;

void display(team *ptr);

team *red,*blue,*violet;

void create_red()
{
    int i,flag=0; char cap[20]; team *temp;
//    printf("\nEnter the number of players in Red Team: ");
//    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        team newnode = (team)malloc(sizeof(team));
        if(i==0)
        {
            while(flag==0)
            {
                printf("\nEnter the name of Red Team Member %d: ",i+1);
                scanf(" %[^\n]",cap);
                if(cap[0]=='a' || cap[0]=='A')
                {
                    flag=1;
                }
                else
                {
                    printf("\nCaptain's Name must start with A.");
                }
            }
        }
        else if(i==4)
        {
            flag=0;
            while(flag==0)
            {
                printf("\nEnter the name of Red Team Member %d: ",i+1);
                scanf(" %[^\n]",cap);
                if(cap[0]=='z' || cap[0]=='Z')
                {
                    flag=1;
                }
                else
                {
                    printf("\nLast Member's Name must start with Z.");
                }
            }
        }
        else
        {
            printf("\nEnter the name of Red Team Member %d: ",i+1);
            scanf(" %[^\n]",cap);
        }
        strcpy(newnode->name,cap);
        newnode->next=NULL;
        if(i==0)
        {
            red=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("\nRed Team List Created.");
}

void create_blue()
{
    int i,flag=0; char cap[20]; team *temp;
//    printf("\nEnter the number of players in Blue Team: ");
//    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        team newnode = (team)malloc(sizeof(team));
        if(i==0)
        {
            while(flag==0)
            {
                printf("\nEnter the name of Blue Team Member %d: ",i+1);
                scanf(" %[^\n]",cap);
                if(cap[0]=='a' || cap[0]=='A')
                {
                    flag=1;
                }
                else
                {
                    printf("\nCaptain's Name must start with A.");
                }
            }
        }
        else if(i==4)
        {
            flag=0;
            while(flag==0)
            {
                printf("\nEnter the name of Blue Team Member %d: ",i+1);
                scanf(" %[^\n]",cap);
                if(cap[0]=='z' || cap[0]=='Z')
                {
                    flag=1;
                }
                else
                {
                    printf("\nLast Member's Name must start with Z.");
                }
            }
        }
        else
        {
            printf("\nEnter the name of Blue Team Member %d: ",i+1);
            scanf(" %[^\n]",cap);
        }
        strcpy(newnode->name,cap);
        newnode->next=NULL;
        if(i==0)
        {
            blue=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("\nBlue Team List created.");
}

void merge()
{
    team *temp1,*temp2,*temp3;
    temp1=red;
    temp2=blue;
    int i;
    for(i=0;i<5;i++)
    {
        if(i==0)
        {
            team newnode=(team)malloc(sizeof(team));
            strcpy(newnode->name,temp1->name);
            newnode->next=NULL;
            temp3=newnode;
            violet=newnode;
            team newnode2=(team)malloc(sizeof(team));
            strcpy(newnode2->name,temp2->name);
            newnode2->next=NULL;
            temp3->next=newnode2;
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else
        {
            team newnode=(team)malloc(sizeof(team));
            strcpy(newnode->name,temp1->name);
            newnode->next=NULL;
            temp3->next=newnode;
            temp3=newnode;
            team newnode2=(team)malloc(sizeof(team));
            strcpy(newnode2->name,temp2->name);
            newnode2->next=NULL;
            temp3->next=newnode2;
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    printf("\nMerged List has been created.");
    display(violet);
}

void starting_s()
{
    team *temp=violet; int i;
    printf("\n");
    for(i=1;i<11;i++)
    {
        if(temp->name[0]=='s' || temp->name[0]=='S')
        {
            printf("\nPosition: %d\tName: %s",i,temp->name);
        }
        temp=temp->next;
    }
}

void red_content()
{
    team *temp=violet; int i;
    for(i=1;i<11;i++)
    {
        if(i==2 || i==5 || i==7 || i==10)
        {
            printf("\nPosition: %d\tName: %s",i,temp->name);
        }
        temp=temp->next;
    }
}

void del (team *before_del)
{
    team *temp;
    temp = before_del->next;
    before_del->next = temp->next;
    free(temp);
}

void delred()
{
    team* temp=violet;
    int i;
    violet=violet->next;
    free(temp);
    temp=violet;
    for(i=0;i<4;i++)
    {
        del(temp);
        temp=temp->next;
    }
}

void display(team *ptr)
{
    team *temp=ptr;
    printf("\n");
    while(temp->next!=NULL)
    {
        printf("%s -> ",temp->name);
        temp=temp->next;
    }
    printf("%s",temp->name);
}

int main()
{
    int choice;
    do
    {
        printf("\n========================================================================");
        printf("\n1. Create List for Red Team.");
        printf("\n2. Create List for Blue Team.");
        printf("\n3. Insert Blue Team Member Alternatively into Red Team List.");
        printf("\n4. Display Red Team Content at 2,5,7,10 Positions.");
        printf("\n5. Display names starting with \'S\'.");
        printf("\n6. Delete Red Team Members from the Merged List.");
        printf("\n7. Display Red Team List.");
        printf("\n8. Display Blue Team List.");
        printf("\n9. Display Merged List.");
        printf("\n10. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create_red(); flagred=1; break;
            case 2: create_blue(); flagblue=1; break;
            case 3: if(flagblue==1 && flagred==1)
                    {
                        merge(); flagviolet=1;
                    }
                    else
                    {
                        printf("\nThe two teams have not been created yet.");
                    }
                    break;
            case 4: if(flagviolet==1)
                    {
                        red_content();
                    }
                    else
                    {
                        printf("\nMerged List has not been created yet.");
                    }
                    break;
            case 5: if(flagviolet==1)
                    {
                        starting_s();
                    }
                    else
                    {
                        printf("\nMerged List has not been created yet.");
                    }
                    break;
            case 6: if(flagviolet==1)
                    {
                        delred();
                        display(violet);
                    }
                    else
                    {
                        printf("\nMerged List has not been created yet.");
                    }
                    break;
            case 7: if(flagred==1)
                    {
                        display(red);
                    }
                    else
                    {
                        printf("\nData for Red Team has not been entered.");
                    }
                    break;
            case 8: if(flagblue==1)
                    {
                        display(blue);
                    }
                    else
                    {
                        printf("\nData for the Blue Team has not been entered.");
                    }
                    break;
            case 9: if(flagviolet==1)
                    {
                        display(violet);
                    }
                    else
                    {
                        printf("\nMerged List has not been created yet.");
                    }
                    break;
            case 10: exit(0); break;
            default: printf("\nInvalid.");
        }
    }while(1);
    return 0;
}
