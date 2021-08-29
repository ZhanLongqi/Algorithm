#include<iostream>
#include<string>
typedef long long ll;
using namespace std;

string reverse(string str){
    string reverse="";
    for(int i=str.size()-1;i>=0;i--){
        reverse+=str[i];
    }
    return reverse;
}

string add(string a,string b){
    int curr=0,carry=0;
    string result="";
    for(int i=a.size()-1;i>=0;i--){
        int curr=stoi(a.substr(i,1))+stoi(b.substr(i,1))+carry;
        carry=curr/10;
        curr=curr%10;
        result=to_string(curr)+result;
    }
    if(carry>0){
        result=to_string(carry)+result;
    }
    return result;
}

bool palindrome(string s){
    if(s.size()==1)return true;
    int i=0;
    while(i<=s.size()/2){
        if(s[i]!=s[s.size()-i-1])return false;
        i++;
    }
    return true;
}

int main(){
    string num;
    cin>>num;
    int count=0;
    while(!palindrome(num)&&count<10){
        string reversed=reverse(num);
        string t=add(num,reversed);
        printf("%s + %s = %s\n",num.c_str(),reversed.c_str(),t.c_str());
        num=t;
        count++;
    }
    if(count<10)
    printf("%s is a palindromic number.",num.c_str());
    else 
    printf("Not found in 10 iterations.");
}