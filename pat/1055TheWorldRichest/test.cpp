#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class data{
    public:
    string name;
    int age,weight;
    data(string name,int age,int weight):name(name),age(age),weight(weight){};
};

bool cmp(data d1,data d2){
    if(d1.weight!=d2.weight){
        return d1.weight>d2.weight;
    } 
    else if(d1.age!=d2.age){
        return d1.age<d2.age;
    }
    else{
        return d1.name<d2.name;
    }
}

class query{
    public:
    int num,min,max;
    query(int num,int min,int max):num(num),min(min),max(max){};
};

int main(){
    int num_data,num_query;
    cin>>num_data>>num_query;
    vector<data> data_set;
    for(int i=0;i<num_data;i++){
        string temp_name;
        int temp_age,temp_weight;
        cin>>temp_name>>temp_age>>temp_weight;
        data temp_data(temp_name,temp_age,temp_weight);
        data_set.push_back(temp_data);
    }
    sort(data_set.begin(),data_set.end(),cmp);
    vector<query> qeuries;
    int global_min=INT32_MAX,global_max=-1;
    for(int i=0;i<num_query;i++){
        int temp_num,temp_min,temp_max;
        cin>>temp_num>>temp_min>>temp_max;
        if(temp_min<global_min)global_min=temp_min;
        if(temp_max>global_max)global_max=temp_max;
        query temp_query(temp_num,temp_min,temp_max);
        qeuries.push_back(temp_query);
    }
    for(int i=0;i<num_query;i++){
        cout<<"Case #"<<(i+1)<<":"<<"\n";
        int count=qeuries[i].num,min=qeuries[i].min,max=qeuries[i].max;
        int it=0;
        if(min>global_max||max<global_min){
            cout<<"None"<<"\n";
            continue;
        }
        while(it<num_data&&count>0){
            if(data_set[it].age<min||data_set[it].age>max){
                it++;
                continue;
            }
            else{
                cout<<data_set[it].name<<" "<<data_set[it].age<<" "<<data_set[it].weight<<"\n";
                it++;
                count--;
            }
        }
        if(count==qeuries[i].num){
            cout<<"None"<<"\n";
            continue;
        }
    }
}