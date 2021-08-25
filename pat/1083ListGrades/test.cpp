#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class student{
	public:
		int grade;
		string name,id;
};

bool cmp(student s0,student s1){
	return s0.grade>s1.grade;
}

int main(){
	int num,low,high;
	cin>>num;
	vector<student> students(num);
	for(int i=0;i<num;i++){
		cin>>students[i].name>>students[i].id>>students[i].grade;
	}	
	cin>>low>>high;
	sort(students.begin(),students.end(),cmp);
	int p=0;
	bool flag=true;
	while(students[p].grade>high)p++;
	while(p<num&&students[p].grade>=low){
		flag=false;
		cout<<students[p].name<<" "<<students[p].id<<"\n";
		p++;
	}
	if(flag)cout<<"NONE";
}