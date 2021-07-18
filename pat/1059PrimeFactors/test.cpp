#include<iostream>
#include<map>
#include<math.h>
using namespace std;

void getPrime(int target,map<int,int> &m){
	for(int i=2;i<=sqrt(target);){
		//cout<<"getting prime of"<<target<<" from "<<i<<"\n";
		if(target%i==0){
			if(m.find(i)==m.end()){
				m.insert(make_pair(i,1));
			}
			else{
				m[i]=m[i]+1;
			}
			target=target/i;
			i=2;
		}
		else{
			i++;
		}
	}
	if(target!=1){
		if(m.find(target)==m.end()){
			m.insert(make_pair(target,1));
		}
		else{
			m[target]=m[target]+1;
		}
	}
}

int main(){
	int target;
	cin>>target;
	map<int,int> result;
	getPrime(target,result);
	map<int,int>::iterator it=result.begin();
	cout<<target<<"=";
	while(it!=result.end()){
		if(it!=result.begin()) cout<<"*";
		cout<<(*it).first;
		if((*it).second!=1) cout<<"^"<<(*it).second;
		it++;
	}
}