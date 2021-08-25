#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num_users,num_problems,num_submissions;
vector<int> full_marks;

class student{
	public:
		std::vector<int> score;
		bool hasScore = false;
		int perfect = 0,id,rank=-1;
		student(int id):id(id){
			score.resize(num_problems+1);
			fill(score.begin(),score.end(),-1);
		};
		int sum(){
			int sum=0;
			for(int i : score){
				if(i == -1)continue;
				sum+=i;
			}
			return sum;
		}
		void submit(int problem_id,int partical_score){
			if(partical_score == -1){
				if(score[problem_id] == -1){
					score[problem_id] = 0;
				}
				return;
			}
			else if(partical_score>score[problem_id]){
				score[problem_id] = partical_score;
				hasScore = true;
				if(partical_score == full_marks[problem_id]){
					perfect++;
				}
			}
		}
};

bool cmp(student s1,student s2){
	if(s1.sum() != s2.sum()){
		return s1.sum()>s2.sum();
	}
	else{
		if(s1.perfect != s2.perfect){
			return s1.perfect > s2.perfect;
		}
		else{
			return  s1.id<s2.id;
		}
	}
}

int main(){
	cin>>num_users>>num_problems>>num_submissions;
	full_marks.resize(num_problems+1);
	vector<student> users;
	for(int i=0;i<num_users;i++){
		student temp_student(i+1);
		users.push_back(temp_student);
	}
	for(int i = 0;i< num_problems;i++){
		cin>>full_marks[i+1];
	}
	for(int i=0;i<num_submissions;i++){
		int temp_user_id,temp_problem_id,temp_score;
		cin>>temp_user_id>>temp_problem_id>>temp_score;

		users[temp_user_id-1].submit(temp_problem_id,temp_score);
	}
	sort(users.begin(),users.end(),cmp);
	int rank = 1;
	for(int i=0;i<num_users;i++){
		if(users[i].hasScore){
			if(i != 0 &&users[i].sum() == users[i-1].sum()){
				users[i].rank = users[i-1].rank;
			}
			else{
				users[i].rank = rank;
			}
			printf("%d %05d %d",users[i].rank,users[i].id,users[i].sum());
			for(int j=0;j<num_problems;j++){
				if(users[i].score[j+1]!=-1)
					printf(" %d",users[i].score[j+1]);
				else
					printf(" -");
			}
		printf("\n");
		rank++;
		}
	}

}