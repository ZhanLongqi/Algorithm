#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long reverse(int num,int radix){
    vector<int> nums;
    long long result=0;
    if(num==0){
        return 0;
    }
    while (num!=0)
    {
        nums.push_back(num%radix);
        num/=radix;
    }
    for(int i=0;i<nums.size();i++){
        result+=nums[i]*pow(radix,nums.size()-i-1);
    }
    return result;
}

bool isPrime(int num){
    if(num<=1){
        return false;
    }
    if(num==2||num==3)
        return true;
    for(int i=2;i<num/2;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
    
}

int main(){
    vector<pair<int,int>> data;
    int num,radix;
    cin>>num;
    while (num>0)
    {
        cin>>radix;
        data.push_back({num,radix});
        cin>>num;
    }
    for(int i=0;i<data.size();i++){
        if(i!=0)cout<<endl;
        bool b=isPrime(data[i].first)&&isPrime(reverse(data[i].first,data[i].second));
        cout<<(b?"Yes":"No");
    }
    
}