#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
int K;
class node{
    public:
    int value,index,next,address;
    bool valid=false;
};

bool cmp(node a,node b){
    if(a.value<0&&b.value<0){
        return a.index<b.index;
    }
    else if(a.value<0&&b.value>=0){
        return true;
    }
    else if(a.value>=0&&b.value<0){
        return false;
    }
    else if(a.value<=K&&b.value<=K){
        return a.index<b.index;
    }
    else if(a.value<=K&&b.value>K){
        return true;
    }
    else if(a.value>K&&b.value<=K){
        return false;
    }
    else {
        return a.index<b.index;
    }
}

int main(){
    int root,num_node;
    cin>>root>>num_node>>K;
    map<int,node> m;
    for(int i=0;i<num_node;i++){
       node n;
       cin>>n.address>>n.value>>n.next;
       m.insert(make_pair(n.address,n)); 
    }
    int curr=root,count=0;
    while(curr!=-1){
        m[curr].index=count++;
        m[curr].valid=true;
        curr=m[curr].next;
    }
    auto it=m.begin();
    vector<node> res; 
    while(it!=m.end()){
        if(it->second.valid)
            res.push_back(it->second);
        it++;
    }
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size()-1;i++){
        
        printf("%05d %d %05d\n",res[i].address,res[i].value,res[i+1].address);
    }
    printf("%05d %d -1\n",res[res.size()-1].address,res[res.size()-1].value);
}