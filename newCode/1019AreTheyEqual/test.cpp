#include<iostream>

using namespace std;

int main(){
	int num;
	string s[2];
	cin>>num>>s[0]>>s[1];
    int temp0=s[0].find_first_of(".");
    int temp1=s[1].find_first_of(".");
	int pos[2]={temp0,temp1};
	int exp[2]{0};
	for(int i=0;i<2;i++){
		if(pos[i]!=-1){
			s[i]=s[i].substr(0,pos[i])+s[i].substr(pos[i]+1);
		}
		if(pos[i]==-1){
			pos[i]=s[i].size();
		}
		exp[i]=pos[i]-s[i].find_first_not_of("0");
		//if(exp[i]<=0)exp[i]--;
		while(s[i][0]=='0')s[i]=s[i].substr(1);
		if(s[i].size()==0)exp[i]=0;
		while(s[i].size()<num)s[i]+="0";
	}
	if(exp[0]==exp[1]&&s[0].substr(0,num)==s[1].substr(0,num)){
		cout<<"YES 0."<<s[0].substr(0,num)<<("*10^"+to_string(exp[0]));
	}
	else{
		cout<<"NO 0."<<s[0].substr(0,num)<<("*10^"+to_string(exp[0]))<<" 0."<<s[1].substr(0,num)<<("*10^"+to_string(exp[1]));
	}
	
}