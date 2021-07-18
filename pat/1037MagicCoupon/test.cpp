#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int n1,int n2){
    return n1>n2;
}

int main(){
    int num_coupon,num_product;
    cin>>num_coupon;
    vector<int> coupon(num_coupon);
    for(int i=0;i<num_coupon;i++){
        cin>>coupon[i];
    }
    sort(coupon.begin(),coupon.end(),cmp);
    cin>>num_product;
    vector<int> product(num_product);
    for(int i=0;i<num_product;i++){
        cin>>product[i];
    }
    sort(product.begin(),product.end(),cmp);
    int i=0,j=0;
    long long sum=0;
    while(i<num_coupon&&coupon[i]>0&&j<num_product&&product[j]>0){
            sum+=coupon[i++]*product[j++];
    }
    i=num_coupon-1,j=num_product-1;
    while(i>=0&&coupon[i]<0&&j>=0&&product[j]<0){
            sum+=coupon[i--]*product[j--];
    }
    cout<<sum;
}