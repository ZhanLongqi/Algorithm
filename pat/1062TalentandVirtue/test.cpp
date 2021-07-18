#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class people{
	public:
	static int L,H;
	int talent,virtue,total;
	int id,judgement;
	people(int id,int talent,int virtue):id(id),talent(talent),virtue(virtue){
		judge();
		total=talent+virtue;
	};
	void judge(){
		if(talent>=H&&virtue>=H){
			judgement=0;//sage
		}
		else if(talent<H&&virtue>=H){
			judgement=1;//nobelman
		}
		else if(talent<H&&virtue<H&&virtue>=talent){
			judgement=2;//fool man
		}
		else{
			judgement=3;//others
		}
	}
};

bool cmp(people p1,people p2){
	if(p1.judgement!=p2.judgement){
		return p1.judgement<p2.judgement;
	}
	else if(p1.total!=p2.total){
		return p1.total>p2.total;
	}
	else if(p1.virtue!=p2.virtue){
		return p1.virtue>p2.virtue;
	}
	else{
		return p1.id<p2.id;
	}
}
int people::H=0;
int people::L=0;
int main(){
	int num_data,L,H;
	cin>>num_data>>L>>H;
	people::L=L;
	people::H=H;
	int invalid=0;
	vector<people> rank;
	for(int i=0;i<num_data;i++){
		int id,talent,virtue;
		cin>>id>>virtue>>talent;
		if(talent>=L&&virtue>=L){
			people temp(id,talent,virtue);
			rank.push_back(temp);
		}	
		else{
			invalid++;
		} 
	}
	sort(rank.begin(),rank.end(),cmp);
	cout<<num_data-invalid<<"\n";
	for(int i=0;i<num_data-invalid;i++){
		cout<<rank[i].id<<" "<<rank[i].virtue<<" "<<rank[i].talent<<" "<<"\n";
	}
}