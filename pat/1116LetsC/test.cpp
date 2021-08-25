#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<set>
using namespace std;

bool isPirme(int i){
	if(i<=2)return true;
	for(int j=2;j<=sqrt(i);j++){
		if(i%j==0)return false;
	}
	return true;
}

int main(){
	int num,num_query;
	cin>>num;
	map<string,int> ranklist;
	for(int i=0;i<num;i++){
		string name;
		cin>>name;
		ranklist.insert(make_pair(name,i+1));
	}
	vector<string> query;
	cin>>num_query;
	for(int i=0;i<num_query;i++){
		string q;
		cin>>q;
		query.push_back(q);
	}
	set<string> checked;
	for(int i=0;i<num_query;i++){
		map<string,int>::iterator it=ranklist.find(query[i]);
		set<string>::iterator it2=checked.find(query[i]);
		if(it!=ranklist.end()&&it2==checked.end()){
			checked.insert(query[i]);
		}
		if(it2!=checked.end()){
			printf("%s: Checked\n",query[i].c_str());
			continue;
		}
		printf("%s: ",query[i].c_str());
		if(it==ranklist.end()){
			printf("Are you kidding?\n");
			continue;
		}
		else{
			int rank=(*it).second;
			if(rank==1){
				printf("Mystery Award\n");
			}
			else if(isPirme(rank)){
				printf("Minion\n");
			}
			else{
				printf("Chocolate\n");
			}
		}
	}
}