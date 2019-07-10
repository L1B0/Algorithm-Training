#include<stdio.h>
#include<string.h>

char num[31],output[1000];

void div()
{
	if(strlen(num) == 0) return ;
	output[strlen(output)] = (num[strlen(num)-1]-'0')%2+'0';
	int last=0;
	for(int i=0;i<strlen(num);i++)
	{
		int t = last*10+num[i]-'0';
		if( t < 2 )
		{
			num[i] = '0';
			last = t;
		}
		else
		{
			num[i] = '0' + t/2;
			last = t%2;		
		}	
	}

	int i=0;
	while(num[i] == '0') i++;
	for(int j=i;j<strlen(num);j++)
		num[j-i] = num[j];
	num[strlen(num)-i] = '\0';
	div();	
} 
int main()
{
	while(scanf("%s",num)!=EOF)	
	{
		memset(output,0,sizeof(output));
		if( strlen(num) == 1 && num[0] == '0' ) puts("0");
		else
		{
			div();
			for(int i=strlen(output)-1;i>=0;i--)
				putchar(output[i]);
			printf("\n");	
		}
	}
	return 0;
}
