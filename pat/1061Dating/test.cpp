#include<iostream>

using namespace std;

int main() {
	string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string str[4];
	int date[4];
	for(int i=0;i<4;i++)
		cin>>str[i];
	int it=0;
	while(it<min(str[0].size(),str[1].size())&&str[0][it]!=str[1][it]||str[0][it]<'A'||\
	str[0][it]>'Z'){
		it++;
	}
	date[0]=str[0][it]-'A';
	it++;
	while(it<min(str[0].size(),str[1].size())&&str[0][it]!=str[1][it]||str[0][it]<'0'||\
	str[0][it]>'N'){
		it++;
	}
	date[1]=str[0][it]-'0';
	if(date[1]>9)
		date[1]-=7;
	int count=0;
	while(count<min(str[2].size(),str[3].size())&&str[2][count]!=str[3][count]||str[2][count]\
	<'A'||str[2][count]>'z'){
		count++;
	}
	date[2]=count;
	//cout<<day[0]<<" "<<to_string(date[1])<<":"<<to_string(date[2]);
	printf("%s %02d:%02d",&day[date[0]][0],date[1],date[2]);
}	