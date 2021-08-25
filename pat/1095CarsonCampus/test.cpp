#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int string2int(){
	int t[3];
	scanf("%d:%d:%d",&t[0],&t[1],&t[2]);
	return t[0]*60*60+t[1]*60+t[2];
}

class record{
	public:
		int time;
		string id;
		bool in;
		record(string id,int t,bool in):id(id),time(t),in(in){
		}
};

bool cmp(record r0,record r1){
	return r0.time<r1.time;
}

int main(){
	int num_record,num_query,max=-1;
	cin>>num_record>>num_query;
	int timeline[60*60*24+1]{0};
	vector<string> res;
	vector<record> records;
	vector<int> query;
	for(int i=0;i<num_record;i++){
		int temp;
		string id,in;
		cin>>id;
		temp=string2int();
		cin>>in;
		record r(id,temp,in=="in");
		records.push_back(r);
	}
	for(int i=0;i<num_query;i++){
		int temp=string2int();
		query.push_back(temp);
	}
	sort(records.begin(),records.end(),cmp);
	map<string,record> m;
	map<string,int> sum;
	for(int i=0;i<records.size();i++){
		record curr=records[i];
		map<string,record>::iterator it=m.find(curr.id);
		if(curr.in==true){
			if(it==m.end()){
				m.insert(make_pair(curr.id,curr));
				sum.insert(make_pair(curr.id,0));
			}
			else{
				m.erase(curr.id);
				m.insert(make_pair(curr.id,curr));
			}	
		}
		else{
			if(it!=m.end()&&(*it).second.in){
				sum[curr.id]+=curr.time-(*it).second.time;
				if(sum[curr.id]>max){
					max=sum[curr.id];
					res.clear();
					res.push_back(curr.id);
				}
				else if(sum[curr.id]==max){
					res.push_back(curr.id);		
				}
				for(int j=(*it).second.time;j<curr.time;j++){
					timeline[j]++;
				}
				m.erase(curr.id);
			}	
		}
	}
	for(int i=0;i<num_query;i++){
		cout<<timeline[query[i]]<<"\n";
	}
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	printf("%02d:%02d:%02d",max/3600,max/60%60,max%(60));
}