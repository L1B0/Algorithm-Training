#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int num=0;
int mymap[10000000] = {0};

int change(char a[201])
{
	int j=0, result=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i] == '-') continue;
		if(a[i] <= '9' && a[i] >= '0')
		{
			result = result*10+a[i]-'0';
			continue;
		}
		if( a[i] <= 'O' && a[i] >= 'A' )
		{
			result = result*10+ (int)((a[i]-'A')/3) + 2;
			continue;
		}
		switch (a[i])
		{
			case 'P':
			case 'R':
			case 'S':
				result = result*10+7;
				break;
			case 'T':
			case 'U':
			case 'V':
				result = result*10+8;
				break;
			case 'W':
			case 'X':
			case 'Y':
				result = result*10+9;
				break;
		}
	}
	return result;	
} 
int main()
{
	int n,times=0;
	char temp[201];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		int flag = 0, t;
		t = change(temp);
		mymap[t] ++;
	}
	
	int flag = 0;
	for(int i=0;i<10000000;i++)
	{
		if(mymap[i] < 2) continue;
		flag = 1;
		char p[8] = {0};
		sprintf(p,"%d",i);
		if( strlen(p) <= 4 )
		{
			for(int j=0;j<3;j++)
				printf("0");
			printf("-");
			for(int j=0;j<4-strlen(p);j++)
				printf("0");
			for(int j=0;j<strlen(p);j++)
				printf("%c",p[j]);
		}
		else
		{
			for(int j=0;j<7-strlen(p);j++)
				printf("0");
			for(int j=0;j<strlen(p)-4;j++)
				printf("%c",p[j]);
			printf("-");
			for(int j=strlen(p)-4;j<strlen(p);j++)
				printf("%c",p[j]);
		}
		printf(" %d\n",mymap[i]);
	}
	if( flag == 0 ) puts("No duplicates.");
	return 0;	
} 
