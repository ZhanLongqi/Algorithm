#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int num_queries,num_courses;
    cin>>num_queries>>num_courses;
    vector<vector<string>> courses(num_courses);
    map<string,set<int>> MAP;
    for(int i=0;i<num_courses;i++){
        int num_student,index;
        cin>>index>>num_student;

        for(int j=0;j<num_student;j++){
            string temp_name;
            cin>>temp_name;
            if(MAP.find(temp_name)==MAP.end()){
                /*vector<int> temp_vec(num_courses+1);
                fill(temp_vec.begin(),temp_vec.end(),0);
                MAP[temp_name]=temp_vec;*/
                set<int> temp_vec;
                MAP[temp_name]=temp_vec;
            }
            /*vector<int> *pointer=&MAP[temp_name];
            (*pointer)[index]=1;
            (*pointer)[0]+=1;*/
            MAP[temp_name].insert(index);
        }
        
    }
    vector<string> queries(num_queries);
    for(int i=0;i<num_queries;i++){
        cin>>queries[i];
    }
    for(int i=0;i<num_queries;i++){
        cout<<queries[i];
        if(MAP.find(queries[i])==MAP.end()){
            cout<<" 0"<<endl;
            continue;
        }
        set<int> target=MAP[queries[i]];
        //sort(target.begin(),target.end());
        //cout<<" "<<target[0];
        cout<<" "<<target.size();
        /*for(int j=0;j<=num_courses;j++){
            if(target[j]==1){
                cout<<" "<<j;
            }
        }*/
        set<int>::iterator it=target.begin();
        while(it!=target.end()){
            cout<<" "<<(*it);
            it++;
        }
        cout<<endl;
    }
}