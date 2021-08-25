#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int main(){
	int num,root=-1;
	long double price,increment;
	cin>>num>>price>>increment;
	increment/=100.f;
	vector<vector<int>> child(num);
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		if(temp==-1){
			root=i;
		}
		else
			child[temp].push_back(i);
	}
	queue<int> que;
	que.push(root);
	int curr_layer=1,count=1,layer=-1;
	while(!que.empty()){
		curr_layer=count;
		count=0;
		for(int i=0;i<curr_layer;i++){
			int temp=que.front();
			que.pop();
			for(int j=0;j<child[temp].size();j++){
				que.push(child[temp][j]);
				count++;
			}
		}
		layer++;
	}
	printf("%.2llf %d",pow(1.0+increment,layer)*price,curr_layer);
}