#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
    int address,parent=-1;
    int next;
    char data;
    node(int add,int ne,char d):address(add),next(ne),data(d){};
};

int cmp(node n1,node n2){
    return n1.address<n2.address;
}

node* findNode( vector<node> &nodes,int address){
    int i=0,j=nodes.size();
    while(i<=j){
        int mid=(i+j)/2;
        if(address==nodes[mid].address){
            return (node*)&nodes[mid];
        }
        else if(address<nodes[mid].address){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return nullptr;
}

int main(){
    vector<node> nodes;
    int start0,start1,num_char;
    cin>>start0>>start1>>num_char;
    for(int i=0;i<num_char;i++){
        int temp[2];
        char tempChar;
        cin>>temp[0]>>tempChar>>temp[1];
        node tempNode(temp[0],temp[1],tempChar);
        nodes.push_back(tempNode);
    }
    sort(nodes.begin(),nodes.end(),cmp);
    node *i=findNode(nodes,start0),*j=findNode(nodes,start1);
    if(i==nullptr||j==nullptr){
        cout<<-1;
        return 0;
    }

    i->parent=i->address;
    while(i->next!=-1){
        node* temp=findNode(nodes,i->next);
        temp->parent=i->parent;
        i=temp;
    }
    while(j!=nullptr){
        node *temp=findNode(nodes,j->next);

        if(j->parent!=-1){
            //cout<<temp->address;
            printf("%05d",j->address);
            return 0;
        }
        j=temp;
    }
    cout<<-1;
    return 0;
    
}