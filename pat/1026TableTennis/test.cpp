#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class data{
    public:
    string arrive_time_str;
    int arrive_time=0,request_time,vip=0;
    data(string time1,int time2,int v ):arrive_time_str(time1),request_time(time2),vip(v){
        int base=3600;
        for(int i=0;i<3;i++){
            arrive_time+=((arrive_time_str[i*3]-'0')*10+(arrive_time_str[i*3+1]-'0'))*base;
            base/=60;
        }
    };
};

class table{
    public:
    int available_time=8*3600,index,vip=0;
    table(int i):index(i){};
};

bool operator < (table t1,table t2){
    return t1.available_time<t2.available_time;
}

bool operator > (table t1,table t2){
    return t1.available_time>t2.available_time;{
}
}


bool cmp(data d1,data d2){
    return d1.arrive_time<d2.arrive_time;
}



string f(int num){
    int num1,num2,num3;
    num1=num%60;
    num2=(num/60)%60;
    num3=(num/3600)%24;
    return to_string(num3)+":"+to_string(num2)+":"+to_string(num1);
}


int main(){
    int num_data;
    cin>>num_data;
    vector<data> database;
    for(int i=0;i<num_data;i++){
        string temp1;
        int temp2,vip;
        cin>>temp1>>temp2>>vip;
        data temp(temp1,temp2,vip);
        database.push_back(temp);
    }

    sort(database.begin(),database.end(),cmp);
    //cout<<endl<<database[1].arrive_time_str<<endl;
   int num_table_ordinary,num_table_vip;
   cin>>num_table_ordinary>>num_table_vip;
   int vip_index[num_table_vip];
   for(int i=0;i<num_table_vip;i++){
       cin>>vip_index[i];
   } 
   int count=0;
   vector<table> tables;
   for(int i=0;i<num_table_ordinary+num_table_vip;i++){
       int vip=0;
       if(i==vip_index[count]){
           count++;
           vip=1;
       }
       table temp(i);
       temp.vip=vip;
       tables.push_back(temp);
   }

    count=0;
   queue<data> que_vip,que_ordinary;
   int time_count[num_table_ordinary+num_table_vip]{0};
   for(int time=8*3600;time<=21*3600&&count<database.size();time++){
       if(database[count].arrive_time<=time){
           cout<<database[count].arrive_time_str<<" "<<count<<endl;
           if(database[count].vip==0){
               que_ordinary.push(database[count++]);
           }
           else{
               que_vip.push(database[count++]);
           }
           
       }
       if(que_ordinary.empty()&&que_vip.empty()){continue;}
       priority_queue<table,vector<table>,less<table>> vip_available,ordinary_available;
        
       for(int j=0;j<num_table_ordinary+num_table_vip;j++){
           if(tables[j].available_time>21*3600){
               continue;
           }
           if(tables[j].vip==0&& tables[j].available_time<=que_ordinary.empty()?INT32_MAX:que_ordinary.front().arrive_time){
               ordinary_available.push(j);
           }
           if(tables[j].vip==1&& tables[j].available_time<=que_vip.empty()?INT32_MAX:que_vip.front().arrive_time){
               vip_available.push(j);
           }
       }

       while(!que_vip.empty()&&!vip_available.empty()){
           cout<<que_vip.front().arrive_time_str<<" "<<f(tables[vip_available.top().index].available_time)<<" "<<max(0,tables[vip_available.top().index].available_time-que_vip.front().arrive_time)<<endl;
           
           time_count[vip_available.top().index]++;
           tables[vip_available.top().index].available_time=max(tables[vip_available.top().index].available_time,que_vip.front().arrive_time)+que_vip.front().request_time;
           que_vip.pop();
           vip_available.pop();
       }
       while (!que_vip.empty()&&!ordinary_available.empty())
       {
            cout<<que_vip.front().arrive_time_str<<" "<<f(tables[ordinary_available.top().index].available_time)<<" "<<max(0,tables[ordinary_available.top().index].available_time-que_vip.front().arrive_time)<<endl;
            time_count[ordinary_available.top().index]++;
            tables[ordinary_available.top().index].available_time=max(tables[ordinary_available.top().index].available_time,que_vip.front().arrive_time)+que_vip.front().request_time;
            que_vip.pop();
            ordinary_available.pop();
       }
       while(!que_ordinary.empty()&&!ordinary_available.empty()){
           cout<<que_ordinary.front().arrive_time_str<<" "<<f(tables[ordinary_available.top().index].available_time)<<" "<<max(0,tables[ordinary_available.top().index].available_time-que_ordinary.front().arrive_time)<<endl;
           time_count[ordinary_available.top().index]++;
           tables[ordinary_available.top().index].available_time=max(tables[ordinary_available.top().index].available_time,que_ordinary.front().arrive_time)+que_ordinary.front().request_time;
           que_ordinary.pop();
           ordinary_available.pop();
       }
       while(!que_ordinary.empty()&&!vip_available.empty()){
           cout<<que_ordinary.front().arrive_time_str<<" "<<f(tables[vip_available.top().index].available_time)<<" "<<max(0,tables[vip_available.top().index].available_time-que_ordinary.front().arrive_time)<<endl;
           time_count[vip_available.top().index]++;
           tables[vip_available.top().index].available_time=max(tables[vip_available.top().index].available_time,que_ordinary.front().arrive_time)+que_ordinary.front().request_time;
           que_ordinary.pop();
           ordinary_available.pop();
       }
   }
   for(int i=0;i<num_table_ordinary+num_table_ordinary;i++){
       if(i!=0){
           cout<<" ";
       }
       cout<<time_count[i];
   }

}