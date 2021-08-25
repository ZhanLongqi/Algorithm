#include<iostream>
#include<math.h>
using namespace std;

int getPrime(int n){
	if(n<=2)return 2;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return getPrime(n+1);
	}
	return n;
}

int main(){
	int Msize,N;
	cin>>Msize>>N;
	int size=getPrime(Msize);
	string res[10001];
	bool occupied[10001]{false};
	int input;
	for(int i=0;i<N;i++){
		cin>>input;
		bool flag = true;
		for(int j=0;j<size/2;j++){
			int pos=(input+j*j)%size;
			if(!occupied[pos]){
				occupied[pos]=true;
				res[i]=to_string(pos);
				flag=false;
				break;
			}
		}
		if(flag){
			res[i]="-";
		}
	}
	for(int i=0;i<N;i++){
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
}