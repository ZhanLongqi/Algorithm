#include<iostream>
#include<vector>
#include<set>
#include<assert.h>
using namespace std;
int main(){
	int num;
	cin>>num;
	string origin;
	cin>>origin;
	string str=origin;
	int repeated[300];
	vector<char> appear;
	fill(&repeated[0],&repeated[300],num);
	int t=1;
	appear.push_back(str[0]);
	for(int i=1;i<=str.size();i++){
		bool appeared=false;
		for(int j=0;j<appear.size();j++){
			if(str[i]==appear[j])
				appeared=true;
		}
		if(!appeared){
			appear.push_back(str[i]);
		}
		if(str[i]==str[i-1]){
			t++;
			if(t==num+1)t=1;
		}
		else{
			if(t<=repeated[str[i-1]]){
				repeated[str[i-1]]=t;
			}
			t=1;
		}
	}
	vector<char> k;
	string u="";
	for(int i=0;i<appear.size();i++){
		if(repeated[appear[i]]==num){
			u+=appear[i];
			k.push_back(appear[i]);
		}
		
	}
	printf("%s\n",u.c_str());
	for(int i=0;i<k.size();i++){
		string s="";
		for(int j=0;j<num;j++){
			s+=k[i];
		}
		int t=origin.find(s);
		int min_index=0;
		while(t!=-1){
			origin.replace(t,num,s.substr(0,1));
			min_index=t+1;
			t=origin.find(s,min_index);
		}
	}
	printf("%s",origin.c_str());
}