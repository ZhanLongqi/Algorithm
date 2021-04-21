#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class data{
    public:
    string rigisteratio_num;
    int score,location_num,localRank;
    data(string t1,int t2,int t3):rigisteratio_num(t1),location_num(t2),score(t3){};
};

bool cmp(data d1,data d2){
    return d1.score>d2.score;
}

int main(){
    int num_location,count=0;
    cin>>num_location;
    vector<data> database;
    for(int i=0;i<num_location;i++){

        int temp_num_data;
        cin>>temp_num_data;

        for(int j=0;j<temp_num_data;j++){
            string t1;
            int t2;
            cin>>t1>>t2;
            data temp_data(t1,i,t2);
            database.push_back(temp_data);
        }
        sort(database.begin()+count,database.begin()+count+temp_num_data,cmp);
        int last_score=-1,lastRank=1;
        for(int j=0;j<temp_num_data;j++){
            if(last_score==database[j+count].score){
                database[j+count].localRank=lastRank;
            }
            else{
                database[j+count].localRank=j+1;
            }
            last_score=database[j+count].score;
            lastRank=database[j+count].localRank;
        }
        count+=temp_num_data;
    }
    cout<<count<<endl;
    sort(database.begin(),database.end(),cmp);
    int final_rank=1,last_rank=1,last_score=-1;
    for(int i=0;i<count;i++){
        if(database[i].score==last_score){
            final_rank=last_rank;
        }
        else{
            final_rank=i+1;
        }
        cout<<database[i].rigisteratio_num<<" "<<final_rank<<" "<<database[i].location_num+1<<" "<<database[i].localRank<<endl;
        last_rank=final_rank;
        last_score=database[i].score;
    }
    
}