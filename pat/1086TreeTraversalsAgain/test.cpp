#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> pre,mid,post;
void f(int root,int start,int end){
	if(start>end)return;
	int i=start;
	while(i<end&&mid[i]!=pre[root])i++;
	f(root+1,start,i-1);
	f(root+(i-start)+1,i+1,end);
	post.push_back(pre[root]);
}

int main(){
	int num;
	cin>>num;
	stack<int> s;
	pre.resize(num+1),mid.resize(num+1);
	int count1=1,count2=1;
	for(int i=0;i<2*num;i++){
		string command;
		cin>>command;
		if(command=="Push"){
			int temp=0;
			cin>>temp;
			s.push(temp);
			pre[count1]=temp;
			count1++;
		}
		else{
			mid[count2]=s.top();
			s.pop();
			count2++;
		}
	}
	f(1,1,num);
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<post[i];
	}
}