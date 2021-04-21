#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int count=0;
class node{
    public:
    node * left,*right;
    int val;
    node(node *left,node *right,int val):val(val),left(left),right(right){

    }

};
node* fun(vector<int> postOrder,vector<int> inOrder);

int main(){
    vector<int> postOrder,inOrder;
    int len;
    cin>>len;
    for(int i=0;i<len;i++){
        int temp;
        cin>>temp;
        postOrder.push_back(temp);
    }
    for(int i=0;i<len;i++){
        int temp;
        cin>>temp;
        inOrder.push_back(temp);
    }
    node * ans=fun(postOrder,inOrder);
    queue<node*> que;
    que.push(ans);
    int count=0;
    while(!que.empty()){
        if(que.front()->left!=nullptr)
        que.push(que.front()->left);
        if(que.front()->right!=nullptr)
        que.push(que.front()->right);
        if(count++!=0){
            cout<<" ";
        }
        cout<<que.front()->val;
        que.pop();
    }
}

node* fun(vector<int> postOrder,vector<int> inOrder){
    //if(count++>5)return nullptr;
    if(postOrder.size()==0)
        return nullptr;
    else if(postOrder.size()==1){
        node * temp=new node(nullptr,nullptr,postOrder[0]);
        return temp;
    }


   /* cout<<"func"<<endl;
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<" ";
    }
    cout<<endl;
    */

    int root=postOrder[postOrder.size()-1];
    int root_index=0;
    while(inOrder[root_index]!=root){
        root_index++;
    }
    vector<int> left_in,right_in,left_post,right_post;
    for(int i=0;i<root_index;i++){
        left_in.push_back(inOrder[i]);
    }
    for(int i=root_index+1;i<inOrder.size();i++){
        right_in.push_back(inOrder[i]);
    }
    for(int i=0;i<left_in.size();i++){
        left_post.push_back(postOrder[i]);
    }
    for(int i=left_in.size();i<postOrder.size()-1;i++){
        right_post.push_back(postOrder[i]);
    }
    node * temp=new node(fun(left_post,left_in),fun(right_post,right_in),root);
    return temp;
}