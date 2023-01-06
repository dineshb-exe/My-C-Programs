#include<stdio.h>

typedef struct{
    int feet;
    int inches;
}Distance;

int main(){
    Distance d1,d2,d3;
    int s;
    printf("Enter the distance1 in feet: ");
    scanf("%d",&d1.feet);
    printf("Enter the distance1 in inches: ");
    scanf("%d",&d1.inches);
    printf("Enter the distance2 in feet: ");
    scanf("%d",&d2.feet);
    printf("Enter the distance2 in inches: ");
    scanf("%d",&d2.inches);
    d3.feet=d1.feet+d2.feet;
    d3.inches=d1.inches+d2.inches;
    if(d3.inches>=12){
        s=(d3.inches/12);
        d3.feet+=s;
        d3.inches-=(s*12);
    }
    printf("The sum of 2 distances is: %d ft %d in",d3.feet,d3.inches);

}
