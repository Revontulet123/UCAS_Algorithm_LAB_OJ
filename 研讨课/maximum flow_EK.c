#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;
const int inf=0x3fffffff;

int g[N][N];
int f[N][N];
int pre[N];
bool vis[N];
int n,m;

bool bfs(int s,int t)
{
	memset(pre,-1,sizeof(pre));
	memset(vis,false,sizeof(vis));
	queue<int> Q;
	vis[s]=true;
	Q.push(s);
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&g[now][i]>0)
			{
				vis[i]=true;
				pre[i]=now;
				if(i==t)
					return true;
				Q.push(i);
			}
		}
	}
	return false;
}

int maxflow(int s,int t)
{
	int v,w,d,ans;
	ans=0;
	while(bfs(s,t))
	{
		v=t;
		d=inf;
		while(v!=s)
		{
			w=pre[v];
			if(d>g[w][v])
				d=g[w][v];
			v=w;
		}
		ans+=d;
		v=t;
		while(v!=s)
			{
				w=pre[v];
				g[w][v]-=d;
				g[v][w]+=d;
				if(f[v][w]>0)
					f[v][w]-=d;
				else
					f[w][v]+=d;
				v=w;
			}
	}
	return ans;
}

int main()
{
	int s,t;
	int i,j,c;
	cin>>n>>m>>s>>t;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	for(int p=1;p<=m;p++)
	{
		cin>>i>>j>>c;
		g[i][j]+=c;
	}
	cout<<maxflow(s,t)<<endl;
	return 0;
}