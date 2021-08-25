#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class applicant{
	public: 
		int id,G0,G1,sum;
		vector<int> choices;
};

bool cmp(applicant &a0,applicant &a1){
	if(a0.sum!=a1.sum)return a0.sum>a1.sum;
	return a0.G0>a1.G0;
}

bool cmp2(applicant &a0,applicant &a1){
	return a0.id<a1.id;
}

int main(){
	int num_applicant,num_school,num_choices,quota[110];
	cin>>num_applicant>>num_school>>num_choices;
	vector<applicant> applicants;	
	for(int i = 0; i < num_school; i++){
		cin>>quota[i];
	}
	for(int i = 0;i < num_applicant; i++){
		applicant temp;
		cin>>temp.G0>>temp.G1;
		temp.id=i;
		temp.sum=temp.G0+temp.G1;
		temp.choices.resize(num_choices);
		for(int j = 0; j < num_choices; j++){
			cin>>temp.choices[j];
		}
		applicants.push_back(temp);
	}
	sort(applicants.begin(),applicants.end(),cmp);
	vector<vector<applicant>> admit(num_school);
	for(int i = 0;i < num_applicant; i++){
		for(int j = 0;j < num_choices;j++){
			int target = applicants[i].choices[j];
			if(admit[target].size()<quota[target]||(admit[target].size()>=quota[target]&&\
			applicants[i].sum==admit[target].back().sum&&applicants[i].G0==admit[target].back().G0)){
				admit[target].push_back(applicants[i]);
				break;
			}
		}
	}
	for(int i=0;i<num_school;i++){
		sort(admit[i].begin(),admit[i].end(),cmp2);
		for(int j = 0; j < admit[i].size(); j++){
			if(j!=0)cout<<" ";
			cout<<admit[i][j].id;
		}
		cout<<"\n";
	}
}