#include<iostream>

using namespace std;

int main(){
	string str_num;
	cin>>str_num;
	string num,exp_str;
	int positive=1,exp=0;
	if(str_num[0]=='-'){
		positive=-1;
	}
	else{
		positive=1;
	}
	int dot_pos=str_num.find_first_of("."),e_pos=str_num.find_first_of("E");
	num=str_num.substr(1,dot_pos-1)+str_num.substr(dot_pos+1,e_pos-dot_pos-1);
	exp_str=str_num.substr(e_pos+1);
	exp=stoi(exp_str);
	if(exp>=0){
		if(exp+1>=num.size()){
			int temp=num.size();
			for(int i=0;i<exp+1-temp;i++){
				num=num+"0";
			}
		}
		else{
			num=num.substr(0,exp+1)+"."+num.substr(exp+1);
		}
	}
	else if(exp<0){
		for(int i=0;i<-1*exp;i++){
			if(i==-1*exp-1){
				num="."+num;
			}
			num="0"+num;
		}
	}
	if(positive==-1)
		num="-"+num;
	cout<<num;
}