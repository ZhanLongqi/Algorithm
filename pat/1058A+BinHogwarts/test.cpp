#include<iostream>

using namespace std;

int main(){
	int num[2][3]{0};
	for(int i=0;i<2;i++)
	scanf("%d.%d.%d",&num[i][0],&num[i][1],&num[i][2]);
	int result[3];
	result[2]=(num[0][2]+num[1][2])%29;
	result[1]=(num[0][1]+num[1][1]+(num[0][2]+num[1][2])/29)%17;
	result[0]=num[0][0]+num[1][0]+(num[0][1]+num[1][1]+(num[0][2]+num[1][2])/29)/17;
	printf("%d.%d.%d",result[0],result[1],result[2]);
}