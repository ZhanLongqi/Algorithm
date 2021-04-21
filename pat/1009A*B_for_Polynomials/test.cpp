#include<iostream>
#include<map>
#include<vector>
class da{
    public:
    int in;
    float fl;
    da(int i ,float f):in(i),fl(f){};
};
int main(){
    int num=0;
    std::vector<da> data[2];
    for(int i=0;i<2;i++){
        std::cin>>num;
        for(int j=0;j<num;j++){
            int exp;
            float coff;
            std::cin>>exp;
            std::cin>>coff;
            da temp(exp,coff);
            data[i].push_back(temp);
        }
    }
    std::map<int,float> ans;
    for(int i=0;i<data[0].size();i++){
        for(int j=0;j<data[1].size();j++){
            if(ans.find(data[0][i].in+data[1][j].in)==ans.cend())
                ans[data[0][i].in+data[1][j].in]=0;
            ans[data[0][i].in+data[1][j].in]+=data[0][i].fl*data[1][j].fl;
            
        }
    }
    auto it=ans.rbegin();
    std::vector<std::pair<int,float>> vec;
    while(it!=ans.rend()){
        if(it->second!=0){
            vec.push_back(std::make_pair(it->first,it->second));
        }
       //     temp.push_back({it->first,it->second});
       // printf(" %d %.1f",it->first,it->second);
        it++;
    }
    printf("%d",vec.size());
    for(int i=0;i<vec.size();i++){
        printf(" %d %.1f",vec[i].first,vec[i].second);
    }
      
}