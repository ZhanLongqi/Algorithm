#include<iostream>
#include<cctype>

using namespace std;

int main(){
	string s0,s1,ans;
	cin>>s0>>s1;
	for(int i=0;i<s0.size();i++){
		if(s1.find(s0[i])==string::npos&&ans.find(toupper(s0[i]))==string::npos)
			ans.push_back(toupper(s0[i]));
	}
	cout<<ans;
}