#include<iostream>
#include<math.h>
typedef long long ll;
using namespace std;

int main(){
	ll num=0;
	scanf("%lld",&num);
	ll max=1,res=num;
	for(ll i=2;i<=sqrt(num);i++){
	    ll j=i,len=0,k=num;
		while(k%j==0){
			k/=j;
			j++;
		}
		len=j-i;
		if(len>max){
			max=len;
			res=i;
		}
	}
	cout<<max<<"\n";
	for(ll i=res;i<res+max;i++){
		if(i!=res)cout<<"*";
		cout<<i;
	}
}