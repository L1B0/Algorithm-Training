#include <stdio.h>
#include <math.h>

#define pai 3.1415926
int main()
{
	int n;
	double x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf",&x,&y);
		double d = sqrt(x*x+y*y);
		for(int j=1;;j++)
		{
			double r = sqrt((j*100.0)/pai);
			if( r > d )
			{
				printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
				break;
			}
		}
	}
	puts("END OF OUTPUT.");
	return 0;
}
