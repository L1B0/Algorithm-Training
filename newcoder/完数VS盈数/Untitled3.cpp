#include <stdio.h>
#include <math.h>

int check(int x)
{
    int sum=1;
    for(int i=2;i<x;i++)
    {
        if(x % i == 0)
        	sum += i;
    }
    if( sum == x ) return 1;
    else if( sum > x ) return -1;
    else return 0;
}
int main()
{
    int f[61]={0};
    for(int i=2;i<=60;i++)
    {
        f[i] = check(i);
    }
    printf("E:");
    for(int i=2;i<61;i++)
    {
        if(f[i] == 1)
            printf(" %d",i);
    }
    printf("\nG:");
    for(int i=2;i<61;i++)
    {
        if(f[i] == -1)
            printf(" %d",i);
    }
    printf("\n");
    return 0;
}
