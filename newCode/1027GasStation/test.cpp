#include<iostream>
#include<assert.h>
#define maxn 2001
#define inf 9999
using namespace std;

int num_houses,num_candidates,num_roads,range;
int road[maxn][maxn],dis[maxn];

bool visited[maxn];
int parse(string s){
	if(s[0]=='G'){
		return num_houses+stoi(s.substr(1));
	}
	else{
		return stoi(s);
	}
}

int main(){
	cin>>num_houses>>num_candidates>>num_roads>>range;
	fill(&road[0][0],&road[0][0]+maxn*maxn,inf);
	for(int i=0;i<num_roads;i++){
		string str[2];
		int dis,temp[2];
		cin>>str[0]>>str[1]>>dis;
		temp[0]=parse(str[0]);
		temp[1]=parse(str[1]);
		if(dis<road[temp[0]][temp[1]]){
			road[temp[0]][temp[1]]=dis;
			road[temp[1]][temp[0]]=dis;
		}
	}	
	int res_index=-1,res_min_dis=-1,res_sum=0;
	for(int i=num_houses+1;i<=num_houses+num_candidates;i++){//interating through all candidates
		bool valid=true;	
		fill(&visited[0],&visited[0]+maxn,false);
		fill(&dis[0],&dis[0]+maxn,inf);
		dis[i]=0;
		int sum=0,sample_min_dis=inf,next=-1;
		for(int j=0;j<num_houses+num_candidates;j++){//Dijstra
			int min=inf,next=-1;
			for(int k=1;k<=num_houses+num_candidates;k++){
				if(!visited[k]&&dis[k]<min){
					min=dis[k];
					next=k;
				}
			}
			visited[next]=true;
			if(next<=num_houses){
				if(min>range){
					valid=false;
					break;
				}
				sum+=min;
				if(min<sample_min_dis){
					sample_min_dis=min;
				}
			}
			for(int k=1;k<=num_houses+num_candidates;k++){
				if(!visited[k]&&dis[next]+road[next][k]<dis[k]){
					dis[k]=dis[next]+road[next][k];	
				}
			}
		}
		/*cout<<"Min:\n";
		for(int i=0;i<num_houses+num_candidate;i++)cout<<dis[i+1]<<" ";
		cout<<"\n";*/
		if(!valid)continue;
		if(sample_min_dis>res_min_dis||(sample_min_dis==res_min_dis&&sum<res_sum)){
			res_min_dis=sample_min_dis;
			res_sum=sum;
			res_index=i;
		}
	}
	if(res_index!=-1)
	printf("G%d\n%.1f %.1f",res_index-num_houses,float(res_min_dis),float(res_sum+0.001)/num_houses);
	else
	printf("No Solution");
	
}