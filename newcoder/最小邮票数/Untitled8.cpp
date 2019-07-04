#include<stdio.h>

#define min(a,b) a > b ? b : a
int main()
{
	int sum,n,num[20];
	while(scanf("%d",&sum)!=EOF)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		int dp[20][101]={0};
		for(int i=1;i<101;i++)
			dp[0][i] = 1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				if( j < num[i] ) dp[i][j] = dp[i-1][j];
				else dp[i][j] = min(dp[i-1][j],dp[i-1][j-num[i-1]]+1);
			}	
		} 
		printf("%d\n",dp[n][sum] == 1e9 ? 0 : dp[n][sum]); 
	}
	return 0;
}
