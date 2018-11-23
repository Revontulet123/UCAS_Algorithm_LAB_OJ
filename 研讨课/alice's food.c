#include <iostream> 
#include <algorithm>
#include <vector>
#include <climits>
#include <string.h>
using namespace std;
vector <int> x;
vector <int> y;
vector <int> cost;
int ***dp;
int main(){
	int x_min;
	int y_min;
	int num;
	cin>>x_min;
	cin>>y_min;
	cin>>num;
	vector<int> x(num,0);
	vector<int> y(num,0);
	vector<int> cost(num,0);
	int i,j,k;
	for(i=0;i<num;i++){
		cin>>x[i];
		cin>>y[i];
		cin>>cost[i];
	}
	int dp[num+1][x_min+1][y_min+1];
	memset(dp,0,sizeof(dp));
	for(j=0;j<=x_min;j++){
		for(k=0;k<=y_min;k++){
			dp[0][j][k]=1000000;
		}
	}
	for(i=1;i<=num;i++){
		for(j=0;j<=x_min;j++){
			for(k=0;k<=y_min;k++){
				if(x[i-1]>=j&&y[i-1]>=k)
					dp[i][j][k]=min(dp[i-1][j][k],cost[i-1]);
				else if(x[i-1]<j&&y[i-1]>=k)
					dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-x[i-1]][0]+cost[i-1]);
				else if(x[i-1]>=j&&y[i-1]<k)
					dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][0][k-y[i-1]]+cost[i-1]);
				else
					dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-x[i-1]][k-y[i-1]]+cost[i-1]);				

			}
		}

	}
	cout<<dp[num][x_min][y_min];
	cout<<endl;
	return 0;

}