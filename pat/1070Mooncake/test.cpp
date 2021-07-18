#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class mooncake{
	public:
		float price,tons;
		//mooncake(float p,float t):price(p),tons(t){};
};

bool cmp(mooncake m0,mooncake m1){
	return m0.price>m1.price;
}

int main(){
	int kinds_mooncake;
	float demand;
	cin>>kinds_mooncake>>demand;
	vector<mooncake> mooncakes(kinds_mooncake);
	for(int i=0;i<kinds_mooncake;i++){
		cin>>mooncakes[i].tons;
	}
	for(int i=0;i<kinds_mooncake;i++){
		cin>>mooncakes[i].price;
		mooncakes[i].price/=mooncakes[i].tons;
	}
	sort(mooncakes.begin(),mooncakes.end(),cmp);
	float profit=0.f;
	for(int i=0;i<kinds_mooncake;i++){
		float provide=min(demand,mooncakes[i].tons);
		demand-=provide;
		mooncakes[i].tons-=provide;
		profit+=provide*mooncakes[i].price;
		if(demand==0)break;
	}
	printf("%.2f",profit);
}