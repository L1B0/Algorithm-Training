#include<stdio.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int na=1,nb=1,lista[32]={a},listb[32]={b};
        while(a >= 1)
        {
        	if( a == 1 ) lista[na++] = 1;
            else if( a%2 ) lista[na++] = (a-1)/2;
            else lista[na++] = a/2;
            a /= 2;
        }
        while(b >= 1)
        {
        	if( b == 1 ) listb[nb++] = 1;
            else if( b%2 ) listb[nb++] = (b-1)/2;
            else listb[nb++] = b/2;
            b /= 2;
        } 
        na = na - 1;
        nb = nb - 1;
        while(na >= 0 && nb >= 0 && lista[na] == listb[nb]) na--,nb--;
        printf("%d\n",lista[na+1]);
    }
    return 0;
}
