#include<iostream>
#include<vector>
using namespace std;
int size[3],T,M,N,L;

int getIndex(int z,int y,int x){
	return z*(M*N)+y*N+x;
}

int getParent(int index,int *parent){
	if(parent[index]!=index){
		parent[index]=getParent(parent[index],parent);
	}
	return parent[index];
}
int main(){
	cin>>M>>N>>L>>T;
	int parent[M*N*L];
	int m[L][M][N];
	int stroke[M*N*L];
	fill(&stroke[0],&stroke[0]+M*N*L,0);
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
					parent[getIndex(i,j,k)]=getIndex(i,j,k);
					cin>>m[i][j][k];
					if(m[i][j][k]==0)continue;
					if(i>0&&m[i-1][j][k]==1)parent[getParent(getIndex(i-1,j,k),parent)]=getIndex(i,j,k),parent;
					if(j>0&&m[i][j-1][k]==1)parent[getParent(getIndex(i,j-1,k),parent)]=getIndex(i,j,k),parent;
					if(k>0&&m[i][j][k-1]==1)parent[getParent(getIndex(i,j,k-1),parent)]=getIndex(i,j,k),parent;	
			}
		}
	}
	for(int i=0;i<M*N*L;i++){
		if(*(&m[0][0][0]+i)==1)
		stroke[getParent(i,parent)]++;
	}
	int sum=0;
	for(int i=0;i<M*N*L;i++){
		if(stroke[i]>=T){
			sum+=stroke[i];
		}
	}
	cout<<sum;
}