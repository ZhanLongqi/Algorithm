#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

class node{
    public:
        int val;
        node* left=nullptr,*right=nullptr;
        node(){};
};

node *RRrotate(node *root){
    node *m=root->right;
    root->right=m->left;
    m->left=root;
    return m;
}

node *LLrotate(node *root){
    node *m=root->left;
    root->left=m->right;
    m->right=root;
    return m;
}

node *LRrotate(node *root){
    root->left=RRrotate(root->left);
    return LLrotate(root);
}

node *RLrotate(node *root){
    root->right=LLrotate(root->right);
    return RRrotate(root);
}

int getDep(node *root){
    if(root==nullptr)return 0;
    return max(getDep(root->left),getDep(root->right))+1;
}

bool isBalanced(node *root){
    return abs(getDep(root->left)-getDep(root->right))<2;
}

node *insert(node *root,int val){
    if(root==nullptr){
        node * n=new node();
        n->val=val;
        return n;
    }
    if(val<root->val){
        root->left=insert(root->left,val);
        if(!isBalanced(root)){
            if(val<root->left->val){
                root=LLrotate(root);
            }
            else{
                root=LRrotate(root);
            }
        }
    }
    else{
        root->right=insert(root->right,val);
        if(!isBalanced(root)){
            if(val>=root->right->val){
                root=RRrotate(root);
            }
            else{
                root=RLrotate(root);
            }
        }
    }
    return root;
}

int main(){
    int num;
    cin>>num;
    node *root=nullptr;
    for(int i=0;i<num;i++){
        int val;
        cin>>val;
        root=insert(root,val);
    }
    queue<node*> que;
    vector<int> res;
    que.push(root);
    bool complete=true;
    int curr=1,count=1,layer=0;
    while(!que.empty()){
        curr=count;
        count=0;
        bool valid=true;
        for(int i=0;i<curr;i++){
            node * n=que.front();
            res.push_back(n->val);
            que.pop();
            if(n->left!=nullptr){
                que.push(n->left);
                count++;
                if(!valid)complete=false;
            }
            else{
                valid=false;
            }
            if(n->right!=nullptr){
                que.push(n->right);
                count++;
                if(!valid)complete=false;
            }
            else{
                valid=false;
            }
        }
        if(curr!=pow(2,layer)&&count>0)complete=false;
        layer++;
    }
    for(int i=0;i<res.size();i++){
        if(i!=0)printf(" ");
        printf("%d",res[i]);
    }
    if(complete){
        printf("\nYES");
    }
    else{
        printf("\nNO");
    }
}