#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int> preOrder,inOrder;

class node{
    public:
        int val;
        node *left,*right;
        node(){};
};

void show(int l,int r){
    for(int i=l;i<=r;i++){
        printf("%d ",preOrder[i]);
    }
    printf("%n");
}

int f(int pre_l,int pre_r,int in_l,int in_r){
    if(pre_l>=pre_r)return preOrder[pre_l];
    int root=preOrder[pre_l];
    int it=0;
    while(inOrder[it+in_l]!=root){
        it++;
    }
    if(it>0){
        return f(pre_l+1,pre_l+it,in_l,in_l+it);
    }
    else if(pre_r-pre_l-it>0){
        return f(pre_l+1+it,pre_r,in_l+it+1,in_r);
    }
    return root;
}



int main(){
    int num;
    cin>>num;
    preOrder.resize(num);
    inOrder.resize(num);
    for(int i=0;i<2;i++){
        for(int j=0;j<num;j++)cin>>(i==0?preOrder[j]:inOrder[j]);
    } 
    printf("%d",f(0,preOrder.size(),0,inOrder.size()));

}