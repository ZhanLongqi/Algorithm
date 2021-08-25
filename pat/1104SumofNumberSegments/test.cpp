#include<iostream>
#include<vector>
typedef long double ld;
using namespace std;

int main(){
	int num;
	cin>>num;
	vector<ld> nums(num),dp(num);
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	fill(&dp[0],&dp[0]+num,0.f);
	dp[0]=nums[0];
	ld sum=nums[0];
	for(int i=1;i<num;i++){
		dp[i]=dp[i-1]+(i+1)*nums[i];
		sum+=dp[i];
	}
	printf("%.2f",double(sum));
}