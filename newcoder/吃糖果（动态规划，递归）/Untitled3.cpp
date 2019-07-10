#include<stdio.h>

int digui(int a)
{
    if(a == 1) return 1;
    if(a == 2) return 2;
    return digui(a-1)+digui(a-2);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum = digui(n);
        printf("%d\n",sum);
    }
    return 0;
}
