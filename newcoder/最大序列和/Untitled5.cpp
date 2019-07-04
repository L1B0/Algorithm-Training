#include<stdio.h>
#define max(a,b) a>b?a:b

int l[1000001],dp[1000001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int m4x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&l[i]);
            if( i == 0 ) dp[0] = l[0], m4x = dp[0];
            else dp[i] = max(dp[i-1]+l[i],l[i]);
            m4x = max(m4x,dp[i]);
        }
        printf("%d\n",m4x);
    }
    return 0;
}
