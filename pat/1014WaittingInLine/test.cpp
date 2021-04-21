#include<iostream>
#include<queue>
using namespace std;



int time_add(int i,int j){
    int hh,mm;
    mm=(i%100+j%60)%60;
    hh=(i/100+j/60)+(i%100+j%60)/60;
    return  hh*100+mm;
} 

std::string int2string(int time){
    string result="";
    for(int i=0;i<4;i++){
        result=char(time%10+'0')+result;
        time/=10;
    }
    result.insert(2,":");
    return result;
}

class window{
    public:
        queue<int> leave;
        int max_len;
        window(int len):max_len(len){};
        window(){};
        int add(int request_time){
            int leave_time=request_time;
            if(!leave.empty()){
                leave_time=request_time+leave.back();
            }
            leave.push(leave_time);
            if(leave.size()>max_len){
                leave.pop();
            }
            return leave_time;
        }

        int time_available(){
            if(leave.size()<max_len){
                return 0;
            }
            else{
                return leave.front();
            }
        }

        int len(){
            return leave.size();
        }
};

int main(){
    int num_windows,len_queue,num_customers,num_query;
    int request_time[num_customers];
    cin>>num_windows>>len_queue>>num_customers>>num_query;
    int query[num_query],finish_time[num_customers];
    vector<window> windows;
    for(int i=0;i<num_windows;i++){
        window temp(len_queue);
        windows.push_back(temp);
    }
    for(int i=0;i<num_customers;i++){
        cin>>request_time[i];
    }
    for(int i=0;i<num_query;i++){
        cin>>query[i];
    }
    
    for(int i=0;i<num_customers;i++){
        if(i<num_windows*len_queue){
            finish_time[i]=windows[i%num_windows].add(request_time[i]);
        }
        else{
            int min=INT32_MAX,min_index=0;
            for(int j=0;j<num_windows;j++){
                if(windows[j].time_available()<min){
                    min=windows[j].time_available();
                    min_index=j;
                }
            }
                //cout<<i<<" added to "<<windows[min_index].time_available();
            finish_time[i]=windows[min_index].add(request_time[i]);
        }
    }

    for(int i=0;i<num_query;i++){
        if(i!=0)cout<<endl;
        int result=time_add(800,finish_time[query[i]-1]);
        if(result>1700){
            cout<<"Sorry";
        }
        else{
            cout<<int2string(result);
        }
    }
}
