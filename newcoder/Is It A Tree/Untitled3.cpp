#include<stdio.h>
#include<string.h>

int ru[10001]={0},chu[10001]={0};

bool checkit()
{
	int flag=-1;
	for(int i=0;i<10001;i++)
	{
		if(ru[i] > 1)
		{
			flag=0;
			break;
		}
		else if(ru[i] == 0 && chu[i] > 0)
		{
			if(flag == 2)
			{
				flag = 0;
				break;
			}
			flag = 2;	
		}
	}
	if( flag == 2 ) return true;
	else return false;
} 
int main()
{
	int num=0,a,b,f=0;
	while(scanf("%d %d",&a,&b))
	{
		if( a == -1 || b == -1 ) break;
		if( a == 0 && b == 0 )
		{
			num++;
			bool flag = checkit();
			if(f == 0 || flag) printf("Case %d is a tree.\n",num);
			else printf("Case %d is not a tree.\n",num);
			
			f = 0;
			memset(ru,0,sizeof(ru));
			memset(chu,0,sizeof(chu));
			continue;
		}
		chu[a] ++;
		ru[b] ++;
		f = 1;
	}
	return 0;
} 
