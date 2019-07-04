#include<stdio.h>
#include<string.h>

int flag[26]={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};

int main()
{
	char s[101];
	while(gets(s))
	{
		int num=0;
		for(int i=0;i<strlen(s);i++)
		{
			if( s[i] < 'p' ) num += (s[i]-'a')%3+1;
			else if( s[i] < 't' ) num += s[i]-'p'+1;
			else if( s[i] < 'w' ) num += s[i]-'t'+1;
			else num += s[i]-'w'+1;

			if( i > 0 && flag[s[i]-'a'] == flag[s[i-1]-'a'] )
				num += 2;
		}
		printf("%d\n",num);
	}	
	return 0;
} 
