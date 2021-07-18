#include<iostream>
#include<map>

using namespace std;

int main(){
	string s,t;
	getline(cin,s);
	map<string,int> m;
	pair<string,int> temp("",-1);
	string result="";
	for(int i=0;i<=int(s.size());i++){//This is fucking important!!!It must contain the
		if(isalnum(s[i]))t+=tolower(s[i]);//extra '\n' char to make the last t a word!!!
		else if(t.size()){
			m[t]++;
			t.clear();
		}
	}
	for(auto i:m){
		if(i.second>temp.second)temp=i;
	}
	cout<<result<<" "<<temp.second;
}