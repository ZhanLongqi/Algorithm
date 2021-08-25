#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class record{
	public:
		string id;
		int time;
		bool in;
		record(string i,int t,bool b):id(i),time(t),in(b){};
};

bool cmp(record r0,record r1){
	return r0.time<r1.time;
}

int main(){
	int num_record,num_query,max=0;
	cin>>num_record>>num_query;
	int count[24*60*60]{0};
	vector<record> records;
	vector<int> query(num_query);
	map<string,record> included;
	map<string,int> sum;
	vector<string> res;
	for(int i=0;i<num_record;i++){
		string id="",in="";
		int time[3];
		cin>>id;
		scanf("%d:%d:%d",&time[0],&time[1],&time[2]);
		cin>>in;
		record temp_record(id,time[0]*3600+time[1]*60+time[2],in=="in");
		records.push_back(temp_record);
	}		
	for(int i=0;i<num_query;i++){
		int time[3];
		scanf("%d:%d:%d",&time[0],&time[1],&time[2]);
		query[i]=time[0]*3600+time[1]*60+time[2];
	}
	sort(records.begin(),records.end(),cmp);
	for(int i=0;i<num_record;i++){
		auto p=included.find(records[i].id);
		if(sum.find(records[i].id)==sum.end())sum.insert(make_pair(records[i].id,0));
		auto s=sum.find(records[i].id);
		if(records[i].in){
			if(p!=included.end()){
				included.erase(records[i].id);
			}
			included.insert(make_pair(records[i].id,records[i]));
		}
		else if(p!=included.end()){
			int start=(*p).second.time,end=records[i].time;
			(*s).second+=end-start;
			while(start<end){
				count[start]++;
				start++;
			}
			if((*s).second>max){
				max=(*s).second;
				res.clear();
				res.push_back(records[i].id);
			}
			else if((*s).second==max){
				res.push_back(records[i].id);
			}
			included.erase(records[i].id);
		}
	}
	for(int i=0;i<num_query;i++){
		cout<<count[query[i]]<<"\n";
	}
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
	printf(" %02d:%02d:%02d",max/3600,max/60%60,max%60);

}