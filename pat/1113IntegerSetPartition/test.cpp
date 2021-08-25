#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int num;
	cin>>num;
	vector<int> nums(num);
	for(int i=0;i<num;i++)cin>>nums[i];
	sort(nums.begin(),nums.end());
	int n=num%2;
	long long sum=0;
	for(int i=num-1;i>=num/2;i--){
		sum+=nums[i];
	}
	for(int i=num/2-1;i>=0;i--){
		sum-=nums[i];
	}
	printf("%d %lld",n,sum);
}