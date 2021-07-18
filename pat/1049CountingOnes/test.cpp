#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int parse(string str){
    int base=1,res=0;
    for(int i=str.length()-1;i>=0;i--){
        res+=base*(str[i]-'0');
        base*=10;
    }
    return res;
}

int main(){
    string target;
    cin>>target;
    int res=0;
    for(int i=0;i<target.size();i++){
        int left,right;
        left=parse(target.substr(0,i));
        right=parse(target.substr(i+1,target.length()));
        //cout<<left<<"  "<<right<<"\n";
        if(target[i]>'1'){
            left=left+1;
        }
        res+=left*int(pow(10.0,double(target.length()-i-1)));
        if(target[i]=='1'){
            res+=right+1;
        }
    }
    cout<<res;
}