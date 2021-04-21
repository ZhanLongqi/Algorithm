#include<iostream>  
#include<vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    int len=s.length();
    int n1,n2;
    n1=(len-1)/3;
    n2=(len+2)/3+(len+2)%3-2;
    vector<vector<char>> result(n1+1,vector<char>(n2+2));
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+2;j++){
            result[i][j]=' ';
        }
    }
    for(int i=0;i<s.length();i++){
        if(i<n1){
            result[i][0]=s[i];
        }

        else if(i>=n1&&i<n1+n2+1){
            
            result[n1][i-n1]=s[i];
        }
        
        else{
            result[n1-i%(n1+n2+1)][n2+1]=s[i];
        }
    }
    for(int i=0;i<n1+1;i++){
        if(i!=0)cout<<endl;
        for(int j=0;j<n2+2;j++){
            cout<<result[i][j];
        }
    }
}