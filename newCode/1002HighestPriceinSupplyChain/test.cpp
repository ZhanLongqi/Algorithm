#include<iostream>
#include<math.h>
#include<vector>
#define maxn 1001
#define inf 99999999
using namespace std;

int deepest=-1;
float increment,price,res=0.f;
vector<vector<int>> m;
int num,root,num_res;

void DFS(int pos,int dep){
	for(int i:m[pos]){
		DFS(i,dep+1);
	}
	if(m[pos].size()==0&&dep>=deepest){
		if(dep>deepest){
			num_res=1;
			deepest=dep;
		}
		else{
			num_res+=1;
		}
	}
}

int main(){
	cin>>num>>price>>increment;
	increment/=100.0;
	m.resize(num);
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		if(temp==-1)root=i;
		else m[temp].push_back(i);
	}
	DFS(root,0);
	float result=pow(1.0+increment,deepest)*price;
	printf("%.2f %d",result,num_res);
}