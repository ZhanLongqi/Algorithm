#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int capacity,len_seq,num_seq;
    cin>>capacity>>len_seq>>num_seq;
    int seq[num_seq][len_seq];
    for(int i=0;i<num_seq;i++){
        for(int j=0;j<len_seq;j++){
            cin>>seq[i][j];
        }
    }    
    for(int i=0;i<num_seq;i++){
        stack<int> temp;
        int need=1;
        for(int j=1;j<=len_seq;j++){
            //cout<<"Adding "<<j<<endl;
            temp.push(j);
            if(temp.size()==capacity+1){
                break;
            }
            while(!temp.empty()&&temp.top()==seq[i][need-1]){
                //cout<<"poping "<<temp.top()<<endl;
                temp.pop();
                need++;
            }
        }
        
        cout<<(temp.empty()?"YES":"NO")<<"\n";
    }
}