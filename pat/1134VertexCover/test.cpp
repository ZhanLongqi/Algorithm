#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int num_vertex,num_edge;
    cin>>num_vertex>>num_edge;
    vector<pair<int,int>> edges;
    for(int i=0;i<num_edge;i++){
        int t[2];
        cin>>t[0]>>t[1];
        edges.push_back(make_pair(t[0],t[1]));
    } 
    int num_query,num_set,s;
    cin>>num_query;
    vector<bool> res;
    for(int i=0;i<num_query;i++){
        bool incident=true;
        set<int> sets;
        cin>>num_set;
        for(int j=0;j<num_set;j++){
            cin>>s;
            sets.insert(s);
        }
        for(int j=0;j<num_edge;j++){
            auto l=sets.find(edges[j].first),r=sets.find(edges[j].second);
            if(l==sets.end()&&r==sets.end()){
                incident=false;
                break;
            }
        }
        res.push_back(incident);
    }
    for(int i=0;i<num_query;i++){
        if(res[i])printf("YES\n");
        else printf("NO\n");
    }
}