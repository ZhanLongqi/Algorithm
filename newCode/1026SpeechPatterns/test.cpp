#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	str=str.substr(str.find_first_of("\"")+1);
	str=str.substr(0,str.find_last_of("\""));
	vector<string> s;
	map<string,int> m;
	int it=0;
	string temp="";
	while(it<str.size()){
		if(isalnum(str[it])){
			temp.push_back(tolower(str[it]));
		}
		else if(temp.size()!=0){
			if(m.find(temp)==m.end()){
				m.insert(make_pair(temp,1));
			}
			else{
				m[temp]++;
			}
			temp="";
		}
		it++;
	}
	int max=-1;
	string max_str="";
	for(auto k:m){
		if(k.second>max){
			max=k.second;
			max_str=k.first;
		}
		if(k.second==max&&k.first<max_str){
			max_str=k.first;
		}
	}
	cout<<max_str<<" "<<max;
}