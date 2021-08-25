#include<iostream>

using namespace std;

int main(){
	string dict[4]={" Qian"," Bai"," Shi",""};
	string dict2[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string dict3[3]={" Yi"," Wan",""};
	string num;
	cin>>num;
	if(num[0]=='-'){
		cout<<"Fu ";
		num=num.substr(1);
	}
	while (num.size()<12)num="0"+num;
	string part[3]={num.substr(0,4),num.substr(4,4),num.substr(8,4)};
	string res="";
	for(int i=0;i<3;i++){
		if(part[i]=="0000")continue;
		if(i!=0&&res.size()>0&&res.back()=='0'||(res.size()>0&&part[i][0]=='0'))res+=" ling";
		int pos=0;
		while(part[i][pos]=='0')pos++;
		while(pos<4){
			if(part[i][pos]=='0'){
				while(part[i][pos]=='0'){
					pos++;
				}
				if(pos!=4)res+=" ling";
			}
			else{
				if(res.size()!=0)res+=" ";
				res+=dict2[part[i][pos]-'0']+dict[pos];
				pos++;
			}
		}
		res+=dict3[i];
	}
	if(res.size()==0)cout<<"ling";
	else cout<<res;
}