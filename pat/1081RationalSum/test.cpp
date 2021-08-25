#include<iostream>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){
	return a%b==0?b:gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

int main(){
	int num;

	cin>>num;
	long long numerator[num],denominator[num];
	for(int i=0;i<num;i++){
		scanf("%ld/%ld",&numerator[i],&denominator[i]);
	}
	long long res[2]={0,1};
	for(int i=0;i<num;i++){
		long long new_denominator=lcm(res[1],denominator[i]);
		res[0] = res[0]*(new_denominator/res[1])+numerator[i]*(new_denominator/denominator[i]);
		res[1] = new_denominator;
		long temp[2]={res[0]/gcd(res[0],res[1]),res[1]/gcd(res[0],res[1])};
		res[0] = temp[0];
		res[1] = temp[1];
	}
	long long integral=res[0]/res[1];
	res[0]=res[0]%res[1];
	if(integral!=0)cout<<integral;
	if(integral!=0&&res[0]!=0)cout<<" ";
	if(res[0]!=0) cout<<res[0]<<"/"<<res[1];
	if(integral==0&&res[0]==0)cout<<"0";
}