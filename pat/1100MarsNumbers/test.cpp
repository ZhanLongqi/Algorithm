#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	int num;
	cin>>num;
	string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string up[12]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string,int> dic;
	for(int i=0;i<13;i++){
		dic.insert(make_pair(low[i],i));
	}	
	for(int i=1;i<=12;i++){
		dic.insert(make_pair(up[i-1],i*13));
	}
	vector<string> test(num);
	getchar();
	for(int i=0;i<num;i++){
		getline(cin,test[i]);
	}	
	for(int i=0;i<num;i++){
		if(isalpha(test[i][0])){
			int k=0,res=0;
			while(k<test[i].size()){
				string s=test[i].substr(k,3);
				res+=dic[s];
				k+=4;
			}
			cout<<res<<"\n";
		}
		else{
			string res="";
			int m=stoi(test[i])/13,n=stoi(test[i])%13;
			if(m!=0){
				res+=up[m-1];
			}
			if(m!=0&&n!=0){
				res+=" ";
			}
			if(n!=0){
				res+=low[n];
			}
			if(res.size()==0)res="tret";
			cout<<res<<"\n";
		}
	}

}