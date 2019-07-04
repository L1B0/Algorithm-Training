#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int m4x=-1000001,m1n=1000001,a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			m4x = m4x > a ? m4x : a;
			m1n = m1n < a ? m1n : a; 
		}
		printf("%d %d\n",m4x,m1n); 
	}
	return 0;
}
