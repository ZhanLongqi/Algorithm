#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int num_coins,target;
    cin>>num_coins>>target;
    int coins[num_coins];
    for(int i=0;i<num_coins;i++){
        cin>>coins[i];
    }
    sort(&coins[0],&coins[num_coins]);
    int left=0,right=num_coins-1;
    while(left<right){
        int temp_res=coins[left]+coins[right];
        if(temp_res==target){
            cout<<coins[left]<<" "<<coins[right];
            return 0;
        }
        else if(temp_res>target){
            right--;
        }
        else{
            left++;
        }
    }
    cout<<"No Solution";
}