#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	int num;
	cin>>num;
	vector<int> vec;
	map<int,int> m;
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		vec.push_back(temp);
		m.insert(make_pair(temp,i));
	}
	bool not_ordered=true;
	int count=0;
	while(not_ordered){
		count++;
		int pos_of_zero=m[0];
		if(pos_of_zero!=0){
			int swap_target=pos_of_zero;
			int swap_pos=m[pos_of_zero];
			swap(vec[pos_of_zero],vec[swap_pos]);
			m[0]=swap_pos;
			m[swap_target]=swap_target;
		}
		else{
			int ordered=0;
			for(int i=1;i<num;i++){
				if(vec[i]!=i){
					m[vec[i]]=0;
					swap(vec[0],vec[i]);
					m[0]=i;
					break;
				}
				ordered++;
			}
			if(ordered==num-1)not_ordered=false;
		}
	}
	cout<<count-1;
}