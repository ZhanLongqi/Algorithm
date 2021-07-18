#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nodes;
vector<vector<int>> result;
void DFS(vector<vector<int>> tree,int curr,int target,int sum,vector<int> &way);
int cmp(int n0,int n1){
    if(nodes[n0]!=nodes[n1]){
        return nodes[n0]>nodes[n1];
    }
    return n0>n1;
}

int main(){
    int num_nodes,num_none_leaf,target;
    cin>>num_nodes>>num_none_leaf>>target;
    for(int i=0;i<num_nodes;i++){
        int temp;
        cin>>temp;
        nodes.push_back(temp);
    }
    vector<vector<int>> tree(num_nodes);
    for(int i=0;i<num_none_leaf;i++){
        int id,num_child;
        cin>>id>>num_child;
        for(int j=0;j<num_child;j++){
            int temp_num;
            cin>>temp_num;
            tree[id].push_back(temp_num);
        }
        sort(tree[id].begin(),tree[id].end(),cmp);
    }
    vector<int> temp;
    DFS(tree,0,target,0,temp);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            if(j!=0)
                cout<<" ";
            cout<<result[i][j];
        }
            cout<<"\n";
    }
}
void DFS(vector<vector<int>> tree,int curr,int target,int sum,vector<int> &way){
    sum+=nodes[curr];
    //cout<<"DFS: "<<curr<<" sum: "<<sum<<endl;
    way.push_back(nodes[curr]);
    if(sum==target&&tree[curr].size()==0){
        vector<int> temp=way;
        result.push_back(way);
        way.pop_back();
        return;
    }
    for(int i=0;i<tree[curr].size();i++){
        DFS(tree,tree[curr][i],target,sum,way);
    }
    way.pop_back();
}