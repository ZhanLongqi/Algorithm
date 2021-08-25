#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

class node{
	public:
	string id,next;
	int val,count=0;
};

int main(){
	string root;
	int num_node;
	cin>>root>>num_node;
	map<string,node> list;
	for(int i=0;i<num_node;i++){
		node temp;
		cin>>temp.id>>temp.val>>temp.next;
		list.insert(make_pair(temp.id,temp));
	}
	vector<string> ori,sep;	
	set<int> included;
	string last=root;
	ori.push_back(root);
	included.insert(abs(list[root].val));
	for(int i=0;i<num_node-1;i++){
		string curr=list[last].next;
		int a=abs(list[curr].val);
		if(included.find(a)==included.end()){
			included.insert(a);
			ori.push_back(curr);
		}
		else{
			sep.push_back(curr);
		}
		last=curr;
	}
	for(int i=0;i<ori.size()-1;i++){
		cout<<list[ori[i]].id<<" "<<list[ori[i]].val<<" "<<list[ori[i+1]].id<<"\n";
	}
	cout<<list[ori.back()].id<<" "<<list[ori.back()].val<<" -1\n";
	for(int i=0;i<sep.size()-1;i++){
		cout<<list[sep[i]].id<<" "<<list[sep[i]].val<<" "<<list[sep[i+1]].id<<"\n";
	}
	if(sep.size()>=1){
		cout<<list[sep.back()].id<<" "<<list[sep.back()].val<<" -1\n";
	}

}