#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int num;
	cin>>num;
	vector<int> nums(num);
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end(),cmp);
	int n=sqrt(double(num)),m=-1;
	while(n>=1){
		if(num%n==0){
			m=num/n;
			break;
		}
		n--;
	}
	int count=0;
	int matrix[m][n];
	fill(&matrix[0][0],&matrix[0][0]+m*n,-1);
	for(int i=0;i<m/2+m%2;i++){
		for(int a=i;a<=n-i-1;a++){
            if(matrix[i][a]==-1)
			matrix[i][a]=nums[count++];
		}
		for(int a=i+1;a<=m-i-2;a++){
            if(matrix[a][n-i-1]==-1)
			matrix[a][n-i-1]=nums[count++];
		}
		for(int a=n-i-1;a>=i;a--){
            if(matrix[m-i-1][a]==-1)
            matrix[m-i-1][a]=nums[count++];
		}
		for(int a=m-i-2;a>i;a--){
            if(matrix[a][i]==-1)
			matrix[a][i]=nums[count++];
		}
	}
		for(int a=0;a<m;a++){
			for(int b=0;b<n;b++){
				if(b!=0)cout<<" ";
				printf("%d",matrix[a][b]);
			}
			printf("\n");
		}
}