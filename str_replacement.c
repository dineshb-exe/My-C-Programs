#include<stdio.h>
#include<string.h>
int main(){
    char name[21],str2[10],str3[10],name2[21];
    printf("Enter a string: ");
    gets(name);
    printf("Enter a sub-string: ");
    gets(str2);
    printf("Enter the sub-string you want to replace: ");
    gets(str3);
    int i,j=0,temp,ch,k,k1;
    int l=0;
    char x[40][21];
    char name3[21],name4[21];
    for(i=0;name[i]!=0;i++){
        if(name[i]==str3[j]){
            k1=0;
            for(k=i;k<i+strlen(str3);k++){
                name3[k1]=name[k];
                k1++;
            }
            name3[k1]=0;
            if(strcmp(name3,str3)==0){
                strncpy(name2,name,i-1);
                strcat(name2,str2);
                k1=0;
                for(;k<strlen(name);k++){
                    name4[k1]=name[k];
                    k1++;
                }
                name4[k1]=0;
                strcat(name2,name4);
                strcpy(name,name2);
                i+=strlen(str2)-2;
            }
        }
    }
    printf("New String: %s",name);
}
