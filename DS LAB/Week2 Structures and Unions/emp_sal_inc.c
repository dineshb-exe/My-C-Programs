#include<stdio.h>
#include<stdlib.h>

int c=0,n;        //global variable to count the no. of structures

typedef struct          //the global structure
{
    char name[15];
    float salary;
    int hours;
}employee;

employee *emp;
void addemp()           //adding new employee record, one at a time
{
    system("cls");
    if(c<n)             //constraint necessary for simplicity
    {
        char str[15];
        printf("\nEnter the name of the employee: "); scanf(" %[^\n]",(emp+c)->name);//fgets(emp[c].name,15,stdin);
        printf("\nEnter the current salary: "); scanf("%f",&(emp+c)->salary);
        printf("\nEnter the no. of hours working per day: "); scanf("%d",&(emp+c)->hours);
        c++;
    }
    else        //error message
    {
        printf("\nLimit reached.");
    }

}

void display()          //displaying all records
{
    system("cls");
    if(c==0)
    {
        printf("\nNo records present to display."); getch();
    }
    else
    {
        printf("\nDisplaying Employee Details: ");
        int i=0;
        for(i=0;i<c;i++)
        {
            printf("\n\nDetails of Employee %d:",i+1);
            printf("\nName: %s",(emp+i)->name);
            printf("\nSalary: %f",(emp+i)->salary);
            printf("\nWorking hours per day: %d",(emp+i)->hours);
        }
    }
}

void update()           //to update the salary of the records
{
    int i=0,up=0,choose=0;      //iteration variable, updating variable, choosing variable
    if(c==0)
    {
        printf("\nNo records available to update salary."); getch();
    }
    else
    {
        printf("\nUpdate One Employee(1) or All Employees (2)? (Choose 1/2): ");
        scanf("%d",&choose);        //choosing between 1 or 2
        if(choose==2)
        {
            for(i=0;i<c;i++)        //updating all records
            {
                if((emp+i)->hours <= 8)
                    (emp+i)->salary += 50;
                else if((emp+i)->hours >8 && (emp+i)->hours <12)
                    (emp+i)->salary += 100;
                else if(emp[i].hours >=12)
                    (emp+i)->salary +=150;
            }
            printf("\nUpdating employee details....."); getch();
            display(); getch();
        }
        if(choose==1)       //updating only one record
        {
            display();
            int flag = 1;
            while(flag==1)          //checking if the record to be updated is valid and existing
            {
                printf("\nEnter the Employee No. to be updated (1 - %d): ",c);
                scanf("%d",&up);
                up-=1;
                if(up>=0 && up<c)
                {
                    flag=0;
                }
                else
                {
                    printf("\nInvalid Number. Try again.");
                }
            }
            if((emp+up)->hours <= 8)
                (emp+up)->salary += 50;
            else if((emp+up)->hours >8 && (emp+up)->hours <12)
                (emp+up)->salary += 100;
            else if((emp+up)->hours >=12)
                (emp+up)->salary +=150;
            printf("\nUpdating employee details....."); getch();
            display(); getch();
        }
    }
}

int main()          //menu based program
{
    int choice = 0;
    printf("Enter the number of employees in the office: ");
    scanf("%d",&n);
    emp=(employee*)calloc(n,sizeof(employee));

    do
    {
        system("cls");
        printf("\nEmployee Details");
        printf("\n1. Enter New Employee Detail.");
        printf("\n2. Display Employee Details.");
        printf("\n3. Update Employee Salary.");
        printf("\n4. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addemp(); break;
            case 2: display(); getch(); break;
            case 3: update(); break;
            case 4: exit(0);
        }
    }while(1);
    free(emp);
    return 0;
}
