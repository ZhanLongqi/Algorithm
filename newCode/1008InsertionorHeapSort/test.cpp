#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void downAdjust(vector<int> &t,int len){
	int i=0,j=1;
	while(j<=len){
		if(j+1<=len&&t[j+1]>t[j])j=j+1;
		if(t[j]>=t[i])swap(t[j],t[i]);
		i=j;
		j=i*2+1;
	}
}

int main(){
	int num;
	cin>>num;
	vector<int> ori(num),mid(num);
	for(int i=0;i<num;i++)cin>>ori[i];
	for(int i=0;i<num;i++)cin>>mid[i];
	bool insect=true;
	int t=1,ordered=1;
	while(t<num&&mid[t]>=mid[t-1])t++;
	ordered=t;
	while(t<num){
		if(mid[t]!=ori[t])insect=false;
		t++;
	}
	if(insect){
		cout<<"Insertion Sort\n";
		sort(mid.begin(),mid.begin()+ordered+1);		
	}
	else{
		cout<<"Heap Sort\n";
		ordered=num-1;
		while(ordered>0&&mid[0]<=mid[ordered]){
			ordered--;
		}
		swap(mid[0],mid[ordered]);
		downAdjust(mid,ordered-1);
	}
	for(int i=0;i<num;i++){
		if(i!=0)cout<<" ";
		cout<<mid[i];
	}
}