#include <iostream>
#include<algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>
#define inf 0x3f3f3f
using namespace std;

const int L=33;

int flag[L*L];
int black[L*L];
int white[L*L];
int hole[L*L];
int m,clo,k;
int num_black;
int num_white;
const int s=0;
const int t=950;


const int N=1000;
const int M=4000;
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
	memset(pre,0,sizeof(pre));
	memset(E,0,sizeof(E));
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
	return 0;
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

int color()
{
	memset(flag,0,sizeof(flag));
	memset(black,0,sizeof(black));
	memset(white,0,sizeof(white));
	for(int j=1;j<=m;j++){
	if(j%2==1){
	for(int i=1;i<=clo;i+=2){
		flag[i+(j-1)*clo]=1;
	}}
	if(j%2==0){
		for(int i=2;i<=clo;i+=2){
		flag[i+(j-1)*clo]=1;
	}
	}
}
	for(int i=0;i<k;i++){
		flag[hole[i]]=-1;
	}
	int j=0;
	int p=0;
	for(int i=1;i<=m*clo;i++){
		if(flag[i]==1){
			black[j]=i;
			j++;
		}
		if(flag[i]==0){
			white[p]=i;
			p++;
		}
	}

	num_black=j;
	num_white=p;
	return 0;
}

int init_hole(int a,int b,int i)
{

   hole[i]=(a-1)*clo+b;
   return 0;
   
}
int init_graph()
{
	init();
	int a,b,c,d;
	for(int i=0;i<num_black;i++){
		a=black[i]-1;
		b=black[i]+1;
		c=black[i]+clo;
		d=black[i]-clo;
		if(a>0&&flag[a]==0){
			add(black[i],a,1);
		}
		if(b<=m*clo&&flag[b]==0){
			add(black[i],b,1);
		}
		if(c!=b&&c<=m*clo&&flag[c]==0){
			add(black[i],c,1);
		}
		if(d!=a&&d>0&&flag[d]==0){
			add(black[i],d,1);
		}

	}
	for(int i=0;i<num_black;i++){
		add(s,black[i],1);
	}
	for(int i=0;i<num_white;i++){
		add(white[i],t,1);
	}
	return 0;
}

int main()
{
	int num_case;
	cin >>num_case;
	int tmp=num_case;
	int ans[6];
	int count=0;
	while(num_case--)
	{
		memset(hole,-1,sizeof(hole));
		cin>>m>>clo>>k;
		int a,b;
		for(int i=0;i<k;i++){
			cin>>a>>b;
			init_hole(a,b,i);
		}
		color();
		init_graph();
		int n=num_white+num_black+2;
		int res;
		res=maxflow(s,t,n);
		if((m*clo-k)%2!=0){
			ans[count]=0;
			count++;
		}
		else if(res!=(m*clo-k)/2){
		
			ans[count]=0;
			count++;}
		else if(res==(m*clo-k)/2){
		
			ans[count]=1;
			count++;}
	}
	for(int i=0;i<tmp;i++){
		if(ans[i]==0)
		printf("NO\n");
		else
		printf("YES\n");
	}
	return 0;	
}



