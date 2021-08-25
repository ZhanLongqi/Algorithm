#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class participant{
	public:
		int index,grade,rank;
};

bool cmp(participant p0,participant p1){
	return p0.grade>p1.grade;
}


int main(){
	int num,size,count=0,num_group=1;
	cin>>num>>size;
	vector<participant> participants(num);
	for(int i=0;i<num;i++){
		cin>>participants[i].grade;
		participants[i].index=i;
	}
	queue<participant> campion;
	for(int i=0;i<num;i++){
		int temp=0;
		cin>>temp;
		campion.push(participants[temp]);
	}
	num_group=num;
	while(!campion.empty()&&num_group!=1){
		count=num_group;
		num_group=count/size+(count%size==0?0:1);
		for(int i=0;i<num_group;i++){
			int max=-1,max_index=-1;
			for(int j=0;j<size&&i*size+j<count;j++){
				participants[campion.front().index].rank=num_group+1;
				if(campion.front().grade>max){
					max=campion.front().grade;
					max_index=campion.front().index;
				}
				campion.pop();
			}
			campion.push(participants[max_index]);
		}
	}
	vector<participant> final;
	while(!campion.empty()){
		final.push_back(campion.front());
		campion.pop();
	}
	sort(final.begin(),final.end(),cmp);
	int r=1;
	for(int i=0;i<final.size();i++)participants[final[i].index].rank=r++;
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<participants[i].rank;
	}
}