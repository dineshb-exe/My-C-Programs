#include<stdio.h>

const int N=4;

int main()
{
	char str[N][101];
	int i,len,j;
	int count[N];
	printf("Enter the string: \n");
	for(i=0;i<N;i++){
        count[i]=0;
		gets(str[i]);
		for(len=0;str[i][len]!='\0';len++);
		for(j=0;j<len;j++)
		if(str[i][j]==' ')
		count[i]++;
	}
	int max=count[0];
	for(i=0;i<N;i++){
        if(count[i]>max){
        max=count[i];
        }
	}
	for(i=0;i<N;i++){
	    if(max==count[i])
	    printf("Line %d: %s \n",i+1,str[i]);
	}
}
