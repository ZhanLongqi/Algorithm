#include<iostream>
#include<queue>
#include<math.h>
#include<vector>

using namespace std;

int main(){
	int num;
	cin>>num;
	int child[num][2];
	bool root[num];
	fill(&root[0],&root[0]+num,true);
	for(int i=0;i<num;i++){
		string str[2];
		cin>>str[0]>>str[1];
		if(str[0]!="-"){
			child[i][0]=stoi(str[0]);
			root[stoi(str[0])]=false;
		}
		else child[i][0]=-1;
		if(str[1]!="-"){
			child[i][1]=stoi(str[1]);
			root[stoi(str[1])]=false;
		}
		else child[i][1]=-1;
	}
	int k=0;
	while(!root[k]){
		k++;
	}
	queue<int> que;
	que.push(k);
	int curr_layer=1,count=1,layer=0,last=k;
	vector<vector<int>> layers;
	while (!que.empty())
	{
		vector<int> l;
		curr_layer=count;
		count=0;
		for(int i=0;i<curr_layer;i++){
			int c=que.front();
			l.push_back(c);
			if(child[c][0]!=-1){
				que.push(child[c][0]);
				last=child[c][0];
				count++;
			}
			if(child[c][1]!=-1){
				que.push(child[c][1]);
				last=child[c][1];
				count++;
			}
			que.pop();
		}
		if(count!=0&&curr_layer!=pow(2,layer)){
			cout<<"No "<<k;
			return 0;
		}
		layers.push_back(l);
		layer++;
	}
	if(layer>=2)
	for(int i=0;i<layers[layer-1].size();i++){
		if(layers[layer-1][i]!=child[layers[layer-2][i/2]][i%2]){
			cout<<"No "<<k;
			return 0;
		}
	}
	cout<<"Yes "<<last;
}