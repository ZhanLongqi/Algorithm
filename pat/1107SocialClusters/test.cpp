#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int parent[1001];

int getParent(int index){
	if(parent[index]==index)return index;
	parent[index]=getParent(parent[index]);
	return parent[index];
}

int main(){
	int num;
	cin>>num;
	for(int i=0;i<1001;i++)parent[i]=i;
	map<int,int> m;
	vector<int> prime;	
	for(int i=0;i<num;i++){
		int k=-1,p=-1,n=-1;
		scanf("%d: %d",&k,&p);
		prime.push_back(p);
		for(int j=0;j<k-1;j++){
			cin>>n;
			parent[getParent(n)]=getParent(p);
		}
	}
	for(int i=0;i<prime.size();i++){
		map<int,int>::iterator it=m.find(getParent(prime[i]));
		if(it==m.end()){
			m.insert(make_pair(getParent(prime[i]),0));
			it=m.find(getParent(prime[i]));
		}
		(*it).second=(*it).second+1;
		it++;
	}
	map<int,int>::iterator it=m.begin();
	vector<int> res;
	while(it!=m.end()){
		res.push_back((*it).second);
		it++;
	}
	sort(res.begin(),res.end());
	for(int i=res.size()-1;i>=0;i--){
		if(i!=res.size()-1)cout<<" ";
		cout<<res[i];
	}

}