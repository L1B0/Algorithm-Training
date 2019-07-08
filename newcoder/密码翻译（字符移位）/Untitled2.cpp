#include<stdio.h>
#include<string.h>
char s[81];
int main()
{
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
        {
            if( s[i] <= 'z' && s[i] >= 'a' )
                s[i] = (s[i]-'a'+1)%26 + 'a';
            else if( s[i] <= 'Z' && s[i] >= 'A' )
                s[i] = (s[i]-'A'+1)%26 + 'A';
        }
        puts(s);
    }
    return 0;
}
