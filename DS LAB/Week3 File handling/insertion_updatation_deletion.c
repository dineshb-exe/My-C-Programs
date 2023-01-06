#include<stdio.h>
#include<string.h>
FILE *fp;
struct user{
    char name[21];
    int empID;
    char ut;
    char password[21];
};
typedef struct user user;
int login(){
    int n,i=-1,co=0;
    char p,arr[21];
    char pass[21];
    user u1;
    fp=fopen("Employee.dat","r+");
    printf("Enter your empID: \n");
    scanf("%d",&n);
    printf("Enter your password: \n");
        p=getch();
        if(p!='\b'&&p!='\r')
        printf(".");
        while(p=='\b'||p=='\r'){
            printf("\b");
            p=getch();
            if(p!='\b'&&p!='\r')
				printf(".");
        }
			while(p!='\r'&&co<21){
				if((p>='a'&&p<='z')||(p>='A'&&p<='Z')||(p>='0'&&p<='9'))
				pass[co]=p;

				co++;
				p=getch();
				if(p!='\b'||co<=0)
				printf(".");
				if(p=='\b'&&co>0)
        		{
        		    printf("\b \b");
        		    co-=2;
        		}
				if(p=='\b'&&co==0)
				co=0;

			}

			pass[co]='\0';
            fseek(fp,(n-1)*sizeof(user),SEEK_SET);
			fread((char *)&u1,sizeof(user),1,fp);
			fclose(fp);
			if(strcmp(pass,u1.password)==0)
                return 1;
            else
                return 0;

}

void insert_record(){
    fp=fopen("Employee.dat","r+");
    user u1;
    char x,p;
    printf("Enter your name: ");
    gets(u1.name);
    printf("Enter the employeeID: ");
    scanf("%d",&u1.empID);
    scanf("%c",&x);
    printf("Enter the type of the user: ");
    scanf("%c",&p);
    u1.ut=p;
    printf("Enter the password: ");
    p=getch();
    if(p!='\b'&&p!='\r')
    printf(".");
    while(p=='\b'||p=='\r'){
        printf("\b");
        p=getch();
        if(p!='\b'&&p!='\r')
            printf(".");
    }
    int co=0;
    while(p!='\r'&&co<21){
        if((p>='a'&&p<='z')||(p>='A'&&p<='Z')||(p>='0'&&p<='9'))
            u1.password[co]=p;

            co++;
            p=getch();
            if(p!='\b'||co<=0)
            printf(".");
            if(p=='\b'&&co>0){
                printf("\b \b");
                co-=2;
            }
            if(p=='\b'&&co==0)
            co=0;

        }
        u1.password[co]='\0';

    fseek(fp,(u1.empID-1)*sizeof(user),SEEK_SET);
    fwrite((char* )&u1,sizeof(user),1,fp);
    fclose(fp);
}
void delete_record(){
    fp=fopen("Employee.dat","r+");
    FILE *ft;
    user u;
    int f=0;
    char x[21];
    ft=fopen("Temp.dat","w");
    printf("Enter the name of the employee to be deleted: ");
    gets(x);
    while(!feof(fp)){
        fread((char*)&u,sizeof(user),1,fp);
        if(strcmp(x,u.name)==0)
            f=1;
    }
    fseek(fp,0,SEEK_SET);
    if(f==1){
        while(!feof(fp)){
            fread((char*)&u,sizeof(u),1,fp);
            if(strcmp(u.name,x)!=0){
                fwrite((char*)&u,sizeof(user),1,ft);
            }
            else{
                strcpy(u.name,"Unknown");
                u.ut='X';
                strcpy(u.password,"Unknown");
                fwrite((char*)&u,sizeof(u),1,ft);
            }
        }
        fclose(fp);
        fclose(ft);
        remove("Employee.dat");
        rename("Temp.dat","Employee.dat");
    }
    else
        printf("The employee does not exist ");

}
void view_record(){
    int v;
    user u;
    fp=fopen("Employee.dat","r+");
    printf("\nEnter the empID of the employee whose record is to be displayed: ");
    scanf("%d",&v);
    fseek(fp,(v-1)*sizeof(user),SEEK_SET);
    fread((char*)&u,sizeof(user),1,fp);
    printf("Deatils: \nName: ");
    puts(u.name);
    printf("\n");
    if(u.ut=='A')
        printf("User Type: Admin\n");
    else
        printf("User Type: Clerk\n");
    printf("Employee ID: %d\n",u.empID);
    fclose(fp);
}
int main(){
    //switch()
    int ch,ch2;
    char c;
    do{
        printf("Enter 1 to register: \n");
        printf("Enter 2 to login: \n");
        printf("Enter 3 to Exit: \n");
        scanf("%d",&ch);
        scanf("%c",&c);
        if(ch==1){
            insert_record();
            printf("\n");
        }
        else if(ch==2){
            if(login()==1){
                do{
                    printf("\nSuccess!!!!!\n");
                    printf("\n");
                    printf("Enter 1 to view a record: \n Enter 2 to delete a record: \n Enter 3 to logout: ");
                    scanf("%d",&ch2);
                    scanf("%c",&c);
                    if(ch2==1)
                    view_record();
                    else if(ch2==2)
                    delete_record();
                    printf("\n");
                }
                while(ch2>=1&&ch2<=2);
            }
            else{
                printf("\nNo existence of user\n\n");
            }
        }
    }
    while(ch>=1&&ch<=2);
    return 0;
}
