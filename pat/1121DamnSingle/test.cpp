#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int main(){
    int num_couple,num_guest;
    cin>>num_couple;
    map<string,string> m;
    for(int i=0;i<num_couple;i++){
        string couple[2];
        cin>>couple[0]>>couple[1];
        m.insert(make_pair(couple[0],couple[1]));
        m.insert(make_pair(couple[1],couple[0]));
    }
    set<string> party;
    cin>>num_guest;
    for(int i=0;i<num_guest;i++){
        string guest;
        cin>>guest;
        map<string,string>::iterator gf=m.find(guest);
        if(gf==m.end()){
            party.insert(guest);
            continue;
        }
        set<string>::iterator it=party.find((*gf).second);
        if(it==party.end()){
            party.insert(guest);
        }
        else{
            party.erase((*gf).second);
        }
        
    } 
    printf("%d\n",party.size());
    set<string>::iterator it=party.begin();
    while(it!=party.end()){
        if(it!=party.begin())cout<<" ";
        printf("%s",(*it).c_str());
        it++;
    }
}