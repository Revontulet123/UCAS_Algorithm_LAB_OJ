#include <queue>
#include <iostream>
#include <cstring>
#define inf 0x3f3f3f
using namespace std;

const int N=10002;
int** map;
int dist[N],n,m;
int flag[N];
struct node
{
	int u,step;
	node(){};
	node(int a,int sp){
		u=a;
		step=sp;
	}
	bool operator < (const node& a)const{
		return step > a.step;
	}
	
};

int dijkstra(int s){
	priority_queue <node> Q;
	Q.push(node(s,0));
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++){
		dist[i]=inf;

	}
	dist[s]=0;
	while(!Q.empty())
	{
		node it=Q.top();
		Q.pop();
		int t=it.u;
		if(flag[t])
			continue;
		flag[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i]&&map[t][i]<inf){
				if(dist[i]>dist[t]+map[t][i])
				{
					dist[i]=dist[t]+map[t][i];
					Q.push(node(i,dist[i]));
				}
			}
		}
	}
	return 0;
}

int main(){
	int u,v,w;
	int s;
	int t;
	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;
	map =new int* [n+2];
	for(int i=0;i<n+2;i++){
		map[i]=new int[n+2];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=inf;
		}
	}
	while(m--)
	{
		cin >>u>>v>>w;
		map[u][v]=w;
	}
	dijkstra(s);
	if(dist[t]!=inf)
		cout << dist[t] <<endl;
	else
		cout << -1;
	return 0;
}