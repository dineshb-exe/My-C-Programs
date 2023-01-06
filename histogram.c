#include<stdio.h>

const int N=10;

int main(){
    int a[N];
    printf("Enter a list of numbers: ");
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    i=0;
    int chk=1;
    int b[N],c[N],last=-1,j,k,l;
    while(i<N)
    c[i++]=0;//Initializing counter array  values to 0
    for(i=0;i<N;i++){
        for(j=i-1;j>=0&&chk==1;j--){
            if(a[j]==a[i])
                chk=0;
        }
        if(chk==0){
            for(k=0;a[i]!=b[k];k++);
            c[k]++;
        }
        else if(chk==1){
            last++;
            b[last]=a[i];
            c[last]++;
        }
        chk=1;
    }
    printf("HISTOGRAM:\n");
    for(l=0;l<=last;l++){
        printf("%d : %d\n",b[l],c[l]);
    }
}
