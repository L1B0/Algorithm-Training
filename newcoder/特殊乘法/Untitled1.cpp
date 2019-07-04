#include<stdio.h>
#include<string.h>

int main()
{
    char a[10],b[10];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int sum=0;
        for(int i=0;i<strlen(a);i++)
            for(int j=0;j<strlen(b);j++)
                sum += (a[i]-'0')*(b[j]-'0');
        printf("%d\n",sum);
    }
    return 0;
}
