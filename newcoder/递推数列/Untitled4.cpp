#include<stdio.h>

int main()
{
    int a0,a1,p,q,k,c;
    scanf("%d %d %d %d %d",&a0,&a1,&p,&q,&k);
    for(int i=2;i<=k;i++)
    {
        c = p*a1%10000+q*a0%10000;
        c %= 10000;
        a0 = a1;
        a1 = c;
    }
    printf("%d\n",c);
    return 0;
}
