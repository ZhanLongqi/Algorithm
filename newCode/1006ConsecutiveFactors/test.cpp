#include<iostream>
#include<math.h>

typedef long long ll;

using namespace std;

int main(){
	ll num,sqr;
	cin>>num;
	sqr=ll(sqrt(num));
	int max=0;
	int res[2]{0};
	for(ll i=2;i<sqr;i++){
		ll temp=i,s=i;
		while(num%temp==0){
			temp*=++s;
		}
		if(s-i>max){
			max=s-i;
			res[0]=int(i);
			res[1]=int(s-1);
		}
	}
	if(max==0){
		cout<<"1\n"<<num;
		return 0;
	}
	cout<<max<<"\n"<<res[0];
	for(int i=res[0]+1;i<=res[1];i++){
		cout<<"*"<<i;
	}

}