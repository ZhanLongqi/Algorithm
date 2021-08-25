#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> subscribers;
vector<bool> visited;
vector<int> query;
queue<int> que;
int num_users,max_dep;

int BFS(int root){
	fill(visited.begin(),visited.end(),false);
	while(!que.empty())que.pop();
	visited[root]=true;
	que.push(root);
	int count=1,res=0,dep=0;
	while(!que.empty()&&dep<max_dep){
		dep++;
		int num=0;
		for(int i=0;i<count;i++){
			int user=que.front();
			que.pop();
			for(int k:subscribers[user]){
				if(visited[k])continue;
				res++;
				num++;
				que.push(k);
				visited[k]=true;
			}
		}
		count=num;
	}
	return res;
}

int main(){
	cin>>num_users>>max_dep;
	int num_follow;
	subscribers.resize(num_users+1);
	visited.resize(num_users+1);
	fill(visited.begin(),visited.end(),false);
	for(int i=1;i<=num_users;i++){
		cin>>num_follow;
		int temp;
		for(int j=0;j<num_follow;j++){
			cin>>temp;
			subscribers[temp].push_back(i);
		}
	}	
	int num_query;
	cin>>num_query;
	query.resize(num_query);
	for(int i=0;i<num_query;i++)cin>>query[i];
	for(int i=0;i<num_query;i++){
		if(i!=0)cout<<"\n";
		cout<<BFS(query[i]);
	}

}