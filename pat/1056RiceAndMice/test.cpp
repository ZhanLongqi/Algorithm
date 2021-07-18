#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

void show(vector<int> vec);

bool cmp(pair<int,int> p0,pair<int,int> p1){
    return p0.second>p1.second;
}

int main(){
    int num_data,group_size;
    cin>>num_data>>group_size;
    vector<int> weight(num_data);
    vector<int> rank(num_data);
    for(int i=0;i<num_data;i++){
        cin>>weight[i];
    }
    queue<int> q,p;
    for(int i=0;i<num_data;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    while(!q.empty()){
        int l=ceil(float(q.size())/group_size);//q.size()/group_size+(q.size()%group_size==0?0:1);
        for(int i=0;i<l;i++){
            int max=-1,max_index=0;
            for(int j=0;j<group_size&&!q.empty();j++){
                rank[q.front()]=l+1;
                if(weight[q.front()]>max){
                    max=weight[q.front()];
                    max_index=q.front();
                }
                q.pop();
            }
            p.push(max_index);
        }
        if(p.size()==1){
            rank[p.front()]=1;
            break;
        }
    queue<int> empty_que;
    q=p;
    p=empty_que;
    }

    show(rank);
}

void show(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        if(i!=0)cout<<" ";
        cout<<vec[i];
    }
    cout<<endl;
}