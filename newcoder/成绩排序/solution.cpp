// https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking 
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct student{
	char name[101];
	int score,number;
};

student st[1000];
int n,type;

bool cmp( student a, student b )
{
	if(type)
	{
		if( a.score != b.score )
			return a.score < b.score;
		return a.number < b.number;
	}
	if( a.score != b.score )
			return a.score > b.score;
		return a.number < b.number;		
} 
int main()
{
	while( scanf("%d %d",&n,&type) != EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s %d",st[i].name,&st[i].score);
			st[i].number = i;
		}
		sort(st,st+n,cmp);
		for(int i=0;i<n;i++)
		{
			printf("%s %d\n",st[i].name,st[i].score);
		}	
	}
	
	return 0;
} 
