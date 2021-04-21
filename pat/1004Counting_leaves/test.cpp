#include<iostream>
#include<vector>
#include<queue>
#include<map>
class data{
    public:
    int node_index;
    int num_leaves;
    std::vector<int> children;
    data();
    data(bool b){
        scanf("%d %d",&node_index,&num_leaves);
        for(int i=0;i<num_leaves;i++){
            int temp;
            scanf("%d",&temp);
            children.push_back(temp);
        }
    }
};
int main(){
    int N,M;
    std::vector<int> ans;
    scanf("%d %d",&N,&M);
    if(M<=0){
        printf("1");
        return 0;
    }
    //std::vector<data> datas;
    std::map<int,data> datas;
    for(int i=0;i<M;i++){
        data temp(true);
        datas.insert({temp.node_index,temp});
        //datas[temp.node_index]=temp;
    }
    std::queue<int> que;
    que.push(1);
    int count=1,next_count=0,none_leaf_num=0;
    while(!que.empty()){
    printf("next stair\n");
        while (count)
        {
            int temp=que.front();
            que.pop();
            if(datas.find(temp)==datas.cend()){
                none_leaf_num++;
            }
            else{
                data t=datas.find(temp)->second;//datas[temp];
                for(int i=0;i<t.num_leaves;i++){
                    que.push(t.children[i]);
                }
                next_count+=t.num_leaves;
            }
            count--;
        }
        count=next_count;
        next_count=0;
        ans.push_back(none_leaf_num);
        none_leaf_num=0;
    }
    for(int i=0;i<ans.size();i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
}
