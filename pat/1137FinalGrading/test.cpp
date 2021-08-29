#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<math.h>
using namespace std;

class student{
    public:
        int score=-1,mid_term=-1,final_term=-1,total=0;
        string index;
        student(){};
};

bool cmp(student a,student b){
    if(a.total!=b.total){
        return a.total>b.total;
    }
    return a.index<b.index;
}

int main(){
    int M,N,K;
    cin>>M>>N>>K;
    map<string,student> m;
    string index;
    int score;
    for(int i=0;i<M;i++){
        cin>>index>>score;
        if(score<200)continue;
        student t;
        t.index=index;
        t.score=score;
        m.insert(make_pair(index,t));
    }    
    for(int i=0;i<N;i++){
        cin>>index>>score;
        auto it=m.find(index);
        if(it==m.end())continue;
        it->second.mid_term=score;
    }
    for(int i=0;i<K;i++){
        cin>>index>>score;
        auto it=m.find(index);
        if(it==m.end())continue;
        it->second.final_term=score;

        if(score>it->second.mid_term){
            it->second.total=score;
        }
        else if(score<=it->second.mid_term){
            it->second.total=round(0.6*score+0.4*it->second.mid_term);
        }
        else{
            assert(false);
        }
        //it->second.total=int(it->second.total+0.5);

    }
    vector<student> n;
    auto it=m.begin();
    while(it!=m.end()){
        n.push_back(it->second);
        it++;
    }
    sort(n.begin(),n.end(),cmp);
    for(int i=0;i<n.size();i++){
        if(n[i].total>=60)
            printf("%s %d %d %d %d\n",n[i].index.c_str(),n[i].score,n[i].mid_term,n[i].final_term,n[i].total);
    }
}