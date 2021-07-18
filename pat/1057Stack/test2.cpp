#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> tree(50001);
stack<int> s;
int lowbit(int i){
	return i&(-1*i);
}

int getsum(int pos){
	int sum=0;
	while(pos>0){
		sum+=tree[pos];
		pos-=lowbit(pos);
	}
	return sum;
}

void update(int pos,int k){
	while(pos<tree.size()){
		tree[pos]+=k;
		pos+=lowbit(pos);
	}
}

void getMid(){
	int target=(s.size()+1)/2;
	int left=1,right=50000,mid=(left+right)/2;
	while(left<right){
		//cout<<"checking "<<mid<<" : "<<getsum(mid)<<"  left: "<<left<<"  right: "<<right<<"\n";
		if(getsum(mid)>=target){
			right=mid;
		}
		else{
			left=mid+1;
		}
		mid=(left+right)/2;
	}
	std::cout<<left<<"\n";
}

int main(){
	int num_task;
	cin>>num_task;
	vector<int> tasks;
	vector<int> targets;
	
	for(int i=0;i<num_task;i++){
		string temp_task;
		cin>>temp_task;
		if(temp_task=="Push"){
			int temp_target;
			cin>>temp_target;
			tasks.push_back(0);
			targets.push_back(temp_target);
		}
		else if(temp_task=="Pop"){
			tasks.push_back(1);
		}
		else{
			tasks.push_back(2);
		}
	}
	int count=0;
	for(int i=0;i<num_task;i++){
		if(tasks[i]==0){
			update(targets[count],1);
			s.push(targets[count]);
			count++;
		}
		else if(tasks[i]==1){
			if(s.empty()){
				cout<<"Invalid\n";
			}
			else {
				update(s.top(),-1);
				cout<<s.top()<<"\n";
				s.pop();
			}
		}
		else{
			if(s.empty()){
				cout<<"Invalid\n";
			}
			else{
				getMid();
			}	
		}
	}
}