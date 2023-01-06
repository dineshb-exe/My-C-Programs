#include <stdio.h>
#include <conio.h>
struct state
{
char *name;
int dist;
long pop;
};
void main()
{
    struct state s;
    printf ("\n Enter state name, number of dist. and population : ");
    scanf ("%s %d %ld",s.name,&s.dist,&s.pop);
    printf ("\n State : %s",s.name);
    printf ("\n District : %d",s.dist);
    printf ("\n Population : %ld",s.pop);
}
