#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

class student{
	public:
		string name;
		int height;
	student(){};
};

bool cmp1(student a,student b){
	if(a.height!=b.height) return a.height<b.height;
	return a.name>b.name;
}
bool cmp2(student a,student b){
	if(a.height=b.height)return a.height<b.height;
	return a.name<b.name;
}

int main(){
	int num,len,num_group;
	cin>>num>>num_group;
	len=num/num_group;
	vector<student> s(num);
	for(int i=0;i<num;i++){
		cin>>s[i].name>>s[i].height;
	}
	sort(s.begin(),s.end(),cmp1);
	vector<vector<student>> row(num_group);
	for(int i=0;i<len*num_group;i++){
		row[i/len].push_back(s[i]);
	}
	for(int i=len*num_group;i<num;i++){
		row[num_group-1].push_back(s[i]);
	}
	vector<string> res;
	for(int i=num_group-1;i>=0;i--){
		res.clear();
		int m=row[i].size();
		res.resize(m);
		int dis=1;
		res[m/2]=row[i].back().name;
		row[i].pop_back();
		while(dis<=m/2){
			res[m/2-dis]=row[i].back().name;
			row[i].pop_back();
			if(!row[i].empty()){
				res[m/2+dis]=row[i].back().name;
				row[i].pop_back();
			}
			dis++;
		}
		for(int i=0;i<res.size();i++){
			if(i!=0)printf(" ");
			printf("%s",res[i].c_str());
		}
		printf("\n");
	}
}