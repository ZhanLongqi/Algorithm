#include<iostream>

using namespace std;

int main(){
	int num1[3],num2[3],res[3];
	scanf("%d.%d.%d",&num1[0],&num1[1],&num1[2]);
	scanf("%d.%d.%d",&num2[0],&num2[1],&num2[2]);
	res[2]=num1[2]+num2[2];
	res[1]=num1[1]+num2[1]+res[2]/29;
	res[0]=num1[0]+num2[0]+res[1]/17;
	res[2]=res[2]%29;
	res[1]=res[1]%17;
	printf("%d.%d.%d",res[0],res[1],res[2]);
}