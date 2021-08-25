#include<iostream>

using namespace std;

int main(){
	int next[100005],val[100005];
	int start=0,num_node=0,len=0;
	int result[100],index[100],ordered[100];
	cin>>start>>num_node>>len;
	for(int i=0;i<num_node;i++){
		int temp;
		cin>>temp;
		index[i]=temp;
		cin>>val[temp]>>next[temp];
	}
	int sum=0,curr=start;

	while(curr!=-1){
		ordered[sum]=curr;
		curr=next[curr];
		sum++;
	}
	for(int i=0;i<sum;i++){
		result[i]=ordered[i];
	}
	for(int i=0;i<sum/len*len;i++){
		int group=i/len,bias=i%len;
		result[i]=ordered[group*len+len-bias-1];
	}
	for(int i=0;i<sum-1;i++)
		printf("%05d %d %05d\n",result[i],val[result[i]],result[i+1]);

	printf("%05d %d -1",result[sum-1],val[result[sum-1]]);
}