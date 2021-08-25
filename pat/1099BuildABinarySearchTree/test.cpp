#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class node{
	public:
	int index,val;
	node* left=nullptr,*right=nullptr;
	node(){};
};

void f(node *root,int &count,vector<int> nums){
	if(root==nullptr)return;
	f(root->left,count,nums);
	root->val=nums[count];
	count++;
	f(root->right,count,nums);
}

int main(){
	int num;
	cin>>num;
	vector<node> nodes(num);
	for(int i=0;i<num;i++){
		int left,right;
		cin>>left>>right;
		if(left!=-1){
			nodes[i].left=&nodes[left];
		}
		if(right!=-1){
			nodes[i].right=&nodes[right];
		}
	}
	vector<int> nums(num),res;
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	int k=0;
	f(&nodes[0],k,nums);
	queue<node*> que;
	que.push(&nodes[0]);
	int curr_layer=1,count=1;
	while(!que.empty()){
		curr_layer=count;
		count=0;
		for(int i=0;i<curr_layer;i++){
			node *temp=que.front();
			que.pop();
			res.push_back(temp->val);
			if(temp->left!=nullptr){
				que.push(temp->left);
				count++;
			}
			if(temp->right!=nullptr){
				que.push(temp->right);
				count++;
			}
		}
	}	
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
}