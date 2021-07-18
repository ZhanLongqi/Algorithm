#include<iostream>
#include<vector>
using namespace std;

vector<string> standardlize(vector<string> str,int bit,int & exp){
	int pos[2]={str[0].find_first_of("."),str[1].find_first_of(".")};
	for(int i=0;i<2;i++){
		if(pos[i]==-1){
			str[i]+=".0";
			pos[i]=str[i].find_first_of(".");
		}
	}
	int maxn=max(pos[0],pos[1]);
	for(int i=0;i<2;i++){
		for(int j=0;j<maxn-pos[i];j++){
			str[i]="0"+str[i];
		}
		pos[i]=str[i].find_first_of(".");
	}
	int rev_maxn=max(str[0].size()-pos[0],str[1].size()-pos[1]);
	for(int i=0;i<2;i++){
		string append="";
		for(int j=0;j<rev_maxn-(str[i].size()-pos[i]);j++){
			append+="0";
		}
		str[i]+=append;
		append="";
		for(int j=0;j<bit;j++){
			append+="0";
		}
		str[i]+=append;
	}
	str[0]=str[0].substr(0,pos[0])+str[0].substr(pos[0]+1);
	str[1]=str[1].substr(0,pos[1])+str[1].substr(pos[1]+1);
	exp=pos[0];
	vector<string> result;
	result.push_back(str[0]);
	result.push_back(str[1]);
	return result;
}

string show(string str,int exp,int bit){
	int base=str.find_first_not_of("0");
	//cout<<"exp: "<<exp<<" base: "<<base<<"\n";
	if(base==-1){
		base=0;
		exp=0;
	}
	else{
		exp=exp-base;
	}
	string result="";
	
	result="0."+str.substr(base,bit)+"*10^"+to_string(exp);
	return result;
}

int main(){
	int bit,exp;
	vector<string> num(2);
	cin>>bit>>num[0]>>num[1];
	num=standardlize(num,bit,exp);
	//cout<<num[0]<<"  "<<num[1]<<"\n";
	int base[2]={num[0].find_first_not_of("0"),num[1].find_first_not_of("0")};
	string result[2]={show(num[0],exp,bit),show(num[1],exp,bit)};
	if(result[0].substr(2,bit)==result[1].substr(2,bit)&&result[0].substr(result[0]\
	.find_last_of("^")+1)==result[1].substr(result[1].find_last_of("^")+1)){
		cout<<"YES "<<result[0];
	}
	else{
		cout<<"NO "<<result[0]<<" "<<result[1];
	}
}