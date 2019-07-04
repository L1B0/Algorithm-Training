#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct number{
	char s[51];
	int num;
};

int n,len;
number myn[101];

bool cmp( number a, number b )
{
	return a.num < b.num;
}
int main()
{
	scanf("%d %d",&len,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",myn[i].s);
		myn[i].num = 0;
		for(int j=0;j<len;j++)
		{
			if(myn[i].s[j] == 'A') continue;
			for(int k=j+1;k<len;k++)
			{
				if(myn[i].s[j] > myn[i].s[k])
					myn[i].num++;
			}
		}
	}
	sort(myn,myn+n,cmp);
	for(int i=0;i<n;i++)
		puts(myn[i].s); 
	return 0;	
} 
