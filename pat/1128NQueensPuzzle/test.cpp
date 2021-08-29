#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int num_config;
    cin>>num_config;

    vector<bool> res(num_config);
    for(int m=0;m<num_config;m++){
        int num_col;
        cin>>num_col;
        bool r=true;
        set<int> row,a,b;
        for(int i=1;i<=num_col;i++){
            int k;
            cin>>k;
            set<int>::iterator i0=row.find(k),i1=a.find(k-i),i2=b.find(k+i);
            if(i0==row.end()&&i1==a.end()&&i2==b.end()){
                row.insert(k);
                a.insert(k-i);
                b.insert(k+i);
            }
            else{
                r=false;
            }
        }
        res[m]=r;
    }
    for(int i=0;i<num_config;i++){
        if(res[i]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}