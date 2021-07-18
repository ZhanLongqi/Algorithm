#include<iostream>
#include<vector>
using namespace std;

void backtrack(int curr_pointer,vector<int> vec,int stripe[],int &max_len,int preference[],int preference_pointer);
int main(){
    int total_color,num_preference,len_stripe;
    cin>>total_color>>num_preference;
    int preference[num_preference+1];
    preference[0]=num_preference+1;
    for(int i=0;i<num_preference;i++){
        cin>>preference[i+1];
    }
    cin>>len_stripe;
    int stripe[len_stripe+1];
    stripe[0]=len_stripe+1;
    for(int i=0;i<len_stripe;i++){
        cin>>stripe[i+1];
    }
    vector<int> temp;
    int max_len=0;
    backtrack(1,temp,stripe,max_len,preference,1);
    cout<<max_len;
}
void backtrack(int curr_pointer,vector<int> vec,int stripe[],int &max_len,int preference[],int preference_pointer){
    cout<<"tracking "<<curr_pointer<< "  : "<<preference_pointer<<endl;
    if(curr_pointer>=stripe[0]||preference_pointer>preference[0]){
        if(vec.size()>max_len){
            max_len=vec.size();
            cout<<"max: "<<max_len<<endl;
        }
        return;
    }
    if(stripe[curr_pointer]==preference[preference_pointer]){
        int count=0;
        while(stripe[curr_pointer+count]==preference[preference_pointer]){
            count++;
            vec.push_back(stripe[curr_pointer]);
        }
        backtrack(curr_pointer+1,vec,stripe,max_len,preference,preference_pointer);
        for(int k=0;k<count;k++){ 
            vec.pop_back();
        }
    }
    else{
        int count=0;
        while(stripe[curr_pointer]!=preference[preference_pointer+count]){
            count++;
        }
        backtrack(curr_pointer,vec,stripe,max_len,preference,preference_pointer+count); 


        backtrack(curr_pointer+1,vec,stripe,max_len,preference,preference_pointer);
    }
}