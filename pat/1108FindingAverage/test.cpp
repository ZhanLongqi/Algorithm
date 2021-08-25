#include<iostream>
#include<vector>
using namespace std;
vector<string> valid,invalid;

void test(string s){
	string str=s;
	if(str[0]=='-')str=str.substr(1);
	int k=str.find_first_of(".");
	if(k!=0&&str.back()=='0'){
		str=str.substr(0,str.size()-1);
	}
	if(str.find_first_of(".")!=-1&&str.size()-str.find_first_of(".")>3){
		invalid.push_back(s);
		return;
	}
	if(k!=-1)str=str.substr(0,k)+str.substr(k+1);
	for(int i=0;i<str.size();i++){
		if(!isdigit(str[i])){
			invalid.push_back(s);
			return;
		}
	}

	if(stof(str)>1000||stof(str)<-1000){
		invalid.push_back(s);
		return;
	}
	valid.push_back(s);
}

int main(){
	int num;
	cin>>num;
	vector<string> strs(num);
	for(int i=0;i<num;i++){
		cin>>strs[i];
		test(strs[i]);
	}	
	float average=0.f;
	for(int i=0;i<invalid.size();i++){
		printf("ERROR: %s is not a legal number\n",invalid[i].c_str());
	}
	if(valid.size()==0){
		printf("The average of 0 numbers is Undefined");
	}
	else if(valid.size()==1){
		printf("The average of 1 number is %.2f",stof(valid[0]));
	}
	else {
		for(int i=0;i<valid.size();i++)average+=stof(valid[i]);
		average/=valid.size();
		printf("The average of %d numbers is %.2f",valid.size(),average);
	}
}