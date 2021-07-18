#include<iostream>

using namespace std;

class node{
	public:
	node* left=NULL,*right=NULL;
	int val=0;
	node(int val):val(val){};
};

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

node* LRrotate(node* root){
	root->left=RRrotate(root->left);
	return LLrotate(root);
}

node* RLrotate(node* root){
	root->right=LLrotate(root->right);
	return RRrotate(root);
}

int getHeight(node* root){
	if(root==NULL){
		return 0;
	}
	return max(getHeight(root->left),getHeight(root->right))+1;
}

bool balanced(node *left,node* right){
	return abs(getHeight(left)-getHeight(right))<2;
}

node* insert(node* root,int val){
	if(root==NULL){
		node *temp=new node(val);
		root=temp;
		return root;
	}
	if(val>root->val){
		root->right=insert(root->right,val);
		if(!balanced(root->left,root->right)){
			if(val>root->right->val){
				root=RRrotate(root);
			}
			else{
				root=RLrotate(root);
			}
		}
	}
	else{
		root->left=insert(root->left,val);
		if(!balanced(root->left,root->right)){
			if(val<root->left->val){
				root=LLrotate(root);
			}
			else{
				root=LRrotate(root);
			}
		}
	}
	return root;
}

int main(){
	int num;
	cin>>num;
	node *root=NULL;
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		root=insert(root,temp);
	}
	cout<<root->val;
}