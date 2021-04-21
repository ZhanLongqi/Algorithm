#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
class record{
    public:
        string name,time,stat;
        int time_digit=0;
        record(string n,string t,string s):name(n),time(t),stat(s){
            time_digit=stoi(time.substr(3,5))*(24*60)+stoi(time.substr(6,8))*60+stoi(time.substr(9,11));
            //time_digit=stoi(time.substr(3,5))*(24*60);
            
        }
};

bool cmp(record a,record b){
    if(a.name!=b.name){
        return a.name<b.name;
    }
    else{
        return a.time_digit<b.time_digit;
    }
}

float cost(int time1,int time2,int charge[24]){
    float result=0;
    time1=time1%(1440);
    time2=time2%(1440);
    for(int i=time1/60;i<=time2/60;i++){
        //cout<<endl<<min(time2,i+1)<<" "<<max(time1,i)<<endl;
        result+=(min(time2,(i+1)*60)-max(time1,i*60))*charge[i];
    }
    return result;

}

float cost1(int time1,int time2,int charge[24]){
    float result=0;
    while(time1<time2){
        if(time1%60==0&&time1+60<=time2){
            result+=charge[time1%(1440)/60]*60;
            time1+=60;
            continue;
        }
        result+=charge[time1%(1440)/60];
        time1++;
    }
    return result;
}



int main(){
    int charge[24],num_records;
    for(int i=0;i<24;i++){
        scanf("%d",&charge[i]);
    }
    scanf("%d",&num_records);
    vector<record> records;
    for(int i=0;i<num_records;i++){
        string name,time,stat;
        cin>>name>>time>>stat;
        record temp(name,time,stat);
        records.push_back(temp);
    }
    
    sort(records.begin(),records.end(),cmp);
    vector<vector<record>> sorted_records;
    for(int i=0;i<num_records;){
        vector<record> temp;
        string customer_name=records[i].name;
        while(records[i].name==customer_name){
            //cout<<records[i].name<<" "<<records[i].time<<endl;
            temp.push_back(records[i]);
            i++;
        }
        sorted_records.push_back(temp);
    }

    for(int i=0;i<sorted_records.size();i++){
        string name=sorted_records[i][0].name;
        cout<<name<<" "<<sorted_records[i][0].time.substr(0,2)<<endl;
        int count=0;
        float total=0;
        while(count<sorted_records[i].size()-1){
            if(sorted_records[i][count+1].stat=="on-line"){
                count++;
                continue;
            }
            if(count+1<sorted_records[i].size()&&sorted_records[i][count+1].stat=="off-line"){
                float co=cost1(sorted_records[i][count].time_digit,sorted_records[i][count+1].time_digit,charge);
                if(co==0){
                    continue;
                }
                cout<<sorted_records[i][count].time.substr(3)<<" "<<sorted_records[i][count+1].time.substr(3);
                cout<<" "<<sorted_records[i][count+1].time_digit-sorted_records[i][count].time_digit;
                total+=co;
                printf(" $%.2f\n",co/100);
                count++;
            }
        }
        if(total!=0)
        printf("Total amount: $%.2f\n",total/100);
        //cout<<"Total amount $"<<total<<endl;
    }
}