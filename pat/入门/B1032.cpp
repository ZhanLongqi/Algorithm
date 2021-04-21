#include<iostream>
#include<map>
int main(){
    int num=0;
    scanf("%d",&num);
    std::map<int,int> score;
    for(int i=0;i<num;i++){
        int temp_index,temp_score;
        scanf("%d %d",&temp_index,&temp_score);
        auto it=score.find(temp_index);
        if(it!=score.cend()){
            (*it).second=(*it).second+temp_score;
        }
        else{
            (*it).second=temp_score;
        }
    }
    auto it=score.begin();
    int max=0,max_index=0;
    while (it!=score.cend())
    {
        if((*it).second>max){
            max_index=(*it).first;
        }   
    }
    std::cout<<(*it).first;
    
}