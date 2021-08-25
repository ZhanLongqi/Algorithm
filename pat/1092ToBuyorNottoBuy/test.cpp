#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<char> shop,eva,res,miss;
	string temp;
	cin>>temp;
	unsigned int p=0;
	while(p<temp.size()){
		shop.push_back(temp.at(p));
		p++;
	}
	cin>>temp;
	p=0;
	while(p<temp.size()){
		eva.push_back(temp.at(p));
		p++;
	}
	sort(shop.begin(),shop.end());
	sort(eva.begin(),eva.end());
	int last=-1;
	for(int i=0;i<eva.size();i++){
		bool flag=false;
		for(int j=last+1;j<shop.size();j++){
			if(eva[i]==shop[j]){
				flag=true;
				last=j;
				break;
			}
			else if(shop[j]>eva[i]){
				break;
			}
		}
		if(!flag){
			miss.push_back(eva[i]);
		}
	}
	if(miss.empty()){
		printf("Yes %d",shop.size()-eva.size());
	}
	else{
		printf("No %d",miss.size());
	}
}