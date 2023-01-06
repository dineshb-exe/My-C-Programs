#include<stdio.h>
typedef struct{
    int h;
    int m;
    int s;
}timex;

timex time_dif(timex t1, timex
                t2){
    timex t3;
    if(t2.s<t1.s){
        t2.s+=60;
        t2.m-=1;
    }
    t3.s=t2.s-t1.s;
    if(t2.m<t1.m){
        t2.m+=60;
        t2.h-=1;
    }
    t3.m=t2.m-t1.m;
    if(t2.h<t1.h)
    t2.h+=24;
    t3.h=t2.h-t1.h;
    return t3;
}
int main(){
    timex t1,t2;
    printf("Enter the hr part of time1: ");
    scanf("%d",&t1.h);
    printf("Enter the minute part of time1: ");
    scanf("%d",&t1.m);
    printf("Enter the seconds part of time1: ");
    scanf("%d",&t1.s);
    printf("Enter the hr part of time2: ");
    scanf("%d",&t2.h);
    printf("Enter the minute part of time2: ");
    scanf("%d",&t2.m);
    printf("Enter the seconds part of time2: ");
    scanf("%d",&t2.s);
    timex T3=time_dif(t1,t2);
    printf("Time Difference: %d hr %d min %d sec",T3.h,T3.m,T3.s);
}
