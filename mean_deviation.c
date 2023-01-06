#include<stdio.h>
const int N=10;
int main(){
	int a[N];
	int i;
	printf("Enter %d numbers: ", N);
	for(i=0; i<N; )
	scanf("%d", &a[i++]);
  	int sum=0;
	for(i=0; i<N;)
	sum+=a[i++];
	float avg = sum/N;
    float j;
	for(i=0; i<N; i++){
		j=avg-a[i];
		if(j<0)
            j*=-1;
		printf("The mean deviation of element %d is %f\n", i, j);
	}
}
