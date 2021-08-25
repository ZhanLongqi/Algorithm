#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class node{
	public:
		node *left=nullptr,*right=nullptr;
		int val;
		node(){};
};

void midTraverse(node* curr,vector<int> val,int &count){
	if(curr==nullptr)return;
	midTraverse(curr->left,val,count);
	curr->val=val[count++];
	midTraverse(curr->right,val,count);
}

int main(){
	int num;
	cin>>num;
	vector<node> nodes(num);
	for(int i=0;i<num;i++){
		int temp[2];
		cin>>temp[0]>>temp[1];
		if(temp[0]!=-1){
			nodes[i].left=&nodes[temp[0]];
		}
		if(temp[1]!=-1){
			nodes[i].right=&nodes[temp[1]];
		}
	}
	vector<int> val(num);
	for(int i=0;i<num;i++)cin>>val[i];
	sort(val.begin(),val.end());
	int count=0;
	midTraverse(&nodes[0],val,count);
	queue<node*> que;
	vector<int> res;
	que.push(&nodes[0]);
	count=1;
	while(!que.empty()){
		int new_count=0;
		for(int i=0;i<count;i++){
			node *temp=que.front();
			que.pop();
			res.push_back(temp->val);
			if(temp->left!=nullptr){
				que.push(temp->left);
				new_count++;
			}
			if(temp->right!=nullptr){
				que.push(temp->right);
				new_count++;
			}
		}
		count=new_count;
	}
	for(int i=0;i<res.size();i++){
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
}