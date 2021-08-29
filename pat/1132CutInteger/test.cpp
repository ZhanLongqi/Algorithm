#include<iostream>
#include<math.h>
typedef long long ll;

using namespace std;

int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        ll n,base=10,t=10,p=1;
        scanf("%lld",&n);
        while(n/t!=0){
            t=ll(pow(base,p++));
        }
        ll high=n%(int(pow(base,p/2))),low=n/(int(pow(base,p/2)));
        if(high==0||low==0||high*low>n||n%(high*low)!=0)
            printf("No\n");
        else 
            printf("Yes\n");
    }
}