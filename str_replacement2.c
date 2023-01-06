#include<stdio.h>
#include<string.h>

int main(){
    char name[21],str1[11],str2[11],name2[11];
    gets(name);
    gets(str1);
    gets(str2);
    int i=0,j=0,k;
    for(;name[i]!=0;i++){
        if(name[i]==str1[j]){
            for(k=i;k<i+strlen(str1);k++){
                name2[j]=name[i];
                j++;
            }
            name2[j]=0;
            if(strcmp(name2,str1)==0){
                k=0;
                j=0;
                for(k=i;k<i+strlen(name2);k++){
                    name[k]=str2[j];
                    j++;
                }
                i=k;
            }
        }
        j=0;

    }
     printf("New string: %s \n",name);
}
