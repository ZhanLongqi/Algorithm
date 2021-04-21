#include<iostream>
#include<vector>
int main(){
    std::string str;
    std::cin>>str;
    long sum=0;
    for(int i=0;i<str.length();i++){
        sum+=str[i]-'0';
    
    }
    if(sum==0){
        printf("zero");
        return 0;
    }
    std::string digit[10];
    digit[0]="zero";
    digit[1]="one";
    digit[2]="two";
    digit[3]="three";
    digit[4]="four";
    digit[5]="five";
    digit[6]="six";
    digit[7]="seven";
    digit[8]="eight";
    digit[9]="nine";
    std::vector<std::string> ans;
    while (sum!=0)
    {
        int temp=sum%10;
        ans.push_back(digit[temp]);
        sum/=10;
    }
    for(int i=0;i<ans.size();i++){
        if(i!=0){
            printf(" ");
        }
        std::cout<<ans[ans.size()-1-i];
    }
}