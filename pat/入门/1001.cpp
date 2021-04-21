#include<iostream>
int main(){
    int count=0;
    int num=0;
    scanf("%d",&num);
    while(num!=1){
        count++;
        if(num%2==0){
            num/=2;
        }
        else{
            num=(3*num+1)/2;
        }
    }
    std::cout<<count;
}