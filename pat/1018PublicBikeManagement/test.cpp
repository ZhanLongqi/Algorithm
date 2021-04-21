#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;
int min_len=INT32_MAX;
vector<vector<int>> ans;
void dfs(int origin,int dest,vector<int> path,int len,vector<int> map,vector<bool> visited);
int main(){
    int capacity,num_stat,dest,num_road;
    scanf("%d %d %d %d",&capacity,&num_stat,&dest,&num_road);
    dest;                                                              
    int num_bikes[num_stat+1];
    for(int i=1;i<=num_stat;i++){
        scanf("%d",&num_bikes[i]);
    }
    vector<int> map(num_stat*num_stat+2*num_stat+1,-1);
    vector<bool> visited(num_stat+1);
    visited[0]=true;
    for(int i=0;i<num_road;i++){                 
        int temp1,temp2,len;
        scanf("%d %d %d",&temp1,&temp2,&len);
        map[temp1*(num_stat+1)+temp2]=len;
        map[temp2*(num_stat+1)+temp1]=len;
    }
    vector<int> path;
    path.push_back(0);
    dfs(0,dest,path,0,map,visited);
    int bikes[ans.size()];
    int min=INT32_MAX,min_index=0;
    for(int i=0;i<ans.size();i++){
        int bike=0;
        int temp_max_bike_needed=0;
        for(int j=1;j<ans[i].size();j++){
            bike+=num_bikes[ans[i][j]]-capacity/2;
            //cout<<bike;
            if(bike<temp_max_bike_needed){
                temp_max_bike_needed=bike;
            }
        }
        //cout<<temp_max_bike_needed;
        temp_max_bike_needed=max(0,-1*temp_max_bike_needed);
        if(temp_max_bike_needed<min){
            min=temp_max_bike_needed;
            min_index=i;
        }
        bikes[i]=max(0,bike);
    }
   cout<<min<<" ";
    for(int i=0;i<ans[min_index].size();i++){
        if(i!=0)cout<<"->";
        cout<<ans[min_index][i];
    }
    cout<<" "<<bikes[min_index];
}

void dfs(int origin,int dest,vector<int> path,int len,vector<int> map,vector<bool> visited){
    int size=visited.size();
    if(len>min_len){
        return;  
    }
    if(origin==dest){
        if(len==min_len){
            ans.push_back(path);
        }
        else if(len<min_len){
            ans.clear();
            ans.push_back(path);
            min_len=len;
        }
        return;
    }
    for(int i=0;i<size;i++){
        if(!visited[i]&&map[origin*size+i]!=-1){
            visited[i]=true;
            path.push_back(i);
            //cout<<map[origin*size+i]<<" ";
            //cout<<"from "<<origin<<"  to "<<i<<endl;
            dfs(i,dest,path,len+map[origin*size+i],map,visited);
            path.pop_back();
            visited[i]=false;
        }
    }
}