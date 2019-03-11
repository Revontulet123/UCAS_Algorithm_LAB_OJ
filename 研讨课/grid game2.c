#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=0x3fffffff;
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

int g[N][N];
int f[N][N];
int pre[N];
bool vis[N];

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
		for(int i=0;i<=N;i++)
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

int add(int a, int b, int c)
{
	g[a][b]+=c;
	return 0;
}

int init()
{
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
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
		int res;
		res=maxflow(s,t);
		//cout<<res;
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