#include<iostream>
using namespace std;
int main(){
    float data[9];
    char dic[3];
    dic[0]='W';
    dic[1]='T';
    dic[2]='L';
    for(int i=0;i<9;i++){
        cin>>data[i];
    }
    float result=1.f;
    for(int i=0;i<3;i++){
        float max=-1.f;
        int max_index=-1;
        for(int j=0;j<3;j++){
            if(data[i*3+j]>max){
                max=data[i*3+j];
                max_index=j;
            }
        }
        result*=max;
        cout<<dic[max_index]<<" ";
    }
    result=(result*0.65-1)*2;
    printf("%.2f",result);
}