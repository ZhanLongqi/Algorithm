#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


int max_order(vector<int> v,int count){
	int num_group=v.size()/count+(v.size()%count==0?0:1);
	for(int i=0;i<num_group;i++){
		int start=i*count;
		int end=min(i*count+count,int(v.size()));
		for(int j=start;j<end-1;j++){
			if(v[j]>v[j+1]){
				return count/2;
			}
		}
	}
	return max_order(v,count*2);
}

int main(){
	int num;
	cin>>num;
	vector<int> origin(num),curr(num);
	for(int i=0;i<2;i++){
		for(int j=0;j<num;j++){
			cin>>(i==0?origin[j]:curr[j]);
		}
	}
	int ordered=1;
	while(ordered<num&&curr[ordered]>=curr[ordered-1]){
		ordered++;
	}
	int k=ordered;
	bool insert=true;
	while(k<num){
		if(curr[k]!=origin[k]){
			insert=false;
			break;
		}
		k++;
	}
	if(insert){
		cout<<"Insertion Sort\n";
		sort(&curr[0],&curr[0]+ordered+1);
	}
	else{
		cout<<"Merge Sort\n";
		ordered=max_order(curr,2)*2;
		int num_group=num/ordered+(num%ordered==0?0:1);
		for(int i=0;i<num_group;i++){
			int begin=i*ordered;
			int end=min(i*ordered+ordered,num);
			sort(&curr[0]+begin,&curr[0]+end);
		}
	}
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<curr[i];
	}
}