#include<stdio.h>

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int y,m,d;
    while(scanf("%d %d %d",&y,&m,&d)!=EOF)
    {
        int sum=d;
        if( m > 2 && (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 )
            sum ++;
        for(int i=1;i<m;i++) sum += day[i];
        printf("%d\n",sum);
    }
    return 0;
}
