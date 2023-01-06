#include<stdio.h>

FILE *fp;

void PDFchecker(char fname[21]){
    fp=fopen(fname,"r");
    if(fp==NULL)
        printf("The file doesn't exist");
    else{
        char name[20];
        int i,j=0;
        fgets(name,9,fp);
        name[8]='\0';
        char x[10];
        for(i=1;i<4;i++){
            x[j]=name[i];
            j++;
        }
        x[j]=0;
        if(strcmp(x,"PDF")==0){
            printf("The given file is of type PDF!!!\n");
            j=0;
            for(i=5;i<8;i++){
                x[j]=name[i];
                j++;
            }
            x[j]=0;
            printf("The version of PDF: %s",x);

        }
        else{
            printf("The given file is not a PDF!!");
        }
    }
    fclose(fp);
}

int main(){
    char str1[20];
    printf("Enter the name of the file: ");
    gets(str1);
    PDFchecker(str1);
}
