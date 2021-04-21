#include<iostream>
#include<vector>
#include<set>
using namespace std;
int getRoot(int[],int);
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<pair<int,int>> bridge;
    for(int i=0;i<M;i++){
        int origin,dest;
        cin>>origin>>dest;

        bridge.push_back(make_pair(origin-1,dest-1));
    }
    if(N<=1){
        cout<<0;
        return 0;
    }
    int check[K];
    for(int i=0;i<K;i++){
        cin>>check[i];
        check[i]--;
    }
    int parent[N];
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            parent[j]=j;
        }
        int city_checked=check[i];
        for(int j=0;j<M;j++){
            if(bridge[j].first!=city_checked&&bridge[j].second!=city_checked){
                if(getRoot(parent,bridge[j].second)==getRoot(parent,bridge[j].first)){
                    continue;
                }
                parent[getRoot(parent,bridge[j].second)]=bridge[j].first;//********
            }
        }
        int count=0;
        for(int j=0;j<N;j++){
            if(parent[j]==j){
                count++;
            }
        }
        if(i!=0)cout<<endl;
        cout<<count-2;
    }

}
int getRoot(int parent[],int target){
    int temp=target;
    while(parent[temp]!=temp){
        temp=parent[temp];
    }
    return temp;
}
