#include<iostream>
#include<vector>

using namespace std;

int main(){
    int num_shuffle;
    cin>>num_shuffle;
    int shuffle[54],result[2][54];
    string dic[]={"S","H","C","D"};


    for(int i=0;i<54;i++){
        cin>>shuffle[i];
        shuffle[i]-=1;
        result[1][i]=i;
        result[0][i]=i;
    }
        

    for(int i=0;i<num_shuffle;i++){
        for(int j=0;j<54;j++){
            result[i%2][shuffle[j]]=result[(i+1)%2][j];
           // cout<<"from "<<j<<" to "<<shuffle[j]<<endl;
        }
    }
    for(int k=0;k<54;k++){
        if(k!=0){
            cout<<" ";
        }

        int index= result[(num_shuffle+1)%2][k];
        if(index<52){
            cout<<dic[index/13]<<index%13+1;
        }
        else{
            cout<<"J"<<index%2+1;
        }
    }

}