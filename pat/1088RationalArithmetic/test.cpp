#include<iostream>
typedef long long ll;
using namespace std;

ll lcm(ll a,ll b){
	return a%b==0?b:lcm(b,a%b);
}

ll gcd(ll a,ll b){
	return a*b/lcm(a,b);
}

void simplify(ll *a){
	if(a[0]==0){
		a[1]=1;
		return;
	}
	else if(a[1]==0){
		a[0]=1;
		return;
	}
	else{
		ll common=lcm(abs(a[0]),abs(a[1]));
		a[0]=a[0]/common;
		a[1]=a[1]/common;
	}
}

bool pulss(ll *a,ll *b,ll *res){
	res[0]=a[0];
	res[1]=a[1];
	if(a[1]==0||b[1]==0)return false;
	else{
		ll common=gcd(a[1],b[1]);
		res[0]=a[0]*common/a[1]+b[0]*common/b[1];
		res[1]=common;
	}
	return true;
}

bool times(ll *a,ll *b,ll *res){
	res[0]=a[0]*b[0];
	res[1]=a[1]*b[1];
	if(res[1]==0)return false;
	simplify(res);
	return true;
}

string show(ll *b){
	ll a[2]={b[0],b[1]};
	string res="";
	if(a[1]==0)return "1/0";
	if(a[0]*a[1]>0){
		a[0]=abs(a[0]);
		a[1]=abs(a[1]);
		if(a[0]/a[1]>0)res=to_string(a[0]/a[1]);
		if(a[0]/a[1]>0&&a[0]%a[1]>0)res+=" ";
		if(a[0]%a[1]>0){
			res+=to_string(a[0]%a[1])+"/"+to_string(a[1]);
		}
		return res;
	}
	else if(a[0]*a[1]<0){
		res="(-";
		a[0]=abs(a[0]);
		a[1]=abs(a[1]);
		if(a[0]/a[1]>0)res+=to_string(a[0]/a[1]);
		if(a[0]/a[1]>0&&a[0]%a[1]>0)res+=" ";
		if(a[0]%a[1]>0){
			res+=to_string(a[0]%a[1])+"/"+to_string(a[1]);
		}
		res+=")";
		return res;
	}
	else{
		return "0";
	}
}

int main(){
	ll a[2],b[2];
	scanf("%lld/%lld %lld/%lld",&a[0],&a[1],&b[0],&b[1]);
	simplify(a);
	simplify(b);
	string str[2]={show(a),show(b)};
	ll res[2];
	cout<<str[0]<<" + "<<str[1]<<" = ";
	if(pulss(a,b,res)){
		cout<<show(res)<<"\n";
	}
	else{
		cout<<"Inf\n";
	}
	cout<<str[0]<<" - "<<str[1]<<" = ";
	ll temp[2]={-1*b[0],b[1]};
	if(pulss(a,temp,res)){
		cout<<show(res)<<"\n";
	}
	else{
		cout<<"Inf\n";
	}
	cout<<str[0]<<" * "<<str[1]<<" = ";
	if(times(a,b,res)){
		cout<<show(res)<<"\n";
	}
	else{
		cout<<"Inf\n";
	}
	cout<<str[0]<<" / "<<str[1]<<" = ";
	temp[0]=b[1];
	temp[1]=b[0];
	if(times(a,temp,res)){
		cout<<show(res);
	}
	else{
		cout<<"Inf\n";
	}

}
