#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num_dis, num_query;
    cin>>num_dis;
    int dis[num_dis]{0};
    long dp[num_dis+1]{0};
    for(int i=1;i<=num_dis;i++){
        cin>>dis[i];
        dp[i]=dp[i-1]+dis[i];
    }
    cin>>num_query;
    vector<pair<int,int>> query;
    for(int i=0;i<num_query;i++){
        int temp1,temp0;
        cin>>temp0>>temp1;
        if(temp0>temp1){
            int temp=temp0;
            temp0=temp1;
            temp1=temp;
        }
        query.push_back(make_pair(temp0-1,temp1-1));
    } 
    for(int i=0;i<num_query;i++){
        int temp=dp[query[i].second]-dp[query[i].first];
        //cout<<dp[query[i].second]<<"  "<<dp[query[i].first]<<endl;
        temp=min(temp,int(dp[num_dis]-temp));
        cout<<temp<<endl;
    }
}