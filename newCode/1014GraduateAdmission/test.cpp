#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student{
	public:
		int G0,G1,id,total;
		vector<int> choises;
		student(){};
};

bool cmp(student &s0,student &s1){
	return s0.total==s1.total?s0.G0>s1.G0:s0.total>s1.total;

}

bool equal(student s0,student s1){
	return s0.G0==s1.G0&&s0.G1==s1.G1;
}

bool cmp2(student &s0,student &s1){
	return s0.id<s1.id;
}

int main(){
	int num_student,num_school,num_choise;
	cin>>num_student>>num_school>>num_choise;
	vector<student> students(num_student);
	vector<int> left(num_school);
	vector<vector<student>> admit(num_school);
	for(int i=0;i<num_school;i++)cin>>left[i];
	for(int i=0;i<num_student;i++){
		students[i].id=i;
		cin>>students[i].G0>>students[i].G1;
		students[i].total=students[i].G0+students[i].G1;
		students[i].choises.resize(num_choise);
		for(int j=0;j<num_choise;j++)cin>>students[i].choises[j];
	}
	sort(students.begin(),students.end(),cmp);
	for(int i=0;i<num_student;i++){
		for(int j=0;j<num_choise;j++){
			int choice=students[i].choises[j];
			if(left[choice]>0||(left[choice]<=0&&equal(students[i],admit[choice].back()))){
				left[choice]--;
				admit[choice].push_back(students[i]);
				break;
			}
		}
	}
	for(int i=0;i<num_school;i++){
		sort(admit[i].begin(),admit[i].end(),cmp2);
		for(int j=0;j<admit[i].size();j++){
			if(j!=0)cout<<" ";
			cout<<admit[i][j].id;
		}
		cout<<"\n";
	}
}