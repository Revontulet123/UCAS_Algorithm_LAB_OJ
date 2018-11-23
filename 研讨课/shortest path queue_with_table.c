#include <queue>
#include <iostream>
#include <cstring>
#define inf 0x3f3f3f
using namespace std;

const int N=10002;

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
struct pnode
{
	int v;
	int w;
	pnode *next;
};
struct Hnode
{
	pnode *first;
};
Hnode g[N];
int insertedge(Hnode &p,int x,int y){
	pnode *q;
	q=new(pnode);
	q->v=x;
	q->w=y;
	q->next=p.first;
	p.first=q;
	return 0;
}
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
		pnode* tmp=g[t].first;
		while(tmp!=NULL){

			if(!flag[tmp->v]&&dist[tmp->v]>dist[t]+tmp->w){
				dist[tmp->v]=dist[t]+tmp->w;
				Q.push(node(tmp->v,dist[tmp->v]));
			}
			tmp=tmp->next;
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
	for(int i=1;i<=n;i++){
		g[i].first=NULL;
	}

	while(m--)
	{
		cin >>u>>v>>w;
		insertedge(g[u],v,w);
	}
	dijkstra(s);
	if(dist[t]!=inf)
		cout << dist[t] <<endl;
	else
		cout << -1;
	return 0;
}