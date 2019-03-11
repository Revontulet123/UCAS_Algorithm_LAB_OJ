#include <iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;
int num;
int l,w;

typedef struct point
{
	int x,y;
} point;

point s[5003];
int init()
{
	int i;
	num = num+2;
	s[0].x=0;
	s[0].y=0;
	s[1].x=l;
	s[1].y=w;
	return 0;
}

int sortx()
{
	int i,j;
	point t;
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(s[i].x>s[j].x){
				t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
			else if(s[i].x==s[j].x){
				if(s[i].y>s[j].y){
				t=s[j];
				s[j]=s[i];
				s[i]=t;
				}
			}
		}
	}

	return 0;
}

int sorty()
{
	int i,j;
	point t;
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(s[i].y>s[j].y){
				t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
			else if(s[i].y==s[j].y){
				if(s[i].x>s[j].x){
				t=s[j];
				s[j]=s[i];
				s[i]=t;
				}
			}
		}
	}
	return 0;
}

int maxx()
{
	int ans=0;
	int i,j,p,q;
	sortx();
	for(i=0;i<num-1;i++){
		p=w;
		q=0;
		for(j=i+1;j<num;j++){
			if(s[i].x!=s[j].x){
				ans = max(ans,(s[j].x-s[i].x)*(p-q));
				if(s[j].y>s[i].y)
					p=min(p,s[j].y);
				else
					q=max(q,s[j].y);
			}
		}
	}
	return ans;
}

int maxy()
{
	int ans=0;
	int i,j,p,q;
	sorty();
	for(i=0;i<num-1;i++){
		p=l;
		q=0;
		for(j=i+1;j<num;j++){
			if(s[i].y!=s[j].y){
				ans = max(ans,(s[j].y-s[i].y)*(p-q));
				if(s[j].x>s[i].x)
					p=min(p,s[j].x);
				else
					q=max(q,s[j].x);
			}
		}
	}
	return ans;
}

int main()
{
	cin >>l;
	cin >>w;
	cin >>num;
	int i;
	int j=2;
	init();
	for(i=0;i<num-2;i++){
		cin >>s[j].x;
		cin >>s[j].y;
		j++;
	}
	int res;
	int ansx=maxx();
	int ansy=maxy();
	res=max(ansx,ansy);
	cout << res <<endl;
	return 0;
}