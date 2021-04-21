#include<iostream>
#include<math.h>
using namespace std;
int convert2digit(char c){
    if(c>'9'){
        return c-'a'+10;
    }
    else 
        return c-'0';
}
long long convert(string str,long long radix){
    long long result=0;
    for(int i=0;i<str.size();i++){
        int temp=convert2digit(str[i]);
        result+=temp*pow(radix,str.size()-i-1);
    }
    return result;
}
int getMinRadix(string str){
    char max=str[0];
    for(int i=0;i<str.size();i++){
        if(str[i]>max){
            max=str[i];
        }
    }
    return convert2digit(max)+1;
}

int main(){
    string target,num;
    int flag;
    long long radix;
    cin>>target>>num>>flag>>radix;
    if(flag==2){
        string temp=target;
        target=num;
        num=temp;
    }
    long long target_digit=convert(target,radix);
    long long low=getMinRadix(num);
    long long high=max(low,target_digit+1);
    long long mid=(high+low)/2;
    while(low<high){
        mid=(high+low)/2;
        long long temp_res=convert(num,mid);
        if(temp_res<target_digit){
            low=mid+1;
        }
        else {
            high=mid;
        }
        
        cout<<"low "<<low<<"  high  "<<high<<endl;
        cout<<"temp result : "<<mid<<"   " <<temp_res<<endl;
    }
    if(convert(num,high)==target_digit){
        while(convert(num,high-1)==target_digit){
            high--;
        }
        cout<<high;
    }
    else
    cout<<"Impossible";
    return 0;
}