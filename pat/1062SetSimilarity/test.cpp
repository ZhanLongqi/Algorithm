#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	int num_sets,num_query;
	cin>>num_sets;
	vector<set<int>> sets;
	for(int i=0;i<num_sets;i++){
		int num_mem;
		cin>>num_mem;
		set<int> temp_set;
		for(int i=0;i<num_mem;i++){
			int temp;
			cin>>temp;
			temp_set.insert(temp);
		}
		sets.push_back(temp_set);
	}
	cin>>num_query;
	vector<float> result(num_query);
	for(int i=0;i<num_query;i++){
		int query[2],common=0,distinct=0;
		cin>>query[0]>>query[1];
		query[0]--;
		query[1]--;
		set<int> sum;
		set<int>::iterator it=sets[query[0]].begin();
		set<int>::iterator ending=sets[query[0]].end();
		while(it!=ending){
			if(sets[query[1]].find((*it))==sets[query[1]].end()){
				distinct++;
			}
			else{
				common++;
			}
			it++;
		}
		//bool distinct=false;
		result[i]=float(common)/(distinct+sets[query[1]].size())*100;
	}
	for(int i=0;i<num_query;i++){
		printf("%.1f%%\n",result[i]);
	}
}