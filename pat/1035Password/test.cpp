#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int num_data;
    cin>>num_data;
    map<string,string> dic;
    dic["1"]="@";
    dic["0"]="%";
    dic["l"]="L";
    dic["O"]="o";
    vector<pair<string,string>> accounts;
    int num_changed=0;
    for(int i=0;i<num_data;i++){
        string name,password;
        cin>>name>>password;
        map<string,string>::iterator it=dic.begin();
        bool changed=false;
        while(it!=dic.end()){
            string target=""+(*it).first;
            size_t last=0;
            while((last=password.find_first_of(target,last))!=-1){
                //cout<<"key: "<<target<<endl;
                changed=true;
                password.replace(password.begin()+last,password.begin()+last+1,(*it).second);
            }
            it++;
        }
        if(changed){
            num_changed++;
        accounts.push_back(make_pair(name,password));
        }
    }
    if(accounts.size()==0){
        if(num_data==1){
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else {
            cout<<"There is "<<num_data<<" account and no account is modified"<<endl;
        }
        return 0;
    }
    cout<<num_changed<<endl;
    for(int i=0;i<accounts.size();i++){
        cout<<accounts[i].first<<" "<<accounts[i].second<<endl;
    }
}