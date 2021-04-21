#include<iostream>
using namespace std;
int dfs(int u[],int bridge[],int index,int size,int city_checked){
    u[index]=1;
    for(int i=0;i<size;i++){
        if(u[i]==0&&bridge[index*size+i]>0&&i!=city_checked){
            dfs(u,bridge,i,size,city_checked);
        }
    }
}
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int bridge[N*N]{0};    
    for(int i=0;i<M;i++){
        int ori,dest;
        cin>>ori>>dest;
        bridge[(ori-1)*N+dest-1]=1;
        bridge[(dest-1)*N+ori-1]=1;
    }
    int check[K];
    for(int i=0;i<K;i++){
        int temp;
        cin>>temp;
        check[i]=temp-1;
    }
    for(int i=0;i<K;i++){
        int u[N]{0};                                  
        int city_checked=check[i];
        int count=0;
        for(int j=0;j<N;j++){
            if(j==city_checked){
                continue;
            }
            if(u[j]==0){
                dfs(u,bridge,j,N,city_checked);
                count++;
            }
        }
        if(i!=0)cout<<endl;
        cout<<count-1;
    }
}