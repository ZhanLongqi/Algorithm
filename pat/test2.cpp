#include<iostream>
class solution{
public:
int count=0,max_rescue=0,min_len=INT32_MAX;
    int M,N,C_1,C_2;
    int num_rescue[501];
    int map[501][501];
    int x,y,len;
    bool visited[501]{0};
solution(){
    scanf("%d %d %d %d",&M,&N,&C_1,&C_2);
    for(int i=0;i<M;i++){
        scanf("%d",&num_rescue[i]);
    }
    visited[C_1]=true;
    std::fill(map[0],map[0]+501*501,INT32_MAX);
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&x,&y,&len);
        map[x][y]=len;
        map[y][x]=len;
    }
    get_shortest(C_1,C_2,0,num_rescue[C_1]);
    printf("%d %d",count,max_rescue);
}

void get_shortest(int ori,int dest,int l,int r){
    if(l>min_len)
        return;
    std::cout<<ori<<std::endl;
    if(ori==dest){
        if(l==min_len){
            count++;
            if(r>max_rescue){
                max_rescue=r;
            }
        }
        else{
            min_len=l;
            count=1;
            max_rescue=r;
        }
        return;
    }
    for(int i=0;i<501;i++){
        if(map[ori][i]!=INT32_MAX&&!visited[i]){
        visited[i]=true;
        get_shortest(i,dest,l+map[ori][i],r+num_rescue[i]);
        visited[i]=false;
        }
    }
}

};
int main(){
    solution s;
}
