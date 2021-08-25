#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int price[24];
int month=0;
class record{
	public:
		string name;
		int time;
		bool on;
	record(){};
};

class bill{
	public:
	int start,end,fee;
};

class user{
	public:
		string name;
		vector<bill> bills;
		float sum=0.f;
		void f(record a,record b){
			int start=a.time,end=b.time,fee=0;
			while (start<end)
			{
				fee+= price[start%(24*60)/60];
				start++;
			}
			bill t;
			t.start=a.time;
			t.end=b.time;	
			t.fee=fee;
			bills.push_back(t);
			sum+=float(fee)/100.f;
		}
};

int parse(){
	int time[4];
	scanf("%d:%d:%d:%d",&time[0],&time[1],&time[2],&time[3]);
	month=time[0];
	return time[1]*24*60+time[2]*60+time[3];
}

bool cmp(record a,record b){
	return a.time<b.time;
}

bool cmp2(user a,user b){
	return a.name<b.name;
}

void reverse(int t,int * time){
	time[0]=t/(24*60);
	time[1]=t%(24*60)/60;
	time[2]=t%60;
}

int main(){
	int num_record;
	for(int i=0;i<24;i++){
		cin>>price[i];
	}
	cin>>num_record;
	
	vector<record> records;
	for(int i=0;i<num_record;i++){
		string name,on;
		cin>>name;
		int time=parse();
		cin>>on;
		record t;
		t.name=name;
		t.time=time;
		t.on=(on=="on-line"?true:false);
		records.push_back(t);
	}
	sort(records.begin(),records.end(),cmp);	
	map<string,record> m;
	map<string,user> b;
	for(int i=0;i<num_record;i++){
		map<string,record>::iterator it=m.find(records[i].name);
		if(it==m.end()){
			if(records[i].on){
				m.insert(make_pair(records[i].name,records[i]));
			}
		}
		else{
			if(records[i].on&&(*it).second.on){
				m.erase(records[i].name);
				m.insert(make_pair(records[i].name,records[i]));
			}
			else if(!records[i].on&&(*it).second.on){
				map<string,user>::iterator it2=b.find(records[i].name);
				if(it2==b.end()){
					user c;
					c.name=records[i].name;
					b.insert(make_pair(records[i].name,c));
					it2=b.find(records[i].name);
				}
				(*it2).second.f((*it).second,records[i]);
				m.erase(records[i].name);
			}
		}
	}
	vector<user> users;
	map<string,user>::iterator it=b.begin();
	while(it!=b.end()){
		users.push_back((*it).second);
		it++;
	}
	sort(users.begin(),users.end(),cmp2);
	for(int i=0;i<users.size();i++){
		user u=users[i];
		if(u.sum<=0)continue;
		printf("%s %02d\n",u.name.c_str(),month);
		for(int j=0;j<u.bills.size();j++){
			int time[3];
			reverse(u.bills[j].start,time);
			printf("%02d:%02d:%02d ",time[0],time[1],time[2]);
			reverse(u.bills[j].end,time);
			printf("%02d:%02d:%02d %d $%.2f\n",time[0],time[1],time[2],u.bills[j].end-u.bills[j].start,float(u.bills[j].fee)/100.f);

		}
		printf("Total amount: $%.2f\n",u.sum);
	}
	
}