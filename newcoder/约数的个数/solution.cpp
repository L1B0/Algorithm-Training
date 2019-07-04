#include<stdio.h>

int myprime[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//if( n == 0 ) break;
		int num[1001];
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(int i=0;i<n;i++)
		{
			int sum=1,times[12]={0},temp = num[i];
			for(int j=0;j<12;j++)
			{
				while( temp % myprime[j] == 0 )
				{
					times[j] ++;
					temp /= myprime[j];
				}
			}
			for(int j=0;j<12;j++)
			{
				sum *= (times[j]+1);
			}
			printf("%d\n",sum);
		}		 
	}
	return 0;
}
