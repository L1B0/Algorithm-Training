#include<stdio.h>
#include<string.h>
char color[101][11]={0};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            scanf("%s",color[a]);
        }
        for(int i=100;i>=0;i--)
        {
            if(strlen(color[i]) > 0)
                puts(color[i]);
        }
    }
    return 0;

