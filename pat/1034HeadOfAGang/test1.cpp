#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool visited[1000]{false};
vector<int> sum;
vector<map<int,int>> data;
void DFS(int curr,int &head,int &total,int &num_member);
int cmp(pair<int,int> p1,pair<int,int> p2);
    map<string,int> str2num;
    map<int,string> num2str;
int main(){
    int num_data,threshold;
    cin>>num_data>>threshold;
    //int data[1000][1000]{0};
    int count=0;
    for(int i=0;i<num_data;i++){
        string n1,n2;
        int time;
        cin>>n1>>n2>>time;
        if(str2num.find(n1)==str2num.end()){
            num2str[count]=n1;
            str2num[n1]=count++;
            map<int,int> temp_vec;
            data.push_back(temp_vec);
        }
        if(str2num.find(n2)==str2num.end()){
            num2str[count]=n2;
            str2num[n2]=count++;
            map<int,int> temp_vec;
            data.push_back(temp_vec);
        }
        data[str2num[n1]][str2num[n2]]+=time;
        data[str2num[n2]][str2num[n1]]+=time;
    }
    for(int i=0;i<data.size();i++){
        map<int,int>::iterator it=data[i].begin();
        sum.push_back(0);
        while(it!=data[i].end()){
       //     cout<<num2str[(*it).first]<<":"<<(*it).second<<"      ";
       sum[i]+=(*it).second;
            it++;
        }
        sum[i]/=2;
        //cout<<endl;
    }
    vector<pair<int,int>> result;
    for(int i=0;i<data.size();i++){
        int head=i,total=0,num_member=0;
        if(!visited[i]){ 
        DFS(i,head,total,num_member);
        if(total>threshold&&num_member>2){
            result.push_back(make_pair(head,num_member));
        }
        }
    }
    sort(result.begin(),result.end(),cmp);
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<num2str[result[i].first]<<" "<<result[i].second<<endl;
    }
}

void DFS(int curr,int &head,int &total,int &num_member){
    //cout<<"DFS : "<<curr<<"  num_member: "<<num_member<<endl;;
    visited[curr]=true;
    if(sum[curr]>sum[head]){
        head=curr;
    }
    num_member++;
    total+=sum[curr];
    map<int,int>::iterator it=data[curr].begin();
    while(it!=data[curr].end()){
        if(!visited[(*it).first]){
            DFS((*it).first,head,total,num_member);
        }
        it++;
    }
}

int cmp(pair<int,int> p1,pair<int,int> p2){
    return num2str[p1.first]<num2str[p2.first];
}