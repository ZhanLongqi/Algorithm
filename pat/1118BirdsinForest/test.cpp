#include<iostream>
#include<set>
#include<vector>
#define maxn 10001

using namespace std;
int parent[maxn];

int getParent(int pos){
    if(parent[pos]==pos)return pos;
    parent[pos]=getParent(parent[pos]);
    return parent[pos];
}

int main(){
    int num_pic;
    cin>>num_pic;
    for(int i=0;i<maxn;i++)parent[i]=i;
    int max=0;
    for(int i=0;i<num_pic;i++){
        int num_birds,p;
        cin>>num_birds>>p;
        if(p>max)max=p;
        for(int i=0;i<num_birds-1;i++){
            int q=0;
            cin>>q;
            if(q>max)max=q;
            parent[getParent(q)]=getParent(p);
        }
    }
    int num_query;
    cin>>num_query;
    vector<pair<int,int>> queries;
    for(int i=0;i<num_query;i++){
        int t[2];
        cin>>t[0]>>t[1];
        queries.push_back(make_pair(t[0],t[1]));
    }
    set<int> trees;
    for(int i=1;i<=max;i++){
        trees.insert(getParent(i));
    }
    printf("%d %d\n",trees.size(),max);
    for(int i=0;i<num_query;i++){
        if(getParent(queries[i].first)==getParent(queries[i].second)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}