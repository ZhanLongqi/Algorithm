#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solved=false;
vector<int> result;
void get(vector<int> coins,vector<int> &paid,int start,int target){
	if(target==0){
		solved=true;
		result=vector<int>(paid);
		return;
	}
	if(start>=coins.size()||coins[start]>target){
		return;
	}
	for(int i=start;i<coins.size()&&!solved;i++){
		paid.push_back(coins[i]);
		get(coins,paid,i+1,target-coins[i]);
		paid.pop_back();
	}
}

int main(){
	int num_coins, target;
	cin>>num_coins>>target;
	vector<int> coins(num_coins);
	for(int i=0;i<num_coins;i++){
		cin>>coins[i];
	}
	sort(coins.begin(),coins.end());
	vector<int> paid(0);
	get(coins,paid,0,target);
	if(result.size()!=0)
	for(int i=0;i<result.size();i++){
		if(i!=0)cout<<" ";
		cout<<result[i];
	}
	else{
		cout<<"No Solution";
	}
}