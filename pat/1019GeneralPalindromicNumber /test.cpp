#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> parse(int target,int base){
    vector<int> data;
    if(target==0){
        data.push_back(0);
        return data;
    }
    while(target!=0){
        data.push_back(target%base);
        target=target/base;
    }
    return data;
}

int main(){
    int target,base;
    scanf("%d %d",&target,&base);
    vector<int> temp=parse(target,base);
    int left=0,right=temp.size()-1;
    while(left<right){
        if(temp[left]!=temp[right]){
            cout<<"No"<<endl;
            break;
        }
        left++;
        right--;
    }
    if(left>=right){
        cout<<"YES"<<endl;
    }
    for(int i=0;i<temp.size();i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<temp[i];
    }
    
}