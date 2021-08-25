#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long num,p;
	cin>>num>>p;
	vector<long> nums(num);
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	int next=0;
	while(next<num&&nums[0]*p>=nums[next]){
		next++;
	}
	int max=next;
	for(int i=1;i<num;i++){
		if(next>=num)break;
		while(next<num&&nums[i]*p>=nums[next])next++;
		if((next-i)>max)max=next-i;
	}
	cout<<max;
}