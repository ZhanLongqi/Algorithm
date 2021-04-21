#include<iostream>
#include<vector>

using namespace std;


int min_cost=INT32_MAX;
int min_dis=INT32_MAX;
vector<int> result_path;

class road{
    public:
    int dest,distance,cost;
    road(int dest,int dis,int cost):dest(dest),distance(dis),cost(cost){};
};
int dfs(int curr_city,vector<bool> visited,vector<vector<road> > map,int dest,int dis,int cost,vector<int> path);

int main(){
    int num_cities,num_highways,start,dest;
    cin>>num_cities>>num_highways>>start>>dest;
    vector<vector<road>> map(num_cities);
    vector<bool> visited(num_cities);
    for(int i=0;i<num_highways;i++){
        int temp[4];
        cin>>temp[0]>>temp[1]>>temp[2]>>temp[3];
        road temp_highway0(temp[1],temp[2],temp[3]);
        map[temp[0]].push_back(temp_highway0);
        road temp_highway1(temp[0],temp[2],temp[3]);
        map[temp[1]].push_back(temp_highway1);
    }
    vector<int> path;
    visited[start]=true;
    dfs(start,visited,map,dest,0,0,path);
    for(int i=0;i<result_path.size();i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<result_path[i];
    }
    cout<<" "<<min_dis<<" "<<min_cost;
    return 0;
}

int dfs(int curr_city,vector<bool> visited,vector<vector<road> > map,int dest,int dis,int cost,vector<int> path){
    
    path.push_back(curr_city);
    if(curr_city==dest){
        if(dis<min_dis||(dis==min_dis&&cost<min_cost)){
            //cout<<"find a better result"<<endl;
            min_cost=cost;
            result_path=vector<int>(path);
            min_dis=dis;
        }
        return 0;
    }
    
    for(int i=0;i<map[curr_city].size();i++){
        road city_to_visit=map[curr_city][i];
        if(!visited[city_to_visit.dest]){
            visited[city_to_visit.dest]=true;
            //vector<int> temp(path);
            //temp.push_back(curr_city);
            //cout<<"dfs: "<<curr_city<<" "<<city_to_visit.dest<<" "<<dis<<" "<<cost<<endl;
            dfs(city_to_visit.dest,visited,map,dest,dis+city_to_visit.distance,cost+city_to_visit.cost,path);
            visited[city_to_visit.dest]=false;
        }
    }
    return 0;
}