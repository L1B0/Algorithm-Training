#include<stdio.h>
#include<string.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int like[201]={-1},num[201]={0};
		char book[201][201]={0};
		for(int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			like[i] = t;
			book[t][num[t]] = i+1;
			num[t]++;
		}
		for(int i=0;i<n;i++)
		{
			if( strlen(book[like[i]]) == 1 ) puts("BeiJu");
			else printf("%d\n",strlen(book[like[i]])-1);
		}
	}
	return 0;
}
