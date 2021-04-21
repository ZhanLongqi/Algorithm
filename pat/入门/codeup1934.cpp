#include<iostream>

int main(){
    int num;
    scanf("%d",&num);
    int data[num];
    for(int i=0;i<num;i++){
        scanf("%d",&data[i]);
    }
    int left=0,right=num-1,target=0;
    scanf("%d",&target);
    while(right>=left){
        int mid=(left+right)/2;
        if(target==data[mid]){
            std::cout<<(left+right)/2;
            return 0;
        }
        else if(target<data[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    std::cout<<-1;
    return 0;
}