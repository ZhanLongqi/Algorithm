#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
int num_applicants,num_schools,num_choices;
vector<vector<int>> admit(110);
vector<int> quota(110);
class student{
	public:
	int G0,G1,index,fin;
	vector<int> choice;
	student(int index):index(index){
		choice.resize(num_choices);
	};	
};

bool cmp(student s1 ,student s2){
	if(s1.G0+s1.G1 !=s2.G0+s2.G1) return (s1.G0+s1.G1) >(s2.G0+s2.G1);
	return s1.G0>s2.G0;
}
bool cmp2(student s1,student s2){
	return s1.index<s2.index;
}

bool equal(student s1,student s2){
	return s1.G1==s2.G1&&s1.G0==s2.G0;
}

int main(){
	cin>>num_applicants>>num_schools>>num_choices;
	assert(num_applicants!=0&&num_schools!=0&&num_choices!=0);
	for(int i=0;i<num_schools;i++){
		cin>>quota[i];
	}
	vector<student> students;
	for(int i=0;i<num_applicants;i++){
		student temp(i);
		cin>>temp.G0>>temp.G1;
		for(int j=0;j<num_choices;j++){
			cin>>temp.choice[j];
		}
		students.push_back(temp);
	}
	sort(students.begin(),students.end(),cmp);
	for(int i=0;i<num_applicants;i++){
		for(int j=0;j<num_choices;j++){
			int choise = students[i].choice[j];
			if(admit[choise].size()<quota[choise]||(admit[choise].size()>=quota[choise]&&equal(students[i],students[admit[choise].size()-1]))){
				admit[choise].push_back(students[i].index);
				break;
			}
		}
	}
	for(int i=0;i<num_schools;i++){
		sort(admit[i].begin(),admit[i].end(),cmp2);
		for(int j=0;j<admit[i].size();j++){
			if(j!=0)cout<<" ";
			cout<<admit[i][j];
		}
		cout<<"\n";
	}
}