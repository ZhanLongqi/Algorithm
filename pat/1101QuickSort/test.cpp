#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;


int main(){
	int num;
	cin>>num;
	vector<ll> nums(num);
	for(int i=0;i<num;i++){
		scanf("%lld",&nums[i]);
	}
	vector<ll> dpl(num),dpr(num);
	dpl[0]=nums[0],dpr[num-1]=nums[num-1];
	for(int i=1;i<num;i++){
		if(nums[i]>dpl[i-1]){
			dpl[i]=nums[i];
		}
		else{
			dpl[i]=dpl[i-1];
		}
	}
	for(int i=num-2;i>=0;i--){
		if(nums[i]<dpr[i+1]){
			dpr[i]=nums[i];
		}
		else{
			dpr[i]=dpr[i+1];
		}
	}
	vector<ll> res;
	for(int i=0;i<num;i++){
		if((i==0||nums[i]>=dpl[i-1])&&(i==num-1||nums[i]<=dpr[i+1])){
			res.push_back(nums[i]);
		}
	}
	cout<<res.size()<<"\n";

	for(int i=0;i<res.size();i++){
		if(i!=0)cout<<" ";
		printf("%lld",res[i]);
	}
	cout<<"\n";
}