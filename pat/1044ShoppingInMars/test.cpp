#include<iostream>
#include<vector>

using namespace std;

int main(){
    int num_diamonds,pay;
    cin>>num_diamonds>>pay;
    int diamonds[num_diamonds+1];
    for(int i=0;i<num_diamonds;i++)
        cin>>diamonds[i+1];
    int min_cost=INT32_MAX;
    vector<pair<int,int>> result;
    int last=0;
    int temp_cost=0;
    int j=0;
    for(int i=1;i<=num_diamonds;i++){
        temp_cost-=diamonds[i-1];
        for( j=j+1;j<=num_diamonds;j++){
            temp_cost+=diamonds[j];
            if(temp_cost>min_cost){
                break;
            }
            if(temp_cost>=pay){
                if(temp_cost<min_cost){
                    result.clear();
                    min_cost=temp_cost;
                }
                result.push_back(make_pair(i,j));
                break;
            }
        }
        
    }
    for(int i=0;i<result.size();i++){
        if(i!=0){
            cout<<endl;
        }
        cout<<result[i].first<<"-"<<result[i].second;
    }
}