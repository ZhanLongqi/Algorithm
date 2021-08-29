#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<string,int> a,pair<string,int> b){
    return a.second<b.second;
}

int main(){
    int num_forward,skip,first;
    cin>>num_forward>>skip>>first;
    set<string> winner;
    int count=1;
    vector<string> res;
    for(int i=0;i<num_forward;i++){
        string candidate;
        cin>>candidate;
        set<string>::iterator it=winner.find(candidate);
        if(it!=winner.end())continue;
        if((count-first)>=0&&(count-first)%skip==0){
            res.push_back(candidate);
            winner.insert(candidate);
        }
        count++;
    }
    if(res.size()==0){
        printf("Keep going...");
    }
    for(int i=0;i<res.size();i++){
        printf("%s\n",res[i].c_str());
    }

}