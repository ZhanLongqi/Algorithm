#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class user{
	public:
	vector<int> grade;
	int id,perfect=0,sum=0,rank=-1;
	bool hasGrade=false;	
	user(){};
	void update(){
		sum=0;
		for(int k:grade){
			if(k!=-1){
				sum+=k;
			}
		}
	}
};

bool cmp(user a,user b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	else if(a.perfect!=b.perfect){
		return a.perfect>b.perfect;
	}
	else{
		return a.id>b.id;
	}
}

int main(){
	int num_users,num_problems,num_subsmissions;
	cin>>num_users>>num_problems>>num_subsmissions;
	int total[num_problems+1];
	for(int i=1;i<=num_problems;i++){
		cin>>total[i];
	}
	vector<user> users(num_users);
	for(int i=0;i<users.size();i++){
		users[i].id=i+1;
		users[i].grade.resize(num_problems+1);
		fill(&users[i].grade[0],&users[i].grade[0]+num_problems+1,-1);
	}
	for(int i=0;i<num_subsmissions;i++){
		int temp[3];
		cin>>temp[0]>>temp[1]>>temp[2];
		temp[0]=temp[0]-1;
		if(temp[2]==-1&&users[temp[0]].grade[temp[1]]==-1){
			users[temp[0]].grade[temp[1]]=0;
		}
		else if(temp[2]!=-1){
			users[temp[0]].hasGrade=true;
			if(temp[2]>users[temp[0]].grade[temp[1]]){
				users[temp[0]].grade[temp[1]]=temp[2];
				if(temp[2]==total[temp[1]]){
					users[temp[0]].perfect++;
				}
				users[temp[0]].update();
			}

		}
	}
	sort(users.begin(),users.end(),cmp);
	int rank=1;
	for(int i=0;i<num_users;i++){
		if(!users[i].hasGrade)continue;
		if(i!=0&&users[i].sum==users[i-1].sum){
			users[i].rank=users[i-1].rank;
		}
		else{
			users[i].rank=rank;
		}
		printf("%d %05d %d",users[i].rank,users[i].id,users[i].sum);
		for(int j=1;j<=num_problems;j++){
			if(users[i].grade[j]==-1){
				printf(" -");
			}
			else{
				printf(" %d",users[i].grade[j]);
			}
		}
			cout<<"\n";
		rank++;
	}
}