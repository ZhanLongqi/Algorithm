#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool flag=false;
int maximum=-1;
vector<int> result;
bool cmp(vector<int> a,vector<int> b){
	if(b.size()==0){
		return true;
	}
	int sum=0;
	for(int i=0;i<a.size();i++){
		sum+=a[i];
	}
	int sum2=0;
	for(int i=0;i<b.size();i++){
		sum2+=b[i];
	}
	if(max(sum,sum2)>maximum){
		maximum=max(sum,sum2);
	}
	return sum>sum2;
}
void f(int num,int m,int n,vector<int> res,int max,int sum){
	if(num==0&&m==0){
		if(cmp(res,result))
		result=vector<int>(res);
		flag=true;
		return;
	}
	if((num==0&&m!=0)||(num!=0&&m==0))return;
	for(int i=min(int(sqrt(num)),max);i>=1;i--){
		//printf("checking %d : %d\n",num,i);
		if(i*m+sum<maximum){
			return;
		}
		res.push_back(i);
		f(num-pow(i,n),m-1,n,res,i,sum+i);
		res.pop_back();
	}
}

int main(){
	int num,m,n;
	cin>>num>>m>>n;
	vector<int> res;
	f(num,m,n,res,num,0);
	if(!flag){
		cout<<"Impossible";
	}
	else{
		printf("%d = ",num);
		for(int i=0;i<result.size();i++){
			if(i!=0)cout<<" + ";
			printf("%d^%d",result[i],n);
		}
	}
}