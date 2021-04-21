#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class record{
    public:
    string id,name,grade;
    record(string i,string n,string g):id(i),name(n),grade(g){};
};

int cmp1(record r0,record r1){
    return r0.id<r1.id;
}

int cmp2(record r0,record r1){
    if(r0.name!=r1.name)
    return r0.name<r1.name;
    else{
        return cmp1(r0,r1);
    }
}

int cmp3(record r0,record r1){
    if(r0.grade!=r1.grade)
    return r0.grade<r1.grade;
    else{
        return cmp1(r0,r1);
    }
}

int main(){
    int num_records,query;
    cin>>num_records>>query;
    vector<record> records;
    for(int i=0;i<num_records;i++){
        string temp[3];
        cin>>temp[0]>>temp[1]>>temp[2];
        record temp_record(temp[0],temp[1],temp[2]);
        records.push_back(temp_record);
    }
    if(query==1){
        sort(records.begin(),records.end(),cmp1);
    }
    else if(query==2){
        sort(records.begin(),records.end(),cmp2);
    }
    else if(query==3){
        sort(records.begin(),records.end(),cmp3);
    }
    for(int i=0;i<num_records;i++){
        cout<<records[i].id<<" "<<records[i].name<<" "<<records[i].grade<<endl;
    }
}