#include<iostream>
#include<vector>
using namespace std;
#define maxn 10001
vector<vector<int>> neighbour;
bool visited[maxn]{false};
int num_vertics,num_edge;
bool circle=false;
vector<vector<int>> res;

int parent[10001];

int getParent(int pos){
    if(parent[pos]==pos)return pos;
    parent[pos]=getParent(parent[pos]);
    return parent[pos];
}

int main(){
    cin>>num_vertics>>num_edge;
    neighbour.resize(num_vertics+1);
    for(int i=1;i<=num_vertics;i++){
        parent[i]=i;
    }
    for(int i=0;i<num_edge;i++){
        int t[2];
        cin>>t[0]>>t[1];
        neighbour[t[0]].push_back(t[1]);
        neighbour[t[1]].push_back(t[0]);
        parent[getParent(t[1])]=getParent(t[0]);
    }
    bool linked=true;
    for(int i=2;i<=num_vertics;i++){
        if(getParent(i)!=getParent(i-1)){
            linked=false;
        }
    }
    vector<int> road;
    visited[1]=true;
    //DFS(1,road,1);
    int odd=0,even=0;
    for(int i=0;i<num_vertics;i++){
        if(i!=0)cout<<" ";
        if(neighbour[i+1].size()%2==0)even++;
        else odd++;
        printf("%d",neighbour[i+1].size());
    }
    if(even==num_vertics&&linked){
        printf("\nEulerian");
    }
    else if(odd==2&&linked){
        printf("\nSemi-Eulerian");
    }
    else{
        printf("\nNon-Eulerian");
    }
    
}