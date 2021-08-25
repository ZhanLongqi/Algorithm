#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main(){
	int num;
	cin>>num;
	vector<bool> res(num);
	fill(res.begin(),res.end(),false);
	for(int i=0;i<num;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		ll temp=a+b;
		if(a>0&&b>0&&temp<0){
			res[i]=true;
		}
		else if(a<0&&b<0&&temp>=0){
			res[i]=true;
		}
		else{
			res[i]=(temp>c);
		}
	}
	for(int i=1;i<=num;i++){
		cout<<"Case #"<<i<<": ";
		if(res[i-1]){
			cout<<"true";
		}
		else{
			cout<<"false";
		}
		cout<<"\n";
	}

}