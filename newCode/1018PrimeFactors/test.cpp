#include<iostream>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;

void getPirme(ll target,vector<int> &res){
	if(target<=2){
		res.push_back(target);
		return;
	}
	for(ll i=2;i<=sqrt(target);i++){
		if(target%i==0){
			target/=i;
			res.push_back(int(i));
			i=1;
		}
	}
	if(target!=1)
	res.push_back(target);
}

int main(){
	ll num;
	cin>>num;	
	if(num==0){
		cout<<"0=0";
		return 0;
	}
	vector<int> res;
	getPirme(num,res);
	cout<<num<<"=";
	for(int i=0;i<res.size();i++){
		if(i!=0)cout<<"*";
		int count=1;
		while(res[i]==res[i+1]){
			count++;
			i++;
		}		
		cout<<res[i];
		if(count!=1)cout<<"^"<<count;
	}
}