#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
char* a;
char* b;
int opt[1200][1200];
int Minimum(int num1,int num2, int num3)
{
	return min(num1,min(num2,num3));
}

int match(char m, char n){
	if(m==n)
		return 0;
	if((m=='G'&&n=='C')||(m=='C'&&n=='G'))
		return 4;
	return 5;
}

int score(char* a,char* b){
	int i,j;
	i=0;
	j=0;
	int row;
	int clo;
	while((a[i]=='A')||(a[i]=='G')||(a[i]=='C')||(a[i]=='T')){
		i++;
	}
	row=i+1;
	while((b[j]=='A')||(b[j]=='G')||(b[j]=='C')||(b[j]=='T')){
		j++;
	}
	clo=j+1;
	opt[0][0]=0;
	for(i=1;i<row;i++){
		opt[i][0]=3*i;
	}
	for(j=1;j<clo;j++){
		opt[0][j]=3*j;
	}
	for(i=1;i<row;i++){
		for(j=1;j<clo;j++){
			opt[i][j]=Minimum((opt[i-1][j-1]+match(a[i-1],b[j-1])),(opt[i-1][j]+3),(opt[i][j-1]+3));
			//cout<<opt[i][j]<<endl;
		}
	}
	return opt[i-1][j-1];

}
int main(){
	a=new char[1000];
	b=new char[1000];
	cin>>a;
	cin>>b;
	cout << score(a,b);
    cout << endl;
    return 0;
}
