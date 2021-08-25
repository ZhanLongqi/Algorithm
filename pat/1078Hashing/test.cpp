#include<iostream>
#include<math.h>
using namespace std;

int getPrime(int base){
	if(base == 2)
		return 2;
	for(int i = 2;i <= int(sqrt(base));i++){
		if(base%i == 0){
			return getPrime(base+1);
		}
	}
	return base;
}

int main(){
	int Msize,num_input;
	cin>>Msize>>num_input;
	Msize = getPrime(Msize);
	int m[Msize];
	fill(&m[0], &m[0]+Msize, -1);
	for(int i = 0;i < num_input;i++ ){
		if(i != 0)cout<<" ";
		int temp,base;
		cin>>temp;
		base = temp%Msize;
		bool flag = true;
		for(int j = 0;j <= Msize/2;j++)
		{
			if(m[(base+j*j)%Msize] == -1){
				m[(base+j*j)%Msize] = temp;
				cout<<(base+j*j)%Msize;
				flag = false;
				break;
			}
		}
		if(flag)cout<<"-";
	}
	getPrime(1);
}