#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
typedef long double ld;
using namespace std;

int main(){
	int num;
	double price,increment;
	cin>>num>>price>>increment;
	increment/=100.f;
	vector<vector<int>> child(num);
	for(int i=0;i<num;i++){
		int n;
		cin>>n;
		child[i].resize(n);
		for(int j=0;j<n;j++){
			cin>>child[i][j];
		}
	}	
	queue<int> que;
	que.push(0);
	int curr_layer=1,count=1,num_retailer=0,layer=0;
	while(!que.empty()){
		curr_layer=count;
		count=0;
		for(int i=0;i<curr_layer;i++){
			int c=que.front();
			if(child[c].size()==0){
				num_retailer++;
			}

			for(int j=0;j<child[c].size();j++){
				que.push(child[c][j]);
				count++;
			}
			
			que.pop();
		}
		if(num_retailer!=0){
			break;
		}
		layer++;
	}
	printf("%.4lf %d",pow(1.f+(increment),layer)*price,num_retailer);
}