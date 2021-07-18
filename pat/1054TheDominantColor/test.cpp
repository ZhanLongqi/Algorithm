#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;
    vector<int> image;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            int temp;
            cin>>temp;
            image.push_back(temp);
        }
    }
    sort(image.begin(),image.end());
    cout<<image[(M*N)/2];

}