#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> nums;

int solution(vector<int>& nums){
	vector<int> tmp;
	for(int i=0;i<nums.size();i++){
		if(tmp.size()==0||tmp.back()<nums[i])
			tmp.push_back(nums[i]);
		else{
			int low=0;
			int high=tmp.size()-1;
			int mid;
			while(low<=high){
				mid=low+(high-low)/2;
				if(tmp[mid]<nums[i])
					low=mid+1;
				else
					high=mid-1;
			}
			tmp[low]=nums[i];
		}
	}
	return tmp.size();
}

int main(){
	int length;
	cin>>length;
	vector<int> nums(length);
	for(int i=0;i<length;i++){
		cin >> nums[i];
	}
	cout << solution(nums);
    
    cout << endl;
    return 0;
}
