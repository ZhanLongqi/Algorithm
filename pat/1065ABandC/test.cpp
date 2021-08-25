#include<iostream>
#include<vector>
using namespace std;

int main(){
	int num_queries;
	cin>>num_queries;
	vector<long long int> queries(num_queries*3);
	for(int i=0;i<num_queries;i++){
		//cin>>queries[i*3]>>queries[i*3+1]>>queries[i*3+2];
		scanf("%d%d%d",&queries[i*3],&queries[i*3+1],&queries[i*3+2]);
	}	
	for(int i=0;i<num_queries;i++){
		cout<<"Case #"<<i+1<<": ";
		long long sum=queries[i*3]+queries[i*3+1];
		if(queries[i*3]>0&&queries[i*3+1]>0&&sum<0){
			cout<<"true";
		}
		else if(queries[i*3]<0&&queries[i*3+1]<0&&sum>0){
			cout<<"false";
		}
		else if(sum>queries[i*3+2]){
			cout<<"true";
		}
		else{
			cout<<"false";
		}
		cout<<"\n";
	}
}