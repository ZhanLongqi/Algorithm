#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;



class gang{
    int max=INT32_MIN;
};
int main(){
    int num_data,threshold;
    cin>>num_data>>threshold;
    int count=0;
    map<string,map<string,int>> M; 

    for(int i=0;i<num_data;i++){
        string temp[2];
        int time;
        cin>>temp[0]>>temp[1]>>time;
        map<string,map<string,int>>::iterator it0,it1;
        it0=M.find(temp[0]);
        it1=M.find(temp[1]);
        if(it0==M.end()){
            map<string,int> temp_map;
            temp_map.insert(make_pair(temp[1],time));
            M.insert(make_pair( temp[0], temp_map));
        }
        else{
            map<string,int>::iterator it2=(*it0).second.find(temp[1]);
            if(it2==(*it0).second.end()){
                
            }
        }
    }
}