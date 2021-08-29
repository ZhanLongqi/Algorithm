#include<iostream>
#include<string>
#include<set>
#define maxn 100
using namespace std;

int main(){
    int num;
    cin>>num;
    set<int> res;
    string str;
    int temp_sum=0;
    for(int i=0;i<num;i++){
        temp_sum=0;
        cin>>str;
        for(int i=0;i<str.size();i++){
            temp_sum+=stoi(str.substr(i,1));
        }
        res.insert(temp_sum);
    } 
    printf("%d\n",res.size());
    set<int>::iterator it=res.begin();
    while(it!=res.end()){
        if(it!=res.begin())printf(" ");
        printf("%d",(*it));
        it++;
    }
}