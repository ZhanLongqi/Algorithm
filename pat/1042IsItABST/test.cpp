#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> target ,int start,int end){
    for(int i=start;i<=end;i++){
        cout<<target[i]<<" ";
    }
    cout<<endl;
}

bool checkBST(vector<int> &tree,int start,int end,vector<int> &post){
    if(start>=end){
        if(start==end){
            post.push_back(tree[start]);
            //cout<<"reaching an end: "<<tree[start]<<endl;
        }
        else{
            //cout<<"empty"<<endl;
        }
        return true;
    }

    int left_pointer=start,right_pointer=left_pointer;
    while(left_pointer+1<tree.size()&&tree[left_pointer+1]<tree[start]){
        left_pointer++;
    }

    for(int i=left_pointer+1;i<tree.size();i++){
        if(tree[i]<tree[start]){
            return false;
        }
    }

    right_pointer=left_pointer+1;

    vector<int> post_left,post_right;
    bool result=true;


    result=result&& checkBST(tree,start+1,left_pointer,post_left);

    result=result&& checkBST(tree,right_pointer,end,post_right);

    post.insert(post.end(),post_left.begin(),post_left.end());
    post.insert(post.end(),post_right.begin(),post_right.end());
    post.push_back(tree[start]);
    return result;
}

bool checkMirror(vector<int> tree,int start,int end,vector<int> &post){
    if(start>=end){
        if(start==end){
            post.push_back(tree[start]);
        }
        return true;
    }
    int left_pointer=start,right_pointer=left_pointer;
    while(left_pointer+1<tree.size()&&tree[left_pointer+1]>=tree[start]){
        left_pointer++;
    }
    for(int i=left_pointer+1;i<tree.size();i++){
        if(tree[i]>=tree[start]){
            return false;
        }
    }
    right_pointer=left_pointer+1;
    vector<int> post_left,post_right;
    bool result= checkMirror(tree,start+1,left_pointer,post_left)&&checkMirror(tree,right_pointer,end,post_right);
    post.insert(post.end(),post_left.begin(),post_left.end());
    post.insert(post.end(),post_right.begin(),post_right.end());
    post.push_back(tree[start]);
    return result;
}


int main(){
    int num_node;
    cin>>num_node;
    vector<int> tree(num_node);
    for(int i=0;i<num_node;i++){
        cin>>tree[i];
    }
    vector<int> post;
    bool result=false;
    if(checkBST(tree,0,tree.size()-1,post)){
        result=true;
        cout<<"Yes"<<endl;
    }
    else 
    {
        post.clear();
        if(checkMirror(tree,0,tree.size()-1,post)){
            result=true;
            cout<<"Yes"<<endl;
        }
    }
    if(result){
        for(int i=0;i<post.size();i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<post[i];
        }
    }
    else{
        cout<<"NO";
    }

}