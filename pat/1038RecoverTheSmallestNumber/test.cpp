#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string s1,string s2){
    if(s1==s2){
        return true;
    }
    int index=0;
    while(index<min(s1.length(),s2.length())){
        if(s1[index]!=s2[index]){
            return s1<s2;
        }
        index++;
    }
    if(s1.length()<s2.length()){
        return cmp(s1,s2.substr(s1.length()));
    }
    else{
        return cmp(s1.substr(s2.length()),s2);
    }

}
bool cmp2(string s1,string s2){
    //cout<<"cmp : "<<s1<<"   "<<s2<<endl;
    int max_len=max(s1.length(),s2.length());
    for(int i=0;i<max_len;i++){
        if(s1[i%s1.length()]!=s2[i%s2.length()]){
            return s1[i%s1.length()]<s2[i%s2.length()];
        }
    }
    return true;
}

int main(){
    string temp;
    int num_data;
    cin>>num_data;
    vector<string> data(num_data);
    for(int i=0;i<num_data;i++){
        cin>>data[i];
    }
    sort(data.begin(),data.end(),cmp2);
    string result="";
    for(int i=0;i<num_data;i++){
        cout<<data[i]<<endl;
        result=result+data[i];
    }
    int index=0;
    while(result[index]=='0'){
        index++;
    }
    result=result.substr(index);
    if(result.length()!=0)
    cout<<result;
    else{
        cout<<"0";
    }
}