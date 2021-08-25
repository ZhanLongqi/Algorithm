#include<iostream>
#include<vector>
using namespace std;
#define maxn 10001
int m[maxn][maxn]{0};
bool visited[maxn]{false};
int num_users,max_layer,num_query;

void BFS(int root,int &count,int depth){
	//cout<<" to "<<root<<" ";
	visited[root] = true;
	if(depth==max_layer)return;
	vector<int> child; 
	for(int i = 1;i<=num_users; i++){
		if(!visited[i] && m[root][i]==1){
			child.push_back(i);
			visited[i] = true;
			count++;
		}
	}
	for(int i : child)
		BFS(i, count, depth+1);

}

int main(){
	cin>>num_users>>max_layer;
	for(int i = 0; i < num_users; i++){
		int num_followers;
		cin>>num_followers;
		for(int j = 0; j < num_followers; j++){
			int temp=0;
			cin>>temp;
			m[temp][i+1] = 1;
		}
	}
	cin>>num_query;
	int query[num_query],result[num_query]{0};
	for(int i = 0;i < num_query;i++){
		cin>>query[i];
	}	
	for(int i = 0;i < num_query;i++){
		fill(&visited[0],&visited[0]+maxn,false);
		//cout<<"root: ";
		BFS(query[i],result[i],0);
		
		 cout<<result[i]<<"\n";
	}

}
