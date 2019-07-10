#include<stdio.h>
#include<string.h>
char num[31];
bool mymod(int a)
{
	int sum=0;
	for(int i=0;i<strlen(num);i++)
	{
		int temp = num[i]-'0'+sum*10;
		sum = temp%a;
	}
	return sum == 0 ? 1 : 0;
}
int main()
{
	while(scanf("%s",num)!=EOF)
	{
		bool flag = false;
		for(int i=2;i<=9;i++)
		{
			if(mymod(i) == 1)
			{
				if(flag)
					printf(" %d",i);
				else printf("%d",i);
				flag = true;
			}	
		} 
		if( !flag ) puts("none");
		else printf("\n");
	}
	return 0;
} 
