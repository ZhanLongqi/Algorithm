#include<iostream>
#include<vector>
int main(){
    int num;
    scanf("%d",&num);
    int data[num];
    for(int i=0;i<num;i++){
        scanf("%d",&data[i]);
    }
    int left[num]{0};
    int left_sum[num]{0};
    int max_sum=data[0],max_index=0;
    for(int i=0;i<num;i++){
        if(i==0){
            left[i]=0;
            left_sum[0]=data[0];
            continue;
        }
        if(left_sum[i-1]>0){
            left[i]=left[i-1];
            left_sum[i]=data[i]+left_sum[i-1];
        }
        else{
            left[i]=i;
            left_sum[i]=data[i];
        }
        if(max_sum<left_sum[i]){
            max_sum=left_sum[i];
            max_index=i;
        }
    }
    if(max_sum<0){
        printf("0 %d %d",data[0],data[num-1]);
    }
    else
    printf("%d %d %d",max_sum,data[left[max_index]],data[max_index]);
    
}