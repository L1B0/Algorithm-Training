#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct st{
	int num,score;
}st;

st stu[101];
bool cmp(st a,st b)
{
	if( a.score == b.score ) return a.num<b.num;
	return a.score<b.score;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&stu[i].num,&stu[i].score);
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n",stu[i].num,stu[i].score);
	}
	return 0;
}
