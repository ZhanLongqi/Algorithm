#include<iostream>
#include<map>
#include<vector>
int main(){
    int len;
    std::map<int,float> maps;
    for(int i=0;i<2;i++){
        std::cin>>len;
        for(int j=0;j<len;j++){
            int exp,coff;
            std::cin>>exp;
            std::cin>>coff;
            maps[exp]+=coff;
        }
    }
    std::vector< std::pair<int,float> > res;
    for(std::map<int,float>::reverse_iterator it=maps.rbegin();it!=maps.rend();it++){
        if(it->second!=0){
            res.push_back({it->first,it->second});
        }
    }
    printf("%d",res.size());
    for(int i=0;i<res.size();i++)
        {
            printf(" %d %.1f",res[i].first,res[i].second);
        }
}