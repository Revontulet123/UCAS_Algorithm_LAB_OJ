#include <iostream>
#include<algorithm>
using namespace std;
int *rocks;
int L,M,N;
int count_small_than_mid(int *rocks,int mid, int n){
    int start=0;
    int count=0;
    int i=1;
    
    for(int i=1;i<n;i++){
        if (rocks[i] - rocks[start] <= mid)
            {
            count++;

            }
        else
            start = i;}

    return count;
}
int binary_search(int left, int right, int *rocks, int M, int N){
    while (left < right){
        int mid = (left + right)/2;
        if (count_small_than_mid(rocks, mid, N) <= M){
        
            left = mid + 1;
  
            }
        else
            right = mid;}
    return left;
}


int solution(int L,int  M, int N,int *rocks){
    rocks[0]=0;
    rocks[N+1]=L;
    N += 2;
    sort(rocks,rocks+N);
    int min=rocks[1]-rocks[0];
    for(int i=2;i<N;i++){
        if(rocks[i]-rocks[i-1]<min)
            min=rocks[i]-rocks[i-1];
           
    }
    int left=min;
    return binary_search(left, L , rocks, M, N);
}

int main(){
    cin>>L;
    cin>>N;
    cin>>M;
    rocks=new int[N+2];
    for (int i = 1 ; i <= N; i++) {
        cin >> rocks[i];
    }
    cout << solution(L,M,N,rocks);
    cout << endl;
    return 0;
}