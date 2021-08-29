#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<assert.h>
#include<set>
using namespace std;
map<int,set<int>> m;
map<int,int> gender;
map<int,bool> visited;
vector<vector<int>> res;
void DFS(int a,int b,int curr,int dep){
    auto it=m.find(a),it2=m.find(b);
    if(it==m.end()||it2==m.end())return;
    for(int i:it->second){
        if(i==b||i==a||gender[i]!=gender[a])continue;
        auto friends=m.find(i);
        for(int j:it2->second){
            if(j==a||j==b||gender[j]!=gender[b])continue;
            auto same=friends->second.find(j);
            if(same!=friends->second.end()){
                vector<int> t={i,j};
                res.push_back(vector<int>(t));
            }
        }
    }
}

bool cmp(vector<int> a,vector<int> b){
    if(abs(a[0])!=abs(b[0]))return abs(a[0])<abs(b[0]);
    return abs(a[1])<abs(b[1]);
}

int main(){
    int num,num_relation;
    cin>>num>>num_relation;
    for(int i=0;i<num_relation;i++){
        string s[2];
        cin>>s[0]>>s[1];
        int a[2]={stoi(s[0]),stoi(s[1])};
        for(int j=0;j<2;j++){
            auto it=m.find(a[j]);
            if(it==m.end()){
                set<int> t;
                m.insert(make_pair(a[j],t));
                gender.insert(make_pair(a[j],s[j][0]=='-'?-1:1));
                visited.insert(make_pair(a[j],false));
                it=m.find(a[j]);
            }
            it->second.insert(a[(j+1)%2]);
        }
    }
    int num_query;
    cin>>num_query;
    vector<pair<int,int>> queries;
    for(int i=0;i<num_query;i++){
        int a,b;
        cin>>a>>b;
        queries.push_back(make_pair(a,b));
    }
    for(int i=0;i<num_query;i++){
        int a=queries[i].first,b=queries[i].second;
        vector<int> path;
        res.clear();
        DFS(a,b,a,1);
        sort(res.begin(),res.end(),cmp);
        printf("%d\n",res.size());
        for(int j=0;j<res.size();j++){
            printf("%04d %04d\n",abs(res[j][0]),abs(res[j][1]));
        }
    }

}