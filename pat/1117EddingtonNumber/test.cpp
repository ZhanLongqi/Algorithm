#include<iostream>
#include<vector>
#include<assert.h>
#define maxn 1000001
using namespace std;

int tree[maxn]{0};

int main(){
	int num;
	cin>>num;
	vector<int> nums(num);
	int dp[maxn]{0};
	for(int i=0;i<num;i++){
		cin>>nums[i];
        //assert(nums[i]!=0);
		dp[nums[i]]++;
	}
	for(int i=maxn-2;i>=0;i--){
		dp[i]=dp[i+1]+dp[i];
	}
	for(int i=0;i<maxn;i++){
		if(dp[i+1]>i)continue;
		else{
			printf("%d",i-1);
			break;
		}
	}
}