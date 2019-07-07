#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct mynode{
	int index,dist;
	bool flag;
}node;
int n,m;
bool vis[601][601]={0};
int dis[601][601]={-1}, owner[601]={-1};

int bfs()
{
	queue<node> q;
	// init
	node head;
	head.index = 1;
	head.dist = 0;
	head.flag = 0;
	q.push(head);
	// start bfs
	int res = 1e9;
	while(!q.empty())
	{
		// get fist node
		node front = q.front();
		q.pop();
		if( front.index == 2 )
		{
			res = res > front.dist ? front.dist : res;
			continue;
		}
		int ind = front.index, f = front.flag;
		for(int i=1;i<=n;i++)
		{
			if( !vis[i][ind] && dis[i][ind] != -1 )
			{
				if( owner[i] != owner[ind] && f ) continue;
				vis[i][ind] = 1;
				node now;
				now.index = i;
				now.dist = front.dist + dis[i][ind];
				now.flag = (owner[i] != owner[ind]);
				q.push(now);
			}
		}
	}
	return (res == 1e9 ? -1 : res);
}

int main()
{
	while( scanf("%d",&n) )
	{
		if( n == 0 ) break;
		memset(vis,0,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		// input 
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if( dis[a][b] == -1 || (dis[a][b] != -1 && dis[a][b] > c) )
				dis[a][b] = dis[b][a] = c;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&owner[i]);
		}
		// begin search
		int res = bfs();
		printf("%d\n",res);
	}
}
