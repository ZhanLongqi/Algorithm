#include<iostream>
#include<vector>
using namespace std;

int main(){
	int num;
	cin>>num;
	vector<string> sentences(num);
	int count=0,n=0;
	getchar();
	while(count<num)getline(cin,sentences[count++]);
	string common=sentences[0];
	for(int i=1;i<num&&common.size()!=0;i++){
		int c=0;
		while(c<sentences[i].size()&&c<common.size()&&common[common.size()-1-c]==sentences[i][sentences[i].size()-1-c]){
			c++;
		}
		common=common.substr(common.size()-c);
	}
	cout<<(common.size()==0?"nai":common);
}