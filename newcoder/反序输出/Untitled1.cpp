#include<stdio.h>

int main()
{
	char s[6];
	while(gets(s))
	{
		for(int i=3;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
