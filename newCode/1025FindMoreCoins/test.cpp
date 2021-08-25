#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> coins;
vector<int> res;

vector<int> route;

bool cmp(vector<int> v0,vector<int> v1){
	for(int i=0;i<min(v0.size(),v1.size());i++){
		if(v0[i]!=v1[i])return v0[i]<v1[i];
	}
	return v0.size()<v1.size();
}

void f(int pos,int target){
	if(target==0){
		if(res.empty()||cmp(route,res)){
			res=vector<int>(route);
		}
		return;
	}
	if(pos>=coins.size()||coins[pos]>target||!res.empty())return;

	for(int i=pos;i<coins.size();i++){
		route.push_back(coins[i]);
		f(i+1,target-coins[i]);
		route.pop_back();
	}
}

int main(){
	int num_coins,target,sum=0;
	cin>>num_coins>>target;
	coins.resize(num_coins);

	for(int i=0;i<num_coins;i++){
		cin>>coins[i];
		sum+=coins[i];
	}
	if(sum<target){
		cout<<"No Solution";
		return 0;
	}
	sort(coins.begin(),coins.end());
	int start=0,last=0,min=INT32_MAX;
	int range[2];
	f(0,target);
	if(res.empty()){
		cout<<"No Solution";
		return 0;
	}
	for(int i=0;i<res.size();i++){
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
	
}