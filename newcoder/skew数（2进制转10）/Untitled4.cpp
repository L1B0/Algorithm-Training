#include<stdio.h>
#include<string.h>
char s[32];
int main()
{
    while(gets(s))
    {
        int sum=0,lens = strlen(s);
        for(int i=0;i<lens;i++)
        {
            if(s[i] == '0') continue;
            sum += (pow(2,lens-i)-1)*(s[i]-'0');
        }
        printf("%d\n",sum);
    }
    return 0;
}
