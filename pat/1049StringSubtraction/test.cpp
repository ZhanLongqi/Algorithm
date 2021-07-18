#include<iostream>
#include<map>
using namespace std;

int main(){
    string origin,subtract;
    getline(cin,origin);
    cin>>subtract;
    int flag[300]{0};
    for(int i=0;i<subtract.size();i++){
        flag[subtract[i]]=1;
    }
    string res="";
    for(size_t i=0;i<origin.size();i++){
        if(flag[origin[i]]==0){
            //cout<<origin.substr(i,i+1)<<endl;
            res.insert(res.end(),origin[i]);
        }
    }
    std::cout<<res;
}