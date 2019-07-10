#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
 
bool flag[1001][1001]={0};


int gcd(int a, int b)//欧几里得算法求最大公约数
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
/*
bool check(int a,int b)
{
	bool f = true;
	for(int i=2;i<=a;i++)
	{
		if( a%i == 0 && b%i == 0 )
		{
			f = false;
			break;
		}
	}
	return f;
} 
*/
int main()
{
	for(int i=1;i<=1000;i++)
	{
		for(int j=i+1;j<=1000;j++)
		{
			flag[i][j] = (gcd(j,i) == 1 ? 1 : 0); 
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int num[601]={0};
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n); 
		
		int result=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(flag[num[i]][num[j]] == 1)
				{
					//printf("%d %d\n",num[i],num[j]);
					result ++;
				}
					
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
