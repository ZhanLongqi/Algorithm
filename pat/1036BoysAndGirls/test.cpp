#include<iostream>
#include<vector>
using namespace std;

class data{
    public:
    string name;
    int gender=0,grade;
    data(string name,int grade):name(name),grade(grade){};
};


int main(){
    int num_data;
    cin>>num_data;
    vector<data> data_set_male,data_set_female;
    int max=-1,min=INT32_MAX,max_index=-1,min_index=-1;
    string name_male="Absent",ID_male="Absent",name_female="Absent",ID_female="Absent";
    string temp_name,temp_gender,temp_ID;
    for(int i=0;i<num_data;i++){
        int temp_grade;
        cin>>temp_name>>temp_gender>>temp_ID>>temp_grade;
        if(temp_gender=="M"&&temp_grade<min){
            name_male=temp_name;
            ID_male=temp_ID;
            min=temp_grade;
        }
        else if(temp_gender=="F"&&temp_grade>max){
            name_female=temp_name;
            ID_female=temp_ID;
            max=temp_grade;
        }
    }
    if(name_female=="Absent"){
        cout<<name_female<<endl;
    }
    else{
        cout<<name_female<<" "<<ID_female<<endl;
    };

    if(name_male=="Absent"){
        cout<<name_male<<endl;
    }
    else{
        cout<<name_male<<" "<<ID_male<<endl;
    }
    if(name_male=="Absent"||name_female=="Absent"){
        cout<<"NA"<<endl;
    }
    else{
        cout<<max-min<<endl;
    }
    
}