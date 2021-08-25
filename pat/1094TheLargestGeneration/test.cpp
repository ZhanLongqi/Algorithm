#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<int>> child(N+1);
	for(int i=0;i<M;i++){
		int index,num_child;
		vector<int> k;
		cin>>index>>num_child;
		child[index].resize(num_child);
		for(int j=0;j<num_child;j++){
			cin>>child[index][j];
		}
	}
	queue<int> que;
	que.push(1);
	int curr_layer=0,layer=1,count=1,max=1,max_layer=1;
	while(!que.empty()){
		curr_layer=count;
		layer++;
		count=0;
		for(int i=0;i<curr_layer;i++){
			int temp=que.front();
			que.pop();
			for(int i=0;i<child[temp].size();i++){
				que.push(child[temp][i]);
				count++;
			}
		}
		if(count>max){
			max=count;
			max_layer=layer;
		}
	}
	cout<<max<<" "<<max_layer;

}