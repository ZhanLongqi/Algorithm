#include<iostream>
#include<vector>

using namespace std;

string f(string target){
    string result="";
    int curr=0,pass=0;
    for(int i=target.size()-1;i>=0;i--){
        int  temp=target[i]-'0',temp2=target[target.size()-1-i]-'0';
        curr=temp+temp2+pass;
        pass=curr/10;
        curr=curr%10;
        result.insert(0,"0");
        result[0]+=curr;
    }
    if(pass!=0){
    result.insert(0,"0");
    result[0]+=pass;
    }
    return result;
}

bool check(string target){
    for(int i=0;i<target.size()/2;i++){
        if(target[i]!=target[target.size()-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    string num;
    cin>>num;
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        if(check(num)){
            cout<<num<<endl<<i;
            return 0;
        }
        else{
            num=f(num);
        }
        
    }
    cout<<num<<endl<<time;
    return 0;
}