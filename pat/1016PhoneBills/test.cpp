#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int toll[24],num;
class record{
    public:
    string name;
    string time;
    string flag;
    record(string n,string t,string f):name(n),time(t),flag(f){};
    record(){};
};

class data{
    public:
    string name;
    string start_time;
    string end_time;
    data(string n,string s,string e):name(n),start_time(s),end_time(e){};
    data(){};
};

bool comp(const record &r1,const record &r2){
    int i=0;
    for(int i=3;i<11;i++){
        if(r1.time[i]!=r2.time[i]){
            return r1.time[i]<r2.time[i];
        }
    }
    return true;
}

pair<int,float> calculate(data bill){
    string start=bill.start_time,end=bill.end_time;
    int dd1,hh1,mm1,dd2,hh2,mm2;
    dd2=(end[3]-'0')*10+(end[4]-'0');
    hh2=(end[6]-'0')*10+(end[7]-'0');
    mm2=(end[9]-'0')*10+(end[10]-'0');
    dd1=(start[3]-'0')*10+(start[4]-'0');
    hh1=(start[6]-'0')*10+(start[7]-'0');
    mm1=(start[9]-'0')*10+(start[10]-'0');
    int borrow=0;
    int count=0;
    if(mm2<mm1){
        count+=mm2+60-mm1;
        borrow=1;
    }
    else{
        count+=mm2-mm1;
    }
    if((hh2-borrow)<hh1){
        count+=(hh2-borrow+24-hh1)*60;
        borrow=1;
    }
    else{
        count+=(hh2-borrow-hh1)*60;
        borrow=0;
    }
    count+=(dd2-borrow-dd1)*24*60;
    int newD=dd1,newH=hh1,newM=mm1;
    int money=0;
    if(hh1!=hh2||dd1!=dd2){
    money+=(60-mm1)*toll[hh1];
    dd1+=(hh1+1)/24;
    hh1=(hh1+1)%24;
    mm1=0;
    //cout<<dd1<<" "<<dd2<<"  "<<hh1<<"  "<<hh2;
    while(hh1!=hh2||dd1!=dd2){
        money+=60*toll[hh1];
        dd1+=(hh1+1)/24;
        hh1=(hh1+1)%24;
    }
    money+=(mm2)*toll[hh2];}
    else{
        money+=(mm2-mm2)*toll[hh2];
    }
    float temp=money/100.f;
    return {count,temp};
}

int main(){

    for(int i=0;i<24;i++){
        cin>>toll[i];
    }
    cin>>num;
    bool flag;
    vector<record> records ;
    map<string ,vector<data>> bill;
    for(int i=0;i<num;i++){
        string name,time,flag;
        cin>>name>>time>>flag;
        record temp(name,time,flag);
        records.push_back(temp);
    }
    sort(records.begin(),records.end(),comp);

    for(int i=0;i<records.size()-1;i++){
        if(records[i].flag!="on-line"){
            continue;
        }
        for(int j=i+1;j<records.size();j++){
            if(records[j].name==records[i].name&&records[j].flag=="on-line"&&records[j].flag!="off-line"&&records[j].time!=records[i].time){
                break;
            }
            if(records[j].name==records[i].name){
                records[j].flag="visited";
                data newData(records[i].name,records[i].time,records[j].time);
                if(bill.find(records[i].name)==bill.cend()){
                    vector<data> temp_data_vector;
                    temp_data_vector.push_back(newData);
                    bill[records[i].name]=temp_data_vector;
                    break;
                }
                else{
                    bill[records[i].name].push_back(newData);
                }
            }
        }
        
    }

    auto it=bill.cbegin();
    sort(bill.cbegin(),bill.cend());
    while(it!=bill.cend()){
        if(it!=bill.cbegin())cout<<endl;
        cout<<it->first<<" "<<it->second[0].start_time.substr(0,2);
        float count=0.f;
        for(int i=0;i<it->second.size();i++){
            pair<int,float> temp;
            temp=calculate(bill[it->first][i]);
            cout<<endl<<it->second[i].start_time.substr(3)<<" "<<it->second[i].end_time.substr(3)<<" "; 
            printf("%d $%.2f",temp.first,temp.second);
            count+=temp.second;
        }
            printf("\nTotal amount: $%.2f",count);
        it++;
    }
}