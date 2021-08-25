#include<iostream>
#include<vector>

using namespace std;
int M,N,L,T;
vector<int> parent,count;
int getParent(int index){
	if(parent[index]!=index){
		parent[index]=getParent(parent[index]);
		return parent[index];
	}
	else{
		return index;
	}
}

int getIndex(int i,int j,int k){
	return i*M*N+j*N+k;
}

int main(){
	cin>>M>>N>>L>>T;
	parent.resize(M*N*L);
	count.resize(M*N*L);
	fill(&count[0],&count[0]+M*N*L,0);
	int m[L][M][N],res=0;
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				cin>>m[i][j][k];
				parent[getIndex(i,j,k)]=getIndex(i,j,k);
			}
		}
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(m[i][j][k]==1){
					if(i-1>=0&&m[i-1][j][k]==1){
						parent[getParent(getIndex(i-1,j,k))]=getIndex(i,j,k);
					}
					if(j-1>=0&&m[i][j-1][k]==1){
						parent[getParent(getIndex(i,j-1,k))]=getIndex(i,j,k);
					}
					if(k-1>=0&&m[i][j][k-1]==1){
						parent[getParent(getIndex(i,j,k-1))]=getIndex(i,j,k);
					}
				}
			}
		}
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(m[i][j][k]==1)
				count[getParent(getIndex(i,j,k))]++;
			}
		}
	}

	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(count[getIndex(i,j,k)]>=T){
					res+=count[getIndex(i,j,k)];
				}
			}
		}
	}
	cout<<res;
}