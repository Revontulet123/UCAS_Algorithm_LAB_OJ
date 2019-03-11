#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stdio.h>
#define  MAX 5000
using namespace std;


int graph[MAX][MAX];
int W,H,n,t;
int num=1;

struct Box
{
	int x,y,w,h;
	int flag;
	int dis;
	int mask;
	
} Box[257];

int init(){
	memset(graph,0,sizeof(graph));
	return 0;
}
bool open(int a,int b,int c,int d)
{
	Box[num].x=a;
	Box[num].y=b;
	Box[num].w=c;
	Box[num].h=d;
	Box[num].flag=num;

	if(a+c>W||b+d>H)
		return false;

	for(int i=0;i<c;i++){
		for(int j=0;j<d;j++){
			if(graph[a+i][b+j]!=0)
				return false;
		}
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<d;j++){
			graph[a+i][b+j]=Box[num].flag;
		}
	}
	num++;
	return true;
}

bool close(int a,int b)
{
	if(graph[a][b]==0)
		return false;
	int tmp=graph[a][b];
	int x=Box[tmp].x;
	int y=Box[tmp].y;
	int w=Box[tmp].w;
	int h=Box[tmp].h;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			graph[x+i][y+j]=0;
		}
	}
	Box[tmp].flag=0;
	return true;
}

int resize(int a,int b,int c,int d)
{
	if(graph[a][b]==0)
		return 1;
	int tmp=graph[a][b];
	int x=Box[tmp].x;
	int y=Box[tmp].y;
	int w=Box[tmp].w;
	int h=Box[tmp].h;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			graph[x+i][y+j]=0;
		}
	}
		if(x+c>W||y+d>H){
			for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
			graph[x+i][y+j]=Box[tmp].flag;
		}
	}
			return 2;
		}

	for(int i=0;i<c;i++){
		for(int j=0;j<d;j++){
			if(graph[x+i][y+j]!=0){
				for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
			graph[x+i][y+j]=Box[tmp].flag;
		}
	}
				return 2;}
		}	
	}

	for(int i=0;i<c;i++){
		for(int j=0;j<d;j++){
			graph[x+i][y+j]=Box[tmp].flag;
		}
	}
	Box[tmp].w=c;
	Box[tmp].h=d;
	return 0;
}

int main()
{
	init();
	cin>>W>>H>>n>>t;
	for(int i=1;i<=n;i++){
		int x,y,w,h;
		char mode[20];
        scanf("%s",mode);
      if(mode[0]=='O'){
    		scanf("%d%d%d%d",&x,&y,&w,&h);
    	if(open(x,y,w,h)==false)
    		printf("Command %d: OPEN - box does not fit\n",i);
}
		if(mode[0]=='R'){
			scanf("%d%d%d%d",&x,&y,&w,&h);
			if(resize(x,y,w,h)==1)
				printf("Command %d: RESIZE - no box at given position\n",i);
			else if(resize(x,y,w,h)==2)
				printf("Command %d: RESIZE - box does not fit\n",i);
		}
		if(mode[0]=='C'){
			scanf("%d%d",&x,&y);
			if(close(x,y)==false)
				printf("Command %d: CLOSE - no box at given position\n",i);
		}
	}
	int count=0;
	int valid[256];
	for(int i=1;i<=n;i++){
			if(Box[i].flag!=0){
				valid[count]=Box[i].flag;
				count++;
			}
	}
	printf("%d box(es):\n",count);
	for(int i=0;i<count;i++){
		printf("%d %d %d %d \n",Box[valid[i]].x,Box[valid[i]].y,Box[valid[i]].w,Box[valid[i]].h);
	}
	return 0;
}