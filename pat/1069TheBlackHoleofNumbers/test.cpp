#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp0(int i0,int i1){
	return i0<i1;
}

bool cmp1(int i0,int i1){
	return i0>i1;
}

int order(int num){
	vector<int> nums(4);
	for(int i=3;i>=0;i--){
		nums[i]=num%10;
		num=num/10;
	}
	sort(nums.begin(),nums.end(),cmp0);
	int result=0;
	for(int i=0;i<4;i++){
		result=result*10+nums[i];
	}
	return result;
}

int rev_order(int num){
	vector<int> nums(4);
	for(int i=3;i>=0;i--){
		nums[i]=num%10;
		num=num/10;
	}
	sort(nums.begin(),nums.end(),cmp1);
	int result=0;
	for(int i=0;i<4;i++){
		result=result*10+nums[i];
	}
	return result;
}

string show(int i){
	string str=to_string(i);
	int need=4-str.size();
	for(int t=0;t<need;t++){
		str="0"+str;
	}
	return str;
}


int main(){
	int num;
	cin>>num;
	int num0=rev_order(num),num1=order(num);
	int result;
	while(num0!=0&&result!=6174){
		result=num0-num1;
		cout<<show(num0)<<" - "<<show(num1)<<" = "<<show(result)<<"\n";
		num0=rev_order(result);
		num1=order(result);
	}
}