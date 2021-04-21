#include<iostream>
#include<vector>

using namespace std;

int main(){
    int num1,num2;
    vector<int> n1,n2;
    cin>>num1;
    for(int i=0;i<num1;i++){
        int temp;
        cin>>temp;
        n1.push_back(temp);
    }
    cin>>num2;    
    for(int i=0;i<num2;i++){
        int temp;
        cin>>temp;
        n2.push_back(temp);
    }
    int median=(num1+num2+1)/2;
    int i=0,j=0;
    for(int k=0;k<median;k++){
        if(n1[i]<=n2[j]){
            if(k==median-1){
                cout<<n1[i];
            }
            i++;
        }
        else{
            if(k==median-1){
                cout<<n2[j];
            }
            j++;
        }
    }

}