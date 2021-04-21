# Emergence

## Description

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected  by some roads. Amount of rescue teams in each city and the length of  each road between any pair of cities are marked on the map. When there  is an emergency call to you from some other city, your job is to lead  your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

## Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one  path from C1 to C2.

## Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.  All  the numbers in a line must be separated by exactly one space, and there  is no extra space allowed at the end of a line.

## 思路

求最短路径数量以及最短路径经过的节点权的最大值

开始是想使用回朔剪枝法,逐个遍历所有节点,若路径长度大于最短路径则剪枝

```c++
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
```

这里是只记录所有路径,虽然储存时节省了空间,但是在后期查找一个节点的临界节点时需要很大的开销,所以需要改进,这里决定使用邻接矩阵

