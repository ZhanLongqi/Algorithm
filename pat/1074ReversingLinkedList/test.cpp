#include<iostream>
#include<vector>
#include<map>

using namespace std;

class node{
	public:
	int val;
	string index,next_index,last;
	node(){};
	node(string index,string next,int val):index(index),next_index(next),val(val){};
};

void reverse_group(map<string,node> &m,string root,int len,string &start,string &end){
	end=root;
	string curr=m[root].index;
	string last="-1",next="-1";
	for(int i=0;i<len;i++){
		next=m[curr].next_index;
		m[curr].next_index=last;
		last=curr;
		start=curr;
		curr=next;
	}
}

int main(){
	string root;
	int num_node,len;
	cin>>root>>num_node>>len;
	map<string,node> m;
	for(int i=0;i<num_node;i++){
		string index,next;
		int val;
		cin>>index>>val>>next;
		node temp(index,next,val);
		m.insert(make_pair(index,temp));
	}
	int num_group=num_node/len,left=num_node%len;
	vector<string> starts(num_group+1),ends(num_group+1);
	
	string curr=root;
	for(int i=0;i<num_node;i++){
		if(i%len==0){
			starts[i/len]=curr;
		}
		if(i%len==len-1||i==num_node-1){
			ends[i/len]=curr;
		}
		curr=m[curr].next_index;
		if(curr=="-1")break;
	}
	for(int i=0;i<num_group;i++){
		reverse_group(m,starts[i],len,starts[i],ends[i]);
	}
	int last=-1;
	curr=-1;
	for(int i=0;i<num_group-1;i++){
		m[ends[i]].next_index=starts[i+1];
	}
	if(left>0){
		m[ends[num_group-1]].next_index=starts[num_group];
	}
	curr=starts[0];
	for(int i=0;i<num_node;i++){ 
		cout<<m[curr].index<<" "<<m[curr].val<<" "<<m[curr].next_index<<"\n";
		curr=m[curr].next_index;
		if(curr=="-1")break;
	}
}