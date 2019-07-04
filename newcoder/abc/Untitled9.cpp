#include<stdio.h>

int main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if( i == j ) continue;
			for(int k=0;k<10;k++)
			{
				if( j == k ) continue;
				if( (i+j)*100+(j+k)*10+2*k == 532)
					printf("%d %d %d\n",i,j,k);
			}
		}
	} 
}
