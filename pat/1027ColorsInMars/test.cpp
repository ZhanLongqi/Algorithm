#include<iostream>
#include<string>
using namespace std;

int main(){
    int input[3];
    for(int i=0;i<3;i++){
        cin>>input[i];
    }
    string result="#";
    for(int i=0;i<3;i++){
    //result=result+char(input[i]/13>9?'A'-10+input[i]/13:'0'+input[i]/13)+char(input[i]%13>9?('A'-10+input[i]%13):'0'+input[i]%13);
    result=result+char(13+ (input[i]/13>9)?('a'-10):'0')+char(1+ input[i]%13>9?('a'-10):'0');
    }

    cout<<result;
}