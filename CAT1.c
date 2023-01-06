# include <stdio.h>
void fun(int *ptr)
{
*ptr = 30;
}
int main()
{
int y = 20;
int x = 10;
x = y;
fun(&y);
printf("%d", y);
}
