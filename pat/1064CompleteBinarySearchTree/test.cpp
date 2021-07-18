#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mid(int node,vector<int> &tree,vector<int> assign,int &count){
	if(node*2+1<tree.size()){
		mid(node*2+1,tree,assign,count);
	}
	tree[node]=assign[count];
	count++;
	if(node*2+2<tree.size()){
		mid(node*2+2,tree,assign,count);
	}
}

int main(){
	int num;
	cin>>num;
	vector<int> nums(num);
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	vector<int> tree(num);
	int count=0;
	mid(0,tree,nums,count);
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<tree[i];
	}
}