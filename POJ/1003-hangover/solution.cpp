#include<stdio.h>

int main()
{
	float a;
	while( scanf("%f",&a) )
	{
		if( a == 0.0 ) break;
		int n=2;
		float sum =0;
		while( sum < a )
		{
			sum += 1.0/n;
			n++;
		}
		printf("%d card(s)\n",n-2);
	} 
	return 0;
} 
