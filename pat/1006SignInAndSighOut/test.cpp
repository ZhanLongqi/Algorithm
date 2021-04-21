#include<iostream>
#include<vector>
class data{
    public:
    std::string index;
    std::string begin_time,end_time;
    data(){};
    data(std::string i,std::string b,std::string e):index(i),begin_time(b),end_time(e){};
};
int main(){
    int num;
    scanf("%d",&num);
    std::vector<data> datas;
    for(int i=0;i<num;i++){
        std::string index,begin,end;
        std::cin>>index>>begin>>end;
        data temp(index,begin,end);
        datas.push_back(temp);
    }
    int min_index=0,max_index=0;
    for(int i=1;i<datas.size();i++){
        if(datas[i].begin_time<datas[min_index].begin_time){
            min_index=i;
        }
        if(datas[i].end_time>datas[max_index].end_time){
            max_index=i;
        }
    }
    std::cout<<datas[min_index].index<<" "<<datas[max_index].index;
}