#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int num_data;
    cin>>num_data;
    vector<int> data(num_data);
    map<int,int> line;
    for(int i=0;i<num_data;i++){
        cin>>data[i];
        line[data[i]]=i;
    }
    int min_index=INT32_MAX,result=0;
    sort(data.begin(),data.end());
    for(int i=0;i<num_data;i++){
        bool unique=true;
        while(data[i+1]==data[i]){
            unique=false;
            i++;
        }
        if(unique){
            if(line[data[i]]<min_index){
                min_index=line[data[i]];
                result=data[i];
            }
        }
    }
    if(min_index==INT32_MAX){
        cout<<"None"<<endl;
    }
    else{
        cout<<result;
    }
}