#include<iostream>
#include<map>
#define maxn 10001
using namespace std;

int parent[maxn];
bool valid[maxn];
int getParent(int pos){
	if(parent[pos]==pos)return pos;
	parent[pos]=getParent(parent[pos]);
	return parent[pos];
}

int main(){
	int num;
	cin>>num;
	
}