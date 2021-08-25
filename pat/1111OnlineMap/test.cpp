#include<iostream>
#include<vector>
#define maxn 1001
#define inf 999999
using namespace std;

int dis[maxn][maxn];
int s[maxn][maxn];
bool visited[maxn];
int min_dis[maxn],shortest_dis=inf,shortest_time=inf,fastest_time=inf,fastest_dis=inf;
vector<int> shortest,fastest;
vector<vector<int>> pre;

int num_intersection,num_street,source,dest;
void DFS(int curr,vector<int> road,int t,int d){
	if(curr==source&&t<shortest_time){
		shortest_dis=d;
		shortest_time=t;
		shortest=vector<int>(road);
		return;
	}
	else{
		for(int i=0;i<pre[curr].size();i++){
			road.push_back(pre[curr][i]);
			DFS(pre[curr][i],road,t+s[pre[curr][i]][curr],d+dis[pre[curr][i]][curr]);
			road.pop_back();
		}
	}
}

void DFS2(int curr,vector<int> road,int t,int n){
	if(curr==source&&n<fastest_dis){
		fastest_dis=n;
		fastest_time=t;
		fastest=vector<int>(road);
		return;
	}
	else{
		for(int i=0;i<pre[curr].size();i++){
			road.push_back(pre[curr][i]);
			DFS2(pre[curr][i],road,t+s[pre[curr][i]][curr],n+1);
			road.pop_back();
		}
	}
}

int main(){
	cin>>num_intersection>>num_street;
	fill(&dis[0][0],&dis[0][0]+maxn*maxn,inf);
	fill(&s[0][0],&s[0][0]+maxn*maxn,inf);
	for(int i=0;i<num_street;i++){
		int index[2],one_way,len,t;
		cin>>index[0]>>index[1]>>one_way>>len>>t;
		dis[index[0]][index[1]]=len;
		s[index[0]][index[1]]=t;
		if(one_way==0){
			dis[index[1]][index[0]]=len;
			s[index[1]][index[0]]=t;
		}
	}
	cin>>source>>dest;
	
	fill(&visited[0],&visited[0]+maxn,false);
	fill(&min_dis[0],&min_dis[0]+maxn,inf);
	dis[source][source]=0;
	min_dis[source]=0;
	pre.resize(num_intersection);
	for(int i=0;i<num_intersection;i++){

		int min=inf,min_index;
		for(int j=0;j<num_intersection;j++){
			if(!visited[j]&&min_dis[j]<min){
				min=min_dis[j];
				min_index=j;
			}
		}
		if(min_index==-1){
			break;
		}
		visited[min_index]=true;
		for(int j=0;j<num_intersection;j++){
			if(!visited[j]&&min+dis[min_index][j]<min_dis[j]){
				pre[j].clear();
				pre[j].push_back(min_index);
				min_dis[j]=min+dis[min_index][j];
			}
			else if(!visited[j]&&min+dis[min_index][j]==min_dis[j]){
				pre[j].push_back(min_index);
			}
		}
	}
	vector<int> road;
	road.push_back(dest);
	DFS(dest,road,0,0);

	fill(&visited[0],&visited[0]+maxn,false);
	fill(&min_dis[0],&min_dis[0]+maxn,inf);
	s[source][source]=0;
	min_dis[source]=0;
	pre.clear();
	pre.resize(num_intersection);
	for(int i=0;i<num_intersection;i++){

		int min=inf,min_index;
		for(int j=0;j<num_intersection;j++){
			if(!visited[j]&&min_dis[j]<min){
				min=min_dis[j];
				min_index=j;
			}
		}
		if(min_index==-1){
			break;
		}
		visited[min_index]=true;
		for(int j=0;j<num_intersection;j++){
			if(!visited[j]&&min+s[min_index][j]<min_dis[j]){
				pre[j].clear();
				pre[j].push_back(min_index);
				min_dis[j]=min+s[min_index][j];
			}
			else if(!visited[j]&&min+s[min_index][j]==min_dis[j]){
				pre[j].push_back(min_index);
			}
		}
	}
	vector<int> road2;
	road2.push_back(dest);
	DFS2(dest,road2,0,0);

	bool same=true;
	if(shortest.size()!=fastest.size()){
		same=false;
	}
	else{
		for(int i=0;i<shortest.size();i++){
			if(shortest[i]!=fastest[i]){
				same=false;
				break;
			}
		}
	}
	if(same){
		printf("Distance = %d; Time = %d: ",shortest_dis,fastest_time);
		for(int i=0;i<shortest.size();i++){
			if(i!=0)cout<<" -> ";
			cout<<shortest[shortest.size()-1-i];
		}
	}
	else{
		printf("Distance = %d ",shortest_dis);
		for(int i=0;i<shortest.size();i++){
			if(i!=0)cout<<" -> ";
			cout<<shortest[shortest.size()-1-i];
		}
		printf("\nTime = %d " ,fastest_time);
		for(int i=0;i<fastest.size();i++){
			if(i!=0)cout<<" -> ";
			cout<<fastest[fastest.size()-i-1];
		}
	}
	
}