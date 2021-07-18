#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

vector<string> int2str;
bool cmp(pair<int,vector<int>> c0,pair<int,vector<int>> c1 ){
    return int2str[c0.first]<int2str[c1.first];
}

int main(){
    int num_students,num_courses;
    cin>>num_students>>num_courses;
    vector<vector<int>> MAP(num_courses);
    vector<pair<int,vector<int>>> data;
    for(int i=0;i<num_students;i++){
        string name;
        int num_registered;
        cin>>name>>num_registered;
        int2str.push_back(name);
        //int2str[i]=name;
        vector<int> temp_vec;
        for(int j=0;j<num_registered;j++){
            int course_id;
            cin>>course_id;
            temp_vec.push_back(course_id);
        }
        data.push_back(make_pair(i,temp_vec));
    }
    sort(data.begin(),data.end());
    for(int i=0;i<num_students;i++){
        for(int j=0;j<data[i].second.size();j++){
            MAP[data[i].second[j]-1].push_back(data[i].first);
        }
    }
    for(int i=1;i<=num_courses;i++){
        cout<<i<<" "<<MAP[i-1].size()<<endl;
        for(int j=0;j<MAP[i-1].size();j++){
            cout<<int2str[MAP[i-1][j]]<<endl;
        }
    }
}