#include<iostream>
#include<vector>

using namespace std;

int main(){
    string target;
    getline(cin,target);
    int max=1;
    for(int i=0;i<target.size();i++){
         int dis1=1,dis2=0;
             //cout<<"new match : "<<target[i]<<endl;
         while(i-dis1>=0&&i+dis1<target.size()&&target[i-dis1]==target[i+dis1]){
             dis1++;
         }
        while(i-dis2>=0&&i+dis2+1<target.size()&&target[i-dis2]==target[i+dis2+1]){
            //cout<<"new match  "<<target[i+dis2+1];
            dis2++;
        }
        int temp;
        temp=2*dis1-1>2*dis2?(2*dis1-1):(dis2*2);
        if(temp>max){
            max=temp;
        }
    }
    cout<<max<<endl;
}