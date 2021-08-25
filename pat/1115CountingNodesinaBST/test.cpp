#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int val;
		node* left=nullptr,*right=nullptr;
};

node* insert(node* root,int val){
	if(root==nullptr){
		node* n=new node();
		n->val=val;
		return n;
	}
	if(val<=root->val){
		root->left = insert(root->left,val);
	}
	else{
		root->right = insert(root->right,val);
	}
	return root;
}

int main(){
	int num;
	cin>>num;
	node *root=nullptr;	
	for(int i=0;i<num;i++){
		int n=0;
		cin>>n;
		root=insert(root,n);
	}
	queue<node*> que;
	que.push(root);
	int curr_layer=1,count=1,layer=0;
	vector<vector<node*>> layers;
	while(!que.empty()){
		curr_layer=count;
		vector<node*> temp_layer;
		count=0;
		for(int i=0;i<curr_layer;i++){
			node *curr=que.front();
			if(curr->left!=nullptr){
				que.push(curr->left);
				count++;
			}
			if(curr->right!=nullptr){
				que.push(curr->right);
				count++;
			}
			temp_layer.push_back(curr);
			que.pop();
		}
		layers.push_back(temp_layer);
		layer++;
	}	
	int a=layers[layers.size()-2].size(),b=layers[layers.size()-1].size();
	printf("%d + %d = %d",a,b,a+b);

}