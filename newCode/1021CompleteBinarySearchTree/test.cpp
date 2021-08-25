#include<iostream>
#include<vector>	
#include<queue>
#include<algorithm>
using namespace std;

void setTree(vector<int> &tree,vector<int> seq,int &count,int size,int curr){
	if(curr>=size)return;
	setTree(tree,seq,count,size,curr*2+1);
	tree[curr]=seq[count++];
	setTree(tree,seq,count,size,curr*2+2);
}

int main(){
	int size;
	cin>>size;
	vector<int> seq(size),tree(size);
	for(int i=0;i<size;i++){
		cin>>seq[i];
	}
	sort(seq.begin(),seq.end());
	int count=0;
	setTree(tree,seq,count,size,0);
	queue<int> que;
	for(int i=0;i<size;i++){
		if(i!=0)cout<<" ";
		cout<<tree[i];
	}
	
}