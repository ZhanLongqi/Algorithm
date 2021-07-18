#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int total_color,num_preference,len_stripe;
    cin>>total_color>>num_preference;
    int preference[num_preference+1];
    preference[0]=num_preference+1;
    map<int,int> m;
    for(int i=0;i<num_preference;i++){
        int temp;
        cin>>temp;
        m[temp]=i;    
    }
    cin>>len_stripe;
    vector<int> stripe;
    for(int i=0;i<len_stripe;i++){
        int temp;
        cin>>temp;
        if(m.find(temp)==m.end()){
            continue;
        }
        stripe.push_back(m[temp]);
    }
    if(stripe.size()==0){
        cout<<0;
        return ;
    }
    int dp[stripe.size()]{0};
    dp[0]=1; 
        int count=0,max=0,max_index=0;
    for(int i=1;i<stripe.size();i++){
        count=0;
        max=0;
        max_index=0;
        for(int j=0;j<i;j++){
            if(stripe[j]<=stripe[i]){
                if(dp[j]>=max){
                    dp[i]=dp[j]+1;
                    max=dp[j];
                }
            }
        }
        if(max==0){
            dp[i]=max;
        }
    }
    cout<<dp[stripe.size()-1];
    }