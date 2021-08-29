#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
vector<int> n0,n1;
int num;

class node{
    public:
        int val=-1;
        node* left=nullptr,*right=nullptr;
        node(){};
};

vector<int> sub(vector<int> ori,int left,int len){
    vector<int> r;

    for(int i=left;i<left+len;i++){
        r.push_back(ori[i]);
    }
    return r;
}

bool same(vector<int> a,vector<int> b){
    bool res=true;
    set<int> s;
    for(int k:a)s.insert(k);
    for(int k:b)
        if(s.find(k)==s.end())
            res=false;
    return res;
}

int f(vector<int> pre,vector<int> post,node* root){
    if(pre.size()==0){
        return 1;
    }
    if(pre.size()==1){
        root->val=pre[0];
        return pre[0]==post[0]?1:0;
    }
    if(pre[0]!=post.back())return 0;
    int res=0;
    for(int i=0;i<=pre.size()-1;i++){
        vector<int> left0=sub(pre,1,i);
        vector<int> left1=sub(post,0,i);
        vector<int> right0=sub(pre,i+1,pre.size()-i-1);
        vector<int> right1=sub(post,i,post.size()-i-1);
        int k=0;
        node *l=new node,*r=new node();
        k= f(left0,left1,l);
        k*=f(right0,right1,r);
        if(k!=0){
            root->val=pre[0];
            root->left=l;
            root->right=r;
        }
        res+=k;
    }
    return res;
    
}

int inorder(node *root,vector<int> &r){
    if(root==nullptr||root->val==-1)return 0;
    inorder(root->left,r);
    r.push_back(root->val);
    inorder(root->right,r);
}

int main(){
    cin>>num;
    n0.resize(num);
    n1.resize(num);
    for(int i=0;i<num;i++){
        cin>>n0[i];
    }
    for(int i=0;i<num;i++){
        cin>>n1[i];
    }
    int res;
    node n;
    res=f(n0,n1,&n);
    if(res==1)printf("Yes\n");
    else printf("No\n");
    queue<node*> que;
    vector<int> result;
    que.push(&n);
    int curr=1,count=1;
    inorder(&n,result);
    for(int i=0;i<result.size();i++){
        if(i!=0)cout<<" ";
        cout<<result[i];
    }
}