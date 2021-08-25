#include<iostream>
#include<vector>
#include<queue>
#define maxn 1001
using namespace std;

int m[maxn][maxn];

int main(){
	int num_member,num_parent;
	cin>>num_member>>num_parent;
	vector<vector<int>> child(num_member+1);	
	queue<int> generation;
	for(int i=0;i<num_parent;i++){
		int id,num_child;
		cin>>id>>num_child;
		child[id].resize(num_child);
		for(int j=0;j<num_child;j++){
			cin>>child[id][j];
		}
	}
	generation.push(1);
	int count=1,curr_level=1,max=-1,res_level;
	while(!generation.empty()){
		curr_level++;
		int num=count;
		count=0;
		for(int i=0;i<num;i++){
			int temp=generation.front();
			generation.pop();
			for(int temp_child:child[temp]){
				generation.push(temp_child);
				count++;
			}
		}
		if(count>max){
			max=count;
			res_level=curr_level;
		}
	}
	cout<<max<<" "<<res_level;
}