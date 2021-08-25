#include<iostream>
#include<vector>
#define maxn 1001
#define inf 99999999
using namespace std;

int road[maxn][maxn],dis[maxn];
int capacity,num_station,target,num_roads;
bool visited[maxn];
vector<vector<int>> pre;
vector<vector<int>> res;
vector<int> route;

void DFS(int pos){
	if(pos==0){
		res.push_back(vector<int>(route));
		return;		
	}
	for(int i:pre[pos]){
		route.push_back(i);
		DFS(i);
		route.pop_back();
	}
}

int main(){
	cin>>capacity>>num_station>>target>>num_roads;
	int num_bikes[num_station+1];
	for(int i=1;i<=num_station;i++){
		cin>>num_bikes[i];
	}
	fill(&road[0][0],&road[0][0]+maxn*maxn,inf);
	fill(&dis[0],&dis[0]+maxn,inf);
	fill(&visited[0],&visited[0]+maxn,false);
	pre.resize(num_station+1);
	for(int i=0;i<num_roads;i++){
		int temp[3];
		cin>>temp[0]>>temp[1]>>temp[2];
		if(temp[2]<road[temp[0]][temp[1]]){
			road[temp[0]][temp[1]]=temp[2];
			road[temp[1]][temp[0]]=temp[2];
		}
	}
	dis[0]=0;

	for(int i=0;i<num_station+1;i++){
		int min=INT32_MAX,min_index=-1;
		for(int j=0;j<num_station+1;j++){
			if(!visited[j]&&dis[j]<min){
				min=dis[j];
				min_index=j;
			}
		}
		if(min_index==-1)break;
		visited[min_index]=true;
		for(int j=0;j<num_station+1;j++){
			if(!visited[j]&&road[min_index][j]!=inf){
				if(road[min_index][j]+dis[min_index]<dis[j]){
					dis[j]=road[min_index][j]+dis[min_index];
					pre[j].clear();
					pre[j].push_back(min_index);
				}
				else if(road[min_index][j]+dis[min_index]==dis[j]){
					pre[j].push_back(min_index);
				}
			}
		}
	}
	route.push_back(target);
	DFS(target);
	int min=INT32_MAX,min_index=-1,back=INT32_MAX;
	for(int i=0;i<res.size();i++){
		int sum=0,take=0;
		for(int j=res[i].size()-2;j>=0;j--){
			if(num_bikes[res[i][j]]<capacity/2){
				take-=capacity/2-num_bikes[res[i][j]];
				if(take<0){
					sum-=take;
					take=0;
				}
			}
			else{
				take+=num_bikes[res[i][j]]-capacity/2;
			}
		}
		if(sum<min||(sum==min&&take<back)){
			min=sum;
			min_index=i;
			back=take;
		}
	}
	if(min>0)cout<<min;
	else cout<<0;
	cout<<" ";
	for(int i=res[min_index].size()-1;i>=0;i--){
		cout<<res[min_index][i];
		if(i!=0)cout<<"->";
	}
	cout<<" "<<back;
}