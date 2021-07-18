#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<assert.h>
using namespace std;

class data{
    public:
    string id,next;
    int key;
    bool in=false;
    data(string id,int key,string next):id(id),key(key),next(next){};
};

bool cmp(data d0,data d1){
    return d0.key<d1.key;
}

int main(){
    int num_nodes;
    string yummy;
    cin>>num_nodes>>yummy;
    map<string,int> MAP;
    vector<data> vec_data;
    for(int i=0;i<num_nodes;i++){
        string id,next;
        int key;
        cin>>id>>key>>next;
        data temp_data(id,key,next);
        MAP[id]=i;
        vec_data.push_back(temp_data);
    }
    if(MAP.find(yummy)==MAP.end()){
        cout<<0<<" "<<-1;
        return 0;
    }
    int flag[num_nodes]{0};
    string pointer=yummy;
    while(num_nodes!=0&&pointer!="-1"){
        cout<<"Setting "<<MAP[pointer]<<endl;
        vec_data[MAP[pointer]].in=true;
        pointer=vec_data[MAP[pointer]].next;
    }
    sort(vec_data.begin(),vec_data.end(),cmp);
    cout<<num_nodes;
    for(int i=0;i<num_nodes;i++){
            if(!vec_data[i].in){
                continue;
            }
        cout<<" "<<vec_data[i].id<<"\n";
        cout<<vec_data[i].id<<" "<<vec_data[i].key;
    }
    cout<<" "<<-1;
    
}