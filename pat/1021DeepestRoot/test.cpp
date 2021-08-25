#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define maxn 10001
int visited[maxn],num;
vector<vector<int>> m;
int parent[maxn];
int max_depth=0;
set<int> res;

void DFS(int curr,int dep,bool b){

	bool end=true;
	for(int i=1;i<=m[curr].size();i++){
		int next=m[curr][i-1];
		if(visited[next])continue;
		visited[next]=true;
		DFS(next,dep+1,b);
		visited[next]=false;
		end=false;
	}
	if(end&&dep>max_depth){
		max_depth=dep;
		if(b) res.clear();
		res.insert(curr);
	}
	else if(end&&dep==max_depth){
		res.insert(curr);
	}
}

int getParent(int curr){
	if(parent[curr]!=curr){
		parent[curr]=getParent(parent[curr]);
		return parent[curr];
	}
	else {
		return curr;
	}
}

int main(){
	cin>>num;
	m.resize(num+1);
	for(int i=1;i<=num;i++)parent[i]=i;
	for(int i=1;i<=num-1;i++){
		int t[2];
		cin>>t[0]>>t[1];
		m[t[0]].push_back(t[1]);
		m[t[1]].push_back(t[0]);
		parent[getParent(t[1])]=getParent(t[0]);
	}
	set<int> trees;
	for(int i=1;i<=num;i++){
		set<int>::iterator it=trees.find(getParent(i));
		if(it==trees.end()){
			trees.insert(getParent(i));
		}
	}
	if(trees.size()!=1){
		printf("Error: %d components",int(trees.size()));
		return 0;
	}
	fill(&visited[0],&visited[0]+maxn,false);
	visited[1]=true;
	DFS(1,0,true);
	max_depth=0;
	set<int>::iterator it=res.begin();
	fill(&visited[0],&visited[0]+num,false);
	DFS((*it),0,false);
	it++;
	it=res.begin();
	while(it!=res.end()){
		printf("%d\n",(*it));
		it++;
	}
}