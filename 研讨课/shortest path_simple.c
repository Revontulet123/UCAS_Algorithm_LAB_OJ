#include <iostream>
#include<algorithm>
#include <stdio.h>
#define inf 0x3f3f3f
using namespace std;

int edge[100002][3];

int main(){
	int n;
	int m;
	int s;
	int t;
	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;
	for(int i=1;i<=m;i++){
		cin >> edge[i][0];
		cin >> edge[i][1];
		cin >> edge[i][2];
	}
	int dis[n+2];
	int flag[n+2];
	for(int i=1;i<=n;i++){
		flag[i]=0;
	}
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	for(int i=1;i<=m;i++){
		if(edge[i][0]==s){
			dis[edge[i][1]]=edge[i][2];
		}
	}
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int k,tmp=inf;
		for(int j=1;j<=n;j++){
			if(!flag[j] && dis[j]<tmp){
				tmp=dis[k=j];
			}
		}
		flag[k]=1;     
		for(int j=1;j<=m;j++){
			if(edge[j][0]==k&&!flag[edge[j][1]]&&dis[edge[j][1]]>dis[k]+edge[j][2])
				dis[edge[j][1]]=dis[k]+edge[j][2];

		}

}
	if(dis[t]!=inf)
		cout << dis[t] <<endl;
	else
		cout << -1;
	return 0;

}