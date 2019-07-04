#include<stdio.h>
#include<math.h>
#include<string.h>

int bin[20]={0};
int dp[2][1000001]={0};

int main()
{
	for(int i=1;i<=20;i++)
		bin[i] = pow(2,i-1);	

	//printf("fin\n");
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,2*1000001);
		dp[0][0]=dp[1][0]=1;
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=n;j++)
			{
				long long t;
				if( j >= bin[i] ) t = dp[1-i%2][j] + dp[i%2][j-bin[i]];
				else t = dp[1-i%2][j];
				dp[i%2][j] = (int)t%1000000000;
				//if(j == 1) printf("%d\n",dp[i][j]); 
			}

		}
		printf("%d\n",dp[0][n]);
	}
	return 0;
}

/*
int dp[21][1000001]={0};
int bin[20]={0};

int main()
{
	for(int i=1;i<=20;i++)
		bin[i] = pow(2,i-1),dp[i][0]=1;	

	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<1000001;j++)
		{
			long long t;
			if( j >= bin[i] ) t = (long long)dp[i-1][j] + (long long)dp[i][j-bin[i]];
			else t = (long long)dp[i-1][j];
			dp[i][j] = t%1000000000;
			//if(j == 1) printf("%d\n",dp[i][j]); 
		}
	}
	//printf("fin\n");
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",dp[20][n]);
	}
	return 0;
}
*/
