#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void downAdapt(vector<int> &heap,int len){
	swap(heap[0],heap[len]);
	int k=0,next=1;
	while (next<len)
	{
		if(next+1<len-1&&heap[next+1]>=heap[next])next++;
		if(heap[k]<=heap[next]){
			swap(heap[k],heap[next]);
			k=next;
			next=k*2+1;
		}
		else{
			break;
		}
	}
}

int main(){
	int num;
	cin>>num;
	vector<int> ori(num),curr(num);
	for(int i=0;i<num;i++){
		cin>>ori[i];
	}
	for(int i=0;i<num;i++){
		cin>>curr[i];
	}
	bool insert=true;
	int ordered=1,k=0;
	while(curr[ordered]>=curr[ordered-1]){
		ordered++;
	}
	while (ordered+k<num)
	{
		if(curr[ordered+k]!=ori[ordered+k]){
			insert=false;
		}
		k++;
	}
	if(insert){
		printf("Insertion Sort\n");
		sort(curr.begin(),curr.begin()+ordered+1);
	}
	else{
		printf("Heap Sort\n");
		ordered=num-1;
		while(curr[ordered]>curr[0]){
			ordered--;
		}
		downAdapt(curr,ordered);
	}
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
			cout<<curr[i];
	}
	
}