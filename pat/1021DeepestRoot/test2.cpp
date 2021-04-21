#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int getRoot(vector<int> root,int target){
    while(root[target]!=target){
        target=root[target];
    }
    return target;
};
int check(vector<int> root){
    set<int> res;
    for(int i=0;i<root.size();i++){
        res.insert(getRoot(root,i));
    }
    return res.size();
};

int dfs(vector<vector<int>> map,vector<bool> visited,int node,int &max_dep,int dep,vector<int> &result){
    visited[node]=true;
    if(dep==max_dep){
        result.push_back(node);
    }
    else if(dep>max_dep){
        result.clear();
        result.push_back(node);
        max_dep=dep;
    }
    for(int i=0;i<map[node].size();i++){
        if(!visited[map[node][i]])
        dfs(map,visited,map[node][i],max_dep,dep+1,result);
    }
    visited[node]=false;
    return 0;
}

int main(){
    int num;
    cin>>num;
    vector<vector<int> > map(num);
    vector<bool> visited(num);
    vector<int> root(num);
    fill(visited.begin(),visited.end(),false);
    
    for(int i=0;i<num;i++){
        root[i]=i;
    }

    for(int i=0;i<num-1;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        root[getRoot(root,temp2-1)]=root[getRoot(root,temp1-1)];
        map[temp1-1].push_back(temp2-1);
        map[temp2-1].push_back(temp1-1);
    }
    int num_roots=check(root);
    if(num_roots>1){
        cout<<"Error: "<<num_roots<<" components";
        return 0;
    }
    vector<int> res1,res2;
    int max_dep=1;
    dfs(map,visited,num/2,max_dep,1,res1);
    max_dep=1;
    dfs(map,visited,res1[res1.size()/2],max_dep,1,res2);
    set<int> result;
    for(int i=0;i<res1.size();i++){
        result.insert(res1[i]);
        //cout<<res1[i]<<endl;
    }
    for(int i=0;i<res2.size();i++){
        result.insert(res2[i]);
        //cout<<res2[i]<<endl;
    }
    for(auto i=result.begin();i!=result.end();i++){
        cout<<(*i)+1<<endl;
    }
}