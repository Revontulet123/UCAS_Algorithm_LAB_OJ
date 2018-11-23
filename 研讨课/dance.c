#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 100000000
#define dim 1000001
using namespace std;
int dp[1000002][4][4];
int val[4][4]={
	{1,4,3,5},
	{2,1,4,3},
	{4,3,1,3},
	{2,4,3,1}
};
int main(){
	int num;
	cin>>num;


	while(num--){
		string s;
		cin>>s;
		int size=s.size();
		int i,j,k;
		vector<int> nums(size+2,4);
		for(i=0;i<size;i++){
			if((char)s[i]=='L')
				nums[i]=0;
			else if((char)s[i]=='R')
				nums[i]=1;
			else if((char)s[i]=='U')
				nums[i]=2;
			else if((char)s[i]=='D')
				nums[i]=3;

		}
		for(i=0;i<=dim;i++){
			for(j=0;j<=3;j++){
				for(k=0;k<=3;k++){
					dp[i][j][k]=MAX;
				}
			}
		}
		dp[0][0][1]=0;
		for(i=1;nums[i-1]!=4;i++){
			for(j=0;j<=3;j++){
				for(k=0;k<=3;k++){
					if(j!=k){
					dp[i][j][nums[i-1]]=min(dp[i-1][j][k]+val[k][nums[i-1]],dp[i][j][nums[i-1]]);
					dp[i][nums[i-1]][j]=min(dp[i-1][k][j]+val[k][nums[i-1]],dp[i][nums[i-1]][j]);
				}
			}
			}
		}
		int ans=MAX;
		for(j=0;j<=3;j++){
			for(k=0;k<=3;k++){
				ans=min(ans,dp[i-1][j][k]);

			}
		}
		cout<<ans;
		cout<<endl;

	}
	return 0;
}