#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

class node{
	public:
		int val=-1,index=-1,next=-1;
		node* nextnode;
};

int main(){
	int start,num;
	cin>>start>>num;
	map<int,node> nodes;
	for(int i=0;i<num;i++){
		node k;
		cin>>k.index>>k.val>>k.next;
		nodes.insert(make_pair(k.index,k));
	}
	vector<int> nums;
	map<int,node>::iterator it=nodes.find(start);
	set<int> included;
	node ori,removed;
	node *ori_tail=&ori,*removed_tail=&removed;	
	int count[2]{0};
	if(it==nodes.end())return 0;
	for(int i=0;i<num&&it!=nodes.end();i++){
		if(included.find(abs((*it).second.val))==included.end()){
			included.insert(abs((*it).second.val));
			ori_tail->nextnode=&(*it).second;
			ori_tail=ori_tail->nextnode;
			count[0]++;
		}
		else{
			removed_tail->nextnode=&(*it).second;
			removed_tail=removed_tail->nextnode;
			count[1]++;
		}
		it=nodes.find((*it).second.next);
	}	
	if(count[0]>0){
	ori=*ori.nextnode;
	for(int i=0;i<count[0]-1;i++){
		printf("%05d %d %05d\n",ori.index,ori.val,ori.nextnode->index);
		ori=*ori.nextnode;
	}
	}
	if(count[1]>0){
	printf("%05d %d -1\n",ori.index,ori.val);
	removed=*removed.nextnode;
	for(int i=0;i<count[1]-1;i++){
		printf("%05d %d %05d\n",removed.index,removed.val,removed.nextnode->index);
		removed=*removed.nextnode;
	}
	printf("%05d %d -1",removed.index,removed.val);
	}
}