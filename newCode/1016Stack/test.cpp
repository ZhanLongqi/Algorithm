#include<iostream>
#include<stack>
#include<vector>
#define maxn 1000001
using namespace std;

int tree[maxn]{0};

int lowbit(int i){
	return i&-i;
}

void insert(int pos,int i){
	while(pos<maxn){
		tree[pos]+=i;
		pos+=lowbit(pos);
	}
}

int getSum(int pos){
	int res=0;
	while(pos>0){
		res+=tree[pos];
		pos-=lowbit(pos);
	}
	return res;
}

int find(int target){
	int left=1,right=maxn;
	int mid=(left+right)/2;
	while(left<right){
		mid=(left+right)/2;
		int n=getSum(mid);
		if(n>=target){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}

int main(){
	int num=0;
	cin>>num;
	stack<int> s;
	vector<string> commands(num);
	vector<int> targets;
	int count=0;
	for(int i=0;i<num;i++){
		cin>>commands[i];
		if(commands[i]=="Push"){
			int temp;
			cin>>temp;
			targets.push_back(temp);
		}
	}
	count=0,num=0;
	while(num<commands.size()){
		string command=commands[num];

		if(command=="Pop"){
			if(s.empty()){
				cout<<"Invalid\n";
			}
			else{
				cout<<s.top()<<"\n";
				insert(s.top(),-1);
				s.pop();
			}
		}
		else if(command=="Push"){
			int t=targets[count++];
			insert(t,1);
			s.push(t);
		}
		else{
			if(s.empty()){
				cout<<"Invalid\n";
			}
			else{
				int m=(s.size()+1)/2;
				int r=find(m);
				cout<<r<<"\n";
			}
		}
		num++;
	}
}