#include<iostream>
#include<queue>
#include<math.h>
#include<map>
#define maxn 10001
using namespace std;
map<int,vector<int>> m;
int sale[maxn]{0};
int num;
double price,increment;

void DFS(int root,double &sum,int dep){
	if(sale[root]!=0){
		//cout<<dep<<"\n";
		sum+=pow(1.0+increment,dep)*price*sale[root];
	}
	else{
		for(int i : m[root])
			DFS(i,sum,dep+1);
	}
}

int main(){
	cin>>num>>price>>increment;
	increment/=100.0;
	for(int i=0;i<num;i++){
		int num_child;
		cin>>num_child;
		if(num_child!=0){
			vector<int> temp(num_child);
			for(int j=0;j<num_child;j++){
				cin>>temp[j];
			}
			m.insert(make_pair(i,temp));
		}
		else{
			cin>>sale[i];
		}
	}
	double res;
	DFS(0,res,0);
	printf("%.1f",res);

	
}