#include<iostream>
#include<vector>
#include<set>
#define maxn 1001
using namespace std;

int m[maxn][maxn];

int main(){
    int num_road,num_vertic;
    cin>>num_vertic>>num_road;
    for(int i=0;i<num_road;i++){
        int t[2];
        cin>>t[0]>>t[1];
        m[t[0]][t[1]]=1;
        m[t[1]][t[0]]=1;
    }
    int num_query;
    cin>>num_query;
    vector<vector<int>> queries;
    for(int i=0;i<num_query;i++){
        int n;
        cin>>n;
        vector<int> query(n);
        for(int j=0;j<n;j++)cin>>query[j];
        queries.push_back(query);
    } 
    for(int i=0;i<num_query;i++){
        if(queries[i].size()<num_vertic+1||queries[i][0]!=queries[i].back()){
            printf("No\n");
            continue;
        }
        set<int> included;
        bool circle=true;
        included.insert(queries[i][0]);
        for(int j=1;j<queries[i].size();j++){
            if(m[queries[i][j]][queries[i][j-1]]!=1){
                circle=false;
                break;
            }
            set<int>::iterator it=included.find(queries[i][j]);
            if(it!=included.end())break;
            included.insert(queries[i][j]);
        }
       if(circle&&included.size()==num_vertic){
           printf("Yes\n");
       }
       else{
           printf("No\n");
       }

    }
}