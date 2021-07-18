#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void show(map<int,int> m){
	for(int i=0;i<m.size();i++){
		cout<<m[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int num,pos=0;
	cin>>num;
	map<int,int> nums;
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		nums.insert(make_pair(temp,i));
	}
	map<int,int>::iterator it=nums.begin();
	int count=0,base=1;
	while(base!=num){
		while(nums[0]!=0){
			int n=nums[0];
			nums[0]=nums[n];
			nums[n]=n;
			count++;
			//show(nums);
		}
		for(int i=base;i<num;i++){
			if(nums[i]!=i){
				nums[0]=nums[i];
				nums[i]=0;
				count++;
				//show(nums);
				break;

			}
			else{
				base++;
			}
		}

	}
	cout<<count;

}

