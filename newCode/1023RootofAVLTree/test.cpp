#include<iostream>

using namespace std;

using namespace std;

class node{
	public:
		node* left=nullptr,*right=nullptr;
		int val;
		node(){};
};

int getDep(node* root){
	if(root==nullptr)return 0;
	return max(getDep(root->left),getDep(root->right))+1;
}

bool isBalanced(node *root){
	return abs(getDep(root->left)-getDep(root->right))<2;
}


node* RRrotate(node* root){
	node* x=root->right;
	root->right=x->left;
	x->left=root;
	return x;
}

node* LLrotate(node* root){
	node* x=root->left;
	root->left=x->right;
	x->right=root;
	return x;
}

node* RLrotate(node* root){
	root->right=LLrotate(root->right);
	return RRrotate(root);
}

node* LRrotate(node* root){
	root->left=RRrotate(root->left);
	return LLrotate(root);
}

node* insert(node *root,int val){
	if(root==nullptr){
		node *t=new node();
		t->val=val;
		return t;
	}

	if(val>=root->val){
		root->right=insert(root->right,val);
		if(!isBalanced(root)){
			if(getDep(root->right->right)>getDep(root->right->left)){
				return RRrotate(root);
			}
			else{
				return RLrotate(root);
			}
		}
	}
	else {
		root->left=insert(root->left,val);
		if(!isBalanced(root)){
			if(getDep(root->left->left)>getDep(root->left->right)){
				return LLrotate(root);
			}
			else{
				return LRrotate(root);
			}
		}
	}
	return root;
}



int main(){
	int size;
	cin>>size;
	node* root=nullptr;
	for(int i=0;i<size;i++){
		int temp;
		cin>>temp;
		root=insert(root,temp);
	}
	cout<<root->val;
}