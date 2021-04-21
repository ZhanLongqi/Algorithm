#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int poptime=0,endtime=0;
    queue<int> que;
};

int main(){
    int N,M,K,Q;
    cin>>N>>M>>K>>Q;
    int request_time[K];
    for(int i=0;i<K;i++){
        cin>>request_time[i];
    }
    int query[Q];
    node windows[N];
    for(int i=0;i<Q;i++){
        cin>>query[i];
    }
    int endtime[K];
    int index=0;
    bool sorry[K]{0};
    for(int i=0;i<(N*M<K?N*M:K);i++){
        windows[i%N].que.push(request_time[i]);
        if(i<N){
        windows[i%N].poptime=windows[i%N].endtime+request_time[i];
        }
        windows[i%N].endtime=windows[i%N].endtime+request_time[i];
        endtime[i]=windows[i%N].endtime;
        if(windows[i%N].endtime>=540){
            sorry[i]=true;
        }
        //cout<<endtime[i]<<endl;
    }
    for(int i=N*M;i<K;i++){
        int min=INT32_MAX,min_index=0;
        for(int j=0;j<N;j++){
            if(windows[j].poptime<min){
                min=windows[j].poptime;
                min_index=j;
            }
        }
        if(!windows[min_index].que.empty())
        windows[min_index].que.pop();
        windows[min_index].que.push(request_time[i]);
        windows[min_index].poptime=windows[min_index].poptime+windows[min_index].que.front();
        if(windows[min_index].endtime>=540){
            sorry[i]=true;
        }
        windows[min_index].endtime+=request_time[i];
        endtime[i]=windows[min_index].endtime;
        //cout<<endtime[i]<<endl;
    }


    for(int i=0;i<Q;i++){
        if(i!=0)cout<<endl;
        //cout<<endtime[query[i]];
        if(sorry[query[i]-1]){
            printf("Sorry");
        }
        else
        printf("%02d:%02d",(endtime[query[i]-1]+480)/60,(endtime[query[i]-1]+480)%60);
    }

}