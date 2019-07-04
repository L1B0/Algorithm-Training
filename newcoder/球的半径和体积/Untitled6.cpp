#include<stdio.h>
#include<math.h>

#define pai acos(-1)

int main()
{
	double x1,y1,z1,x2,y2,z2;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2)!=EOF)
	{
		double a=pow(x1-x2,2),b=pow(y1-y2,2),c=pow(z1-z2,2);
		double r = sqrt(a+b+c), s=pow(r,3)*4*pai/3;
		printf("%.3lf %.3lf\n",r,s);
	}
	return 0;
}
