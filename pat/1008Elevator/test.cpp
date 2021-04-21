#include<iostream>

int main(){
    int num;
    scanf("%d",&num);
    int request[num];
    int move[num];
    int sum=0;
    for(int i=0;i<num;i++){
        scanf("%d",&request[i]);
        if(i==0){
            move[0]=request[0];
        }
        else{
            move[i]=request[i]-request[i-1];
        }
        sum+=(move[i]>0?6:4)*abs(move[i])+5;
    }
    printf("%d",sum);
}