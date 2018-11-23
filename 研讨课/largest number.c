#include <iostream>
#include<algorithm>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

int cmp(string s1, string s2){
	string sa=s1+s2;
	string sb=s2+s1;
	int m;
	int n;
	stringstream ssa;
	stringstream ssb;
	ssa << sa;
	ssa >> m;
	ssb << sb;
	ssb >> n;
	if(m>=n)
		return 1;
	if(m<n)
		return 0;
}

string getmax(string s[],int len)
{
	for(int i=0; i< len;i++){
		for(int j=i+1;j<len;j++){
			if(cmp(s[i],s[j])==0){
				string tmp =s[j];
				s[j]=s[i];
				s[i]=tmp;
			}
		}
	}
	string res="";
	for(int k=0; k<len;k++){
		res=res+s[k];
		//cout << res <<'\n';
	}
	return res;
}

int main(){
	int N;
	cin>>N;
	int num[1002];

	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	string s[1002];
	for(int i=0;i<N;i++){
		stringstream ss;
		ss<<num[i];
		ss>>s[i];
	}
	string res=getmax(s,N);
	cout << re;
	cout << endl;

}