#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v1={1,2,3};
    if(1==1){
        vector<int> v2{3,2,1};
        v1=v2;
    }
    cout<<v1[2];
}