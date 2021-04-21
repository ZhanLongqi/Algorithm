#include<iostream>
#include<vector>
class road{
    public:
    int origin;
    int dest;
    int len;
    road(){
        scanf("%d %d %d",&origin,&dest,&len);
    }
    road(int ori,int d,int l):origin(ori),dest(d),len(l){};
};
void get_shortest(int ori,int dest,int len,int &shortest,int  &count,std::vector<road> roads,bool traveled[],int num_rescue[],int rescue,int &max_rescue);
std::vector<road> get_adj(int ori,std::vector<road> roads,bool traveled[]);
int main(){
    int M,N,C_1,C_2;
    scanf("%d %d %d %d",&M,&N,&C_1,&C_2);
    int num_rescue[M];
    for(int i=0;i<M;i++){
        scanf("%d",&num_rescue[i]);
    }
    //road roads[N];
    std::vector<road> roads;
    for(int i=0;i<N;i++){
        road temp;
        roads.push_back(temp);
    }
    bool traveled[M]{0};
    traveled[C_1]=true;
    int shortest=INT32_MAX;
    int max_rescue;
    int count=0;
    get_shortest(C_1,C_2,0,shortest,count,roads,traveled,num_rescue,num_rescue[C_1],max_rescue);
    printf("%d %d",count,max_rescue);
}
void get_shortest(int ori,int dest,int len,int &shortest,int  &count,std::vector<road> roads,bool traveled[],int num_rescue[],int rescue,int &max_rescue){
    if(ori==dest){
        if(len<shortest){
            max_rescue=rescue;
            shortest=len;
            count=1;
        }
        else {
            count++;
            if(rescue>max_rescue)
                max_rescue=rescue;
        }
    }
    std::vector<road> adj;
    adj=get_adj(ori,roads,traveled);
    for(int i=0;i<adj.size();i++){
        if(adj[i].len+len>shortest)
            continue;
        traveled[adj[i].dest]=true;
        get_shortest(adj[i].dest,dest,adj[i].len+len,shortest,count,roads,traveled,num_rescue,rescue+num_rescue[adj[i].dest],max_rescue);
        traveled[adj[i].dest]=false;
    }
}

std::vector<road> get_adj(int ori,std::vector<road> roads,bool traveled[]){
    std::vector<road> ans;

    for(int i=0;i<roads.size();i++){
        if(traveled[roads[i].origin]&&traveled[roads[i].dest])
            continue;
        if(roads[i].origin==ori){
            ans.push_back(roads[i]);
        }
        else if(roads[i].dest==ori){
            road temp(roads[i].dest,roads[i].origin,roads[i].len);
            ans.push_back(temp);
        }
    }
    //printf("getting %d for %d ",ans.size(),ori);
    return ans;
}