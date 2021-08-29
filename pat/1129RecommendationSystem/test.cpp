#include<iostream>
#include<set>
#include<vector>
#include<math.h>
#define maxn 50001
using namespace std;

int m[maxn]{0};

struct node{
    int val,cnt;
    node(int val,int cnt):val(val),cnt(cnt){};
    bool operator < (const node &n) const {
        return cnt==n.cnt?val<n.val:cnt>n.cnt;
    }
};

int main(){
    int num_query,max_size;
    cin>>num_query>>max_size;
    vector<int> res;
    set<node> nodes;
        for(int j=0;j<num_query;j++){
            int visit;
            cin>>visit;
        if(j!=0){
            printf("%d ",visit);
            int tmp_cnt=0;
            for(auto it=nodes.begin();it!=nodes.end()&&tmp_cnt<max_size;it++,tmp_cnt++)printf(" %d",it->val);
            printf("\n");
        }
            auto it=nodes.find(node(visit,m[visit]));
            if(it!=nodes.end())nodes.erase(node(visit,m[visit]));
            m[visit]++;
            nodes.insert(node(visit,m[visit]));
        }

}