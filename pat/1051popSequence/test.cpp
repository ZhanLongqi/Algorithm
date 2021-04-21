#include<iostream>
#include<stack>
int main(){
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    int origin[N];
    for(int i=0;i<N;i++){
        origin[i]=i+1;
    }
    int data[K][N];
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&data[i][j]);
        }
    }

    for(int i=0;i<K;i++){
        int ip=0,jp=0;
        std::stack<int> st;
        while(ip<N&&jp<N){
           // std::cout<<"ip: "<<ip<<" jp: "<<jp<<std::endl;
            if(ip<N&&st.size()!=M){
                st.push(origin[ip]);
                ip++;
            }
            while(jp<N&&!st.empty()&&data[i][jp]==st.top()){
                st.pop();
                jp++;
            }
            if(st.size()==M){
                break;
            }
        }
        if(ip==N&&jp==N){
            std::cout<<"YES"<<std::endl;
        }
        else{
            std::cout<<"NO"<<std::endl;
        }
    }
}