#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int getParent(int target,const int parent[]);

class gang{
    public:
    int total,max=-1,max_index=-1,num_member=0;
    bool is_a_gang=false;
    gang(){};
};

int main(){
    int MAP[1000][1000]={0};
    int parent[1000];
    for(int i=0;i<1000;i++){
        parent[i]=i;
    }
    int num_data,threshold;
    vector<string> names;
    cin>>num_data>>threshold;
    int count=0;
    map<string,int> str2num;
    for(int i=0;i<num_data;i++){
        string n1,n2;
        int time;
        cin>>n1>>n2;
        cin>>time;
        if(n1>n2){
            string temp=n1;
            n1=n2;
            n2=temp;
        }
        if(str2num.find(n2)==str2num.end()){
            str2num[n2]=count++;
            names.push_back(n2);
        }
        if(str2num.find(n1)==str2num.end()){
            str2num[n1]=count++;
            names.push_back(n1);
        }
    MAP[str2num[n1]][str2num[n2]]+=time;
    MAP[str2num[n2]][str2num[n1]]+=time;
    parent[str2num[n2]]=getParent(str2num[n1],parent);
    }    

    int sum[count]{0};
    map<int,gang> gangs;
    int num_real_gangs=0;
    for(int i=0;i<num_data;i++){
        for(int j=0;j<count;j++){
            sum[i]+=MAP[i][j];
        }
        if(gangs.find(getParent(i,parent))==gangs.end()){
            gang temp_gang;
            gangs[getParent(i,parent)]=temp_gang;
        }
        gang* pointer=&gangs[getParent(i,parent)];
           // cout<<names[i]<<" : "<<sum[i]<<endl;
        if(sum[i]>pointer->max){
            pointer->max=sum[i];
            pointer->max_index=i;
        }
        bool last=pointer->is_a_gang;
        pointer->total+=sum[i];
        pointer->num_member++;
        if(pointer->total/2>threshold&&pointer->num_member>2){
            pointer->is_a_gang=true;
        }
        if(!last&&pointer->is_a_gang){
            //cout<<"new gang"<<endl;
            num_real_gangs++;
        }
    }
    cout<<num_real_gangs<<endl;
    for(int i=0;i<gangs.size();i++){
        if(gangs[i].is_a_gang){
            cout<<names[gangs[i].max_index]<<" "<<gangs[i].num_member<<endl;
        }
    }
    
}

int getParent(int target,const int parent[]){
    while(target!=parent[target]){
        target=parent[target];
    }
    return target;
}