#include<iostream>
#define maxn 200001
using namespace std;

int pat[maxn],pa[maxn];
int main(){
	string s;
	cin>>s;
	int last=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'){
			int k=i-1;
			while(k>last){
				if(s[k]=='P'){
					pa[i]++;
				}
				k--;
			}
			pa[i]+=pa[last];
			last=i;
		}
	}
	int res=0;
	last=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='T'){
			int k=i-1;
			while(k>last){
				if(s[k]=='A'){
					pat[i]+=pa[k];
				}
				k--;
			}
			pat[i]+=pat[last];
			res+=pat[i];
			res=res%1000000007;
			last=i;
		}
	}
		cout<<res;
	return 0;
}
