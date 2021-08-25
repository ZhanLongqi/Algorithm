#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<string> sentences;
	int num;
	string trash;
	cin>>num;
	getline(cin,trash);
	
	for(int i = 0; i < num; i++){
		string temp;
		getline(cin,temp);
		sentences.push_back(temp);
	}
	string result="";	
	bool flag = false;
	for(int i = 0;i <=256&&i<sentences[0].size()&&!flag;i++){
		string temp = sentences[0].substr(sentences[0].size()-1-i);
		for(int j = 1;j < num;j++){
			if(i>=sentences[j].size()||sentences[j].substr(sentences[j].size()-1-i) != temp){
				flag = true;
				break;
			}
		}
		if(!flag)
		result = temp;
	}
	if(result != "")
		cout<<result;
	else
		cout<<"nai";
}