#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int toll[24];

class request{
    public:
    string name;
    int time;
    string on_off="";
    request(string n,int t,string o):name(n),time(t),on_off(o){};
};

bool comp(request r1,request r2){
    if(r1.name!=r2.name){
        return r1.name>r2.name;
    }
    else{
        return r1.time>r2.time;
    }
}

int main(){
    for(int i=0;i<24;i++){
        cin>>toll[i];
    }
    int num=0;
    cin>>num;
    vector<request> requests;    
    while (num--)
    {
        //cout<<num<<endl;
        char* name,*on_off;
        int  time=0,mon,dd,hh,mm;
        scanf("%s",name);
        scanf("%0d:%0d:%0d:%0d",&mon,&dd,&hh,&mm);
        scanf("%s",on_off);
        time=mon*30*24*60+dd*24*60+hh*60+mm;
        string name_str(name);
        string on_off_str(on_off);
        request temp(name_str,time,on_off_str);
        requests.push_back(temp);
    }
    sort(requests.begin(),requests.end(),comp);
    //for(int i=0;i<requests.size();i++){
      //  cout<<requests[i].name<<"  "<<requests[i].time<<" "<<requests[i].on_off <<endl;
    //}
    for(int index=0;index<requests.size();index++){
        string temp_name=requests[index].name;
        if(index!=0)cout<<endl;
        cout<<temp_name<<" "<<requests[index].time%(30*24*60)<<endl;
        int count=0;
        while(index+1<requests.size()&&requests[index+1].name==temp_name){
            if(requests[index+1].on_off=="off_line"){
                cout<<requests[index].time<<" "<<requests[index+1].time<<" "<<requests[index+1].time-requests[index].time;
            }
            index++;
        }
    }
        
    }
