#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class node{
	public:
	int index;
	node *left=nullptr,*right=nullptr;
};

void in_trav(node* root,vector<int> &res){
	if(root==nullptr)return;
	in_trav(root->left,res);
	res.push_back(root->index);
	in_trav(root->right,res);
}

int main(){
	int num;
	cin>>num;
	bool leaf[num]{false};
	vector<node> nodes;
	for(int i=0;i<num;i++){
		node n;
		n.index=i;
		nodes.push_back(n);
	}
	for(int i=0;i<num;i++){
		string s[2];
		cin>>s[0]>>s[1];
		if(s[0]!="-"){
			nodes[i].right=&nodes[stoi(s[0])];
			leaf[stoi(s[0])]=true;
		}
		if(s[1]!="-"){
			nodes[i].left=&nodes[stoi(s[1])];
			leaf[stoi(s[1])]=true;
		}
	}
	int root=0;
	while(leaf[root]){
		root++;
	}
	queue<node> que;
	vector<int> layer_tranverse,in_tranverse;
	que.push(nodes[root]);
	int curr_layer=1,count=1;
	while(!que.empty()){
		curr_layer=count;
		count=0;
		for(int i=0;i<curr_layer;i++){
			node t=que.front();
			que.pop();
			layer_tranverse.push_back(t.index);
			if(t.left!=nullptr){
				que.push(*t.left);
				count++;
			}
			if(t.right!=nullptr){
				que.push(*t.right);
				count++;
			}
		}
	}
	in_trav(&nodes[root],in_tranverse);
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<layer_tranverse[i];
	}
	cout<<"\n";
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<in_tranverse[i];
	}

}