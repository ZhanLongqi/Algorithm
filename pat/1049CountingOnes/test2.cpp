#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int f(int num){
    int copy=num;
    int sum=0;
    vector<int> digit;
    
    while (num!=0)
    {
        digit.push_back(num%10);
        num/=10;
    }
    for(int i=0;i<digit.size()-1;i++){
        //cout<<temp_sum<<"\n";
        int temp_sum=0;
        if(digit[i]!=0){
            temp_sum=copy%int(pow(10.0,double(i)));
            temp_sum+=copy/int(pow(10.0,double(i+1)))*int(pow(10.0,double(i)));
            temp_sum+=1;
            //continue;
        }
        else{
            temp_sum+=(copy/int(pow(10.0,double(i+1))))*int(pow(10.0,double(i)));
        }
        sum+=temp_sum;
    }
    if(digit[digit.size()-1]==1){
        sum+=copy%int(pow(10.0,double(digit.size()-1)))+1;
    }
    else{
        sum+=pow(10.0,double(digit.size()-1));
    }
    //cout<<sum<<"\n";
    return sum;
}

int main(){
    int last=0;
    for(int i=1;i<=300;i++){
        int curr=f(i);
        if(curr-last<0)
        cout<<"i: "<<i<<" diff: "<<curr-last<<" curr:"<<curr<<"\n";
        last=curr;   
    }   
}