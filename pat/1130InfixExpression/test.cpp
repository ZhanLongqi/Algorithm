#include<iostream>

using namespace std;

struct node{
    string val;
    int left=-1,right=-1;
    node(){};
};

node m[30];

string infix(int pos){
    if(pos==-1)return "";
    string res=infix(m[pos].left)+m[pos].val+infix(m[pos].right);
    if(infix(m[pos].left)!=""||infix(m[pos].right)!=""){
        res="("+res+")";
    }
    return res;
}

int main(){
    int num, root=1;
    cin>>num;
    bool not_root[30]{false};
    for(int i=0;i<num;i++){
        string val;
        int left,right;
        cin>>val>>left>>right;
        if(left!=-1)not_root[left]=true;
        if(right!=-1)not_root[right]=true;
        m[i+1].val=val;
        m[i+1].left=left;
        m[i+1].right=right;
    }
    while(not_root[root])root++;
    string res=infix(root);
    if(res.size()>=3)
    res=res.substr(1,res.size()-2);
    printf("%s",res.c_str());
}