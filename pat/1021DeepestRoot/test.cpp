#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int dfs(const vector<vector<int>> &map,vector<bool> visited,int node,int num,int count,int &max,set<int> &ans,int root);
int check(vector<int> root);
int getRoot(vector<int> root,int target);
int main(){
    set<int> ans;
    int max=0;
    int num=0;
    cin>>num;
    vector<int> root(num);
    for(int i=0;i<num;i++){
        root[i]=i;
    }

    vector<vector<int>> map2(num);
    vector<bool> visited(num,false);
    

    for(int i=0;i<num-1;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        root[getRoot(root,temp2-1)]=root[getRoot(root,temp1-1)];
        map2[temp1-1].push_back(temp2-1);
        map2[temp2-1].push_back(temp1-1);
    }


    int num_compoents=check(root);
    if(num_compoents>1){
        cout<<"Error: "<<num_compoents<<" components";
        return 0;
    }

    //cout<<(visited[0]?"true":"false")<<endl;
    for(int i=0;i<num;i++){
        dfs(map2,visited,i,num,1,max,ans,i);
    }
    
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<(*i)<<endl;
    }

}

int dfs(const vector<vector<int>> &map,vector<bool> visited,int node,int num,int count,int &max,set<int> &ans,int root){
    //cout<<"DFS:from "<<root+1<<" to "<<node+1<<"  count: "<<count<<endl;
    visited[node]=true;
    bool last=true;


    for(int i=0;i<map[node].size();i++){
        if(!visited[map[node][i]]){
            dfs(map,visited,map[node][i],num,count+1,max,ans,root);
        }
    }
    if(last){
        if(count>max){
            max=count;
            ans.clear();
            ans.insert(root+1);
        }
        else if(count==max){
            ans.insert(root+1);
        }
        //cout<<max<<endl;
    }
    visited[node]=false;
    return 0;
}

int check(vector<int> root){
    
    set<int> res;
    for(int i=0;i<root.size();i++){
        res.insert(getRoot(root,i));
    }
    return res.size();
}

int getRoot(vector<int> root,int target){
    while(root[target]!=target){
        target=root[target];
    }
    return target;
}
