#include<iostream>
#define inf 10000
#define maxn 2010
#define bias 1e-6
using namespace std;

int num_houses,num_candidates,num_roads,range;
int roads[maxn][maxn],minDis[maxn];
bool visited[maxn];
int getIndex(string s){
	if(s[0]=='G'){
		return stoi(s.substr(1))+num_houses;
	}
	return stoi(s);
}

int main(){
	cin>>num_houses>>num_candidates>>num_roads>>range;
	fill(&roads[0][0],&roads[0][0]+maxn*maxn,inf);
	for(int i=0;i<num_roads;i++){
		string temp_str[2];
		int dis,temp[2];
		cin>>temp_str[0]>>temp_str[1]>>dis;
		temp[0]=getIndex(temp_str[0]);
		temp[1]=getIndex(temp_str[1]);
		if(dis<roads[temp[0]][temp[1]]){
			roads[temp[0]][temp[1]]=dis;
			roads[temp[1]][temp[0]]=dis;
		}
	}
	int closest=-1,dis=0,res=-1,avg=inf,max=-1;
	for(int i=num_houses+1;i<=num_candidates+num_houses;i++){
		dis=0;
		fill(visited,visited+maxn,false);
		fill(minDis,minDis+maxn,inf);
		int mm=inf,curr=-1,mmm=inf;
		//visited[i]=true;
		//for(int j=1;j<=num_houses+num_candidates;j++){
		//	minDis[j]=roads[i][j];
		//}
		curr=i;
		minDis[i]=0;
		for(int j=0;j<num_houses+num_candidates;j++){
			mm=inf;
			for(int k=1;k<=num_houses+num_candidates;k++){
				if(!visited[k]&&minDis[k]<mm){
					mm=minDis[k];
					curr=k;
				}
			}
			if((curr<=num_houses&&mm>range)||curr==-1){
				mmm=inf;
				break;
			}
			visited[curr]=true;
			//cout<<"G"<<i-num_houses<<": min "<<curr<<" "<<minDis[curr]<<"\n";
			if(curr<=num_houses){
				if(mm<mmm)mmm=mm;
				dis+=mm;
				//cout<<"total dis: "<<dis<<"\n";
				//cout<<"min dis: "<<mmm<<"\n";
			}
			for(int k=1;k<=num_houses+num_candidates;k++){
				if(visited[k]==false&&roads[curr][k]+minDis[curr]<minDis[k]){
					//cout<<"refresh: "<<k<<" from "<<minDis[k]<<" to "<<roads[curr]\
					[k]+minDis[curr]<<"\n";
					minDis[k]=roads[curr][k]+minDis[curr];
				}
			}


		}
		if(mmm>range)continue;
		if(mmm>closest||(mmm==closest&&dis<avg)){
			closest=mmm;
			avg=dis;
			res=i;
		}

	}
	if(res==-1){
		cout<<"No Solution";
	}
	else{
		printf("G%d\n%.1f %.1f",res-num_houses,(float)closest,((float)avg)/num_houses+bias);
	}
}