#include<iostream>
#include<math.h>
using namespace std;

int main(){
	string num[2];
	int bit;
	cin>>bit;
	cin>>num[0]>>num[1];	
	int pos[2]={num[0].find_first_of("."),num[1].find_first_of(".")};
	for(int i=0;i<2;i++){
		if(pos[i]==-1){
			num[i]=num[i]+".0";
		}
		pos[i]=num[i].find_first_of(".");
	}
	
	int rev_pos[2]={int(num[0].size())-pos[0]-1,int(num[1].size())-pos[1]-1};
	int maxn=max(pos[0],pos[1]),rev_maxn=max(rev_pos[0],rev_pos[1]);
	for(int i=0;i<2;i++){
		for(int j=0;j<maxn-pos[i];j++){
			num[i]="0"+num[i];
		}
		for(int j=0;j<rev_maxn-rev_pos[i];j++){
			num[i]=num[i]+"0";
		}
		pos[i]=num[i].find_first_of(".");
		num[i]=num[i].substr(0,pos[i])+num[i].substr(pos[i]+1);
		//cout<<num[i]<<" "<<pos[i]<<"\n";
	}
	int base[2]={num[0].find_first_not_of("0"),num[1].find_first_not_of("0")};
	for(int i=0;i<2;i++){
		while(num[i].size()-base[i]<bit){
			num[i]+="0";
		}
	}
	int exp[2]{pos[0]-num[0].find_first_not_of("0"),pos[1]-num[1].find_first_not_of("0")};
	if(num[0].substr(0,bit)==num[1].substr(0,bit)){
		cout<<"YES ";
		if(base[0]==-1){
			base[0]=0;
			exp[0]=0;
		}
		cout<<"0."<<num[0].substr(base[0],bit)<<"*10^"<<exp[0];
	}
	else{
		cout<<"NO ";
		if(base[0]==-1){
			base[0]=0;
			exp[0]=0;
		}
		cout<<"0."<<num[0].substr(base[0],bit)<<"*10^"<<exp[0]<<" ";

		if(base[1]==-1){
			base[1]=0;
			exp[1]=0;
		}
		cout<<"0."<<num[1].substr(base[1],bit)<<"*10^"<<exp[1];

	}
}