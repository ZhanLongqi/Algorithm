#include<iostream>
#include<vector>
using namespace std;

int main(){
	int num_query;
	cin>>num_query;
	vector<long long> query(num_query*3);
	for(int i=0;i<num_query;i++){
		long long int a,b,c;
		cin>>a>>b>>c;
		long long int sum=a+b;
		cout<<"Case #"<<i+1<<": ";
		if(a>0&&b>0&&sum<0)cout<<"true\n";
		else if(a<0&&b<0&&sum>0)cout<<"false\n";
		else if(sum>c)cout<<"true\n";
		else cout<<"false\n";
	}
}