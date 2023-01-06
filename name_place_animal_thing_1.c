#include<stdio.h>
#include<stdlib.h>

struct noun{
	char id[21];
	char category[21];
};

const int N=10;

int main(){
	FILE *f;
	struct noun n1;
	int bbingo-dingo;
	int co=0;
	f=fopen("mini_database.dat","rb");
	int a[N],top,i,n,ch,j;
	char c,c2;
	printf("Welcome to Name, Place, Animal, Thing Quiz\n");
	for(i=0;i<N;i++){
		if(i==0){
			n=rand()%100+1;
			a[i]=n;
			top=0;
		}
		else{
			do{
				n=rand()%100+1;
				ch=1;
				j=0;
				while(j<=top){
					if(a[j]==n)
					ch=0;
					j++;
				}
			}
			while(ch==0);
			top++;
			a[top]=n;
		}
		printf("Question No.: %d\n",i+1);
		fseek(f,(n-1)*sizeof(struct noun),SEEK_SET);
		fread(&n1, sizeof(struct noun),1,f);
		puts(n1.id);
		printf("\nA: NAME\nB: PLACE\nC:ANIMAL\nD:THING\nEnter A/B/C/D: ");
		scanf("%c",&c);
		scanf("%c",&c2);
		if(c=='A'||c=='a'){
			if(strcmp("Name",n1.category)==0){
				co++;
				printf("Your response is correct!!!!\n");
			}
		 	else{
				printf("Your response is wrong. Better luck next time\n");
			}
		}
		else if(c=='B'||c=='b'){
			if(strcmp("Place",n1.category)==0){
				co++;
				printf("Your response is correct!!!!\n");
			}
		 	else{
				printf("Your response is wrong. Better luck next time\n");
			}
		}
		else if(c=='C'||c=='c'){
			if(strcmp("Animal",n1.category)==0){
				co++;
				printf("Your response is correct!!!!\n");
			}
		 	else{
				printf("Your response is wrong. Better luck next time\n");
			}
		}
		else if(c=='D'||c=='d'){
			if(strcmp("Thing",n1.category)==0){
				co++;
				printf("Your response is correct!!!!\n");
			}
		 	else{
				printf("Your response is wrong. Better luck next time\n");
			}
		}
		else{
			printf("Invalid Response!!\n");
	  	}
	}
	printf("\n You got %d out of 10 answers correct",co);
}

