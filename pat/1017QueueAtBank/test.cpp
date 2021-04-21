#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int comp(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    int num_customers,num_windows;
    cin>>num_customers>>num_windows;
    vector<pair<int,int>> data;
    vector<int> windows;
    for(int i=0;i<num_windows;i++){
        windows.push_back(0);
    }
    for(int i=0;i<num_customers;i++){
        int hh,mm,ss,request_time,temp=0;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&request_time);
        temp+=hh*60*60+mm*60+ss-8*60*60;
        if(temp<=9*60*60){
            data.push_back({temp,request_time*60});
        }
    }
    if(data.size()<=0){
        printf("0.0");
        return 0;
    }
    sort(data.begin(),data.end(),comp);
    //cout<<data.size();
    float count=0.f;
    for(int i=0;i<data.size();i++){
        int min_index=0,min=INT32_MAX;
        for(int j=0;j<num_windows;j++){
            if(windows[j]<min){
                min=windows[j];
                min_index=j;
            }
        }
            count+=std::max(0,windows[min_index]-data[i].first);
            //cout<<windows[min_index]<<"  "<<data[i].first<<"  "<<min_index<<endl;
            windows[min_index]=max(windows[min_index],data[i].first)+data[i].second;
    }
    printf("%.1f",count/60/data.size());
    
}