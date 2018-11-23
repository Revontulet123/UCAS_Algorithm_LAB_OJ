#include <iostream>
#include <math.h>
int *nums;

int solution(int *nums){
	int maximum=1;
	int n=nums.size();
	int tmp[n]={1};
	int i=1;
	int j=0;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(nums[i]>nums[j])
			tmp[i]=max(tmp[i],tmp[j]+1);
		}
		maximum=max(maximum,tmp[i])
	}
	return maximum;
}

int main(){
	int length;
	cin>>length;
	nums=new int[length];
	for(int i=0;i<length;i++){
		cin >> nums[i];
	}
	cout << solution(nums);
    
    cout << endl;
    return 0;
}