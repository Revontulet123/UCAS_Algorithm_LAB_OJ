#include <iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[1002];
	int b[1002];
	int n;
	cin >> n;
	int i=0;
	while(n--){
		cin >> a[i];
		cin >> b[i];
		i++;
	}
	int len=i--;
	for(int j=0;j<len;j++){
		for(int k=j+1;k<len;k++){
			if(a[j]+b[j]>a[k]+b[k]){
		int tmp1=a[j];
		int tmp2=b[j];
		a[j]=a[k];
		b[j]=b[k];
		a[k]=tmp1;
		b[k]=tmp2;
	}
	if(a[j]+b[j]==a[k]+b[k]){
		if(a[j]>a[k]){
			int tmp3=a[j];
			int tmp4=b[j];
			a[j]=a[k];
			b[j]=b[k];
			a[k]=tmp3;
			b[k]=tmp4;
		}
	}
		}
	}
	int res=a[0];
	int sum=0;
	int m;
	for(i=0;i<len;i++){
		m=a[i]-sum;
		if(m<res)
			res=m;
		sum+=b[i];
	}
	cout << res;
	cout << endl;	
}