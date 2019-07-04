#include<stdio.h>
#include<math.h> 

int change(int x)
{
	int i,m4x=(int)sqrt(x);
	for(i=2;i<=m4x;i++)
		if(x%i == 0)
			break;
	if( x%i != 0 ) return 1;
	return x/i;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i=0,num=0;
		while(n != 1)
		{
			n = change(n);
			num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
