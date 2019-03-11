#include <iostream>
#include<algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int inf=100000000;
const int N=510;
const int M=300010;
int top;
int h[N],pre[N],g[N];

struct vertex
{
	int first;
}V[N];

struct edge
{
	int v;
	int next;
	int cap,flow;
}E[M];

int init()
{
	memset(V,-1,sizeof(V));
	top=0;
	return 0;
}

int add_edge(int u,int v, int c)
{
	E[top].v=v;
	E[top].cap=c;
	E[top].flow=0;
	E[top].next=V[u].first;
	V[u].first=top++;
	return 0;
}

int add(int u,int v,int c)
{
	add_edge(u,v,c);
	add_edge(v,u,0);
}

int jump(int t,int n)
{
	queue<int> Q;
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	h[t]=0;
	Q.push(t);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		++g[h[v]];
		for(int i=V[v].first;i!=-1;i=E[i].next)
		{
			int u=E[i].v;
			if(h[u]==-1)
			{
				h[u]=h[v]+1;
				Q.push(u);
			}
		}
	}
	return 0;
}

int maxflow(int s,int t,int n)
{
	jump(t,n);
	int ans=0,u=s;
	int d;
	while(h[s]<n)
	{
		int i=V[u].first;
		if(u==s)
			d=inf;
		for(;i!=-1;i=E[i].next)
		{
			int v=E[i].v;
			if(E[i].cap>E[i].flow&&h[u]==h[v]+1)
			{
				u=v;
				pre[v]=i;
				d=min(d,E[i].cap-E[i].flow);
				if(u==t)
				{
					while(u!=s)
					{
						int j=pre[u];
						E[j].flow+=d;
						E[j^1].flow-=d;
						u=E[j^1].v;
					}
				ans+=d;
				d=inf;
				}
				break;
			}
		}
		if(i==-1)
		{
			if(--g[h[u]]==0)
				break;
			int hmin=n-1;
			for(int j=V[u].first;j!=-1;j=E[j].next)
			{
				if(E[j].cap>E[j].flow)
					hmin=min(hmin,h[E[j].v]);
			}
			h[u]=hmin+1;
			++g[h[u]];
			if(u!=s)
				u=E[pre[u]^1].v;
		}
	}
	return ans;
}

int main()
{
	int n,m,s,t;
	int i,j,c;
	cin>>n;
	cin>>m;
	cin>>s;
	cin>>t;
	init();
	for(int p=1;p<=m;p++)
	{
		cin>>i>>j>>c;
		add(i,j,c);
	}

	cout<<maxflow(s,t,n)<<endl;
	return 0;

}

