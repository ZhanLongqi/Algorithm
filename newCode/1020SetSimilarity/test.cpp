#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
	int num_sets,num_query;
	cin>>num_sets;
	vector<set<int>> sets(num_sets);	
	for(int i=0;i<num_sets;i++){
		int temp_num;
		cin>>temp_num;
		while(temp_num--){
			int temp;
			cin>>temp;
			sets[i].insert(temp);

		}
	}
	cin>>num_query;
	vector<pair<int,int>> query;
	for(int i=0;i<num_query;i++){
		int temp[2];
		cin>>temp[0]>>temp[1];
		query.push_back(make_pair(temp[0]-1,temp[1]-1));
	}
	for(int i=0;i<num_query;i++){
		int diff=sets[query[i].first].size()+sets[query[i].second].size();
		int common=0;
		for(int k:sets[query[i].second]){
			if(sets[query[i].first].find(k)!=sets[query[i].first].end()){
				common++;
				diff--;
			}
		}
		printf("%.1f%\n",(float(common)/diff)*100.f);
	}
}