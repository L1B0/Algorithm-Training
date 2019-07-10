#include<stdio.h>
#include<algorithm>
using namespace std;
int num[10001];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n == 0) break;
        
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        if( n % 2 == 0 ) printf("%d\n",(num[n/2-1]+num[n/2])/2);
        else printf("%d\n",num[n/2]); 
    }
    return 0;
}
