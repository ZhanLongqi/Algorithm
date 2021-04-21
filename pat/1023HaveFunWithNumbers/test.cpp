#include<iostream>
#include<vector>
#include<string>
using namespace std;

string dou(string s){
    int curr=0,pass=0;
    string result="";
    for(int i=s.size()-1;i>=0;i--){
        curr=(s[i]-'0')*2+pass;
        pass=curr/10;
        curr=curr%10;
        string temp(1,curr+'0');
        result=temp+result;
    }
    if(pass!=0){
        string temp(1,pass+'0');
        result=temp+result;
    }
    return result;
};

int main(){
    int count[10]{0};
    string num,num2;
    cin>>num;
    num2=dou(num);
    for(int i=0;i<num.size();i++){
        count[num[i]-'0']++;
    }
    for(int i=0;i<num2.size();i++){
        if(count[num2[i]-'0']<=0){
            cout<<"No"<<endl<<num2;
            return 0;
        }
        else{
            count[num2[i]-'0']--;
        }
    }
    cout<<"Yes"<<endl<<num2;
    return 0;
}