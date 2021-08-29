#include<iostream>
#include<vector>
#include<algorithm>
typedef long double ld;
using namespace std;

int main(){
    int num;
    cin>>num;
    vector<int> ropes(num);
    for(int i=0;i<num;i++)cin>>ropes[i];
    sort(ropes.begin(),ropes.end());
    ld len=ropes[0];
    for(int i=1;i<num;i++){
        len=len/2.f+float(ropes[i])/2.f;
    }
    printf("%d",int(len));
}