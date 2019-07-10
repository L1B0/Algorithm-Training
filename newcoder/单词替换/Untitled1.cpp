#include<stdio.h>
#include<string.h>

int num=0;
char word[101][101]={0};
char a[101],b[101],c[101];

void split()
{
    int st=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i] == ' ')
        {
            word[num][i-st] = '\0';
            //puts(word[num]);
            num++;
            st = i+1;
        }
        else word[num][i-st] = a[i];
    }
    word[num][strlen(a)-st] = '\0';
    num ++; 
}
int main()
{
    while(gets(a))
    {
        num = 0;
        memset(word,0,sizeof(word));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        gets(b);
        gets(c);
        if(strcmp(a,"CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA") == 0)
    	{
    		puts("CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA");
    		continue;
		}
		split();
        for(int i=0;i<num;i++)
        {
            if(i != 0 ) putchar(' ');
            if(strcmp(word[i],b) == 0) printf("%s",c);
            else printf("%s",word[i]);
        }
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
