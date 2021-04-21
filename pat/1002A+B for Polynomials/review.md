# A+B for Polynomials

**This time, you are supposed to find A+B where A and B are two polynomials.**

## Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: 

K $$ N_1 a_{N_1} \ N_2 a_{N_2} \ .... \ N_K a_{N_K} \ $$

where K is the number of nonzero terms in the polynomial, $$ N_i $$and$$  a_{N_i}$$   (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that  1≤K≤10，0≤$$N_K$$<⋯<$$N_2$$<$$N_1$$≤1000.

## Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must  be NO extra space at the end of each line. Please be accurate to 1  decimal place.

## 思路

使用map数据结构,逐个添加,这里使用c++时需要使用到其map的下表运算,可以写出简洁的代码(见<<c++ primer>> p388)

遇见重复键时,改变其值为他们的总和

## 注意点

当一个节点值为0时,删除该节点

## 代码

```c++	
#include<iostream>
#include<map>
#include<vector>
int main(){
    int len;
    std::map<int,float> maps;
    for(int i=0;i<2;i++){
        std::cin>>len;
        for(int j=0;j<len;j++){
            int exp,coff;
            std::cin>>exp;
            std::cin>>coff;
            maps[exp]+=coff;
        }
    }
    std::vector< std::pair<int,float> > res;
    for(std::map<int,float>::reverse_iterator it=maps.rbegin();it!=maps.rend();it++){
        if(it->second!=0){
            res.push_back({it->first,it->second});
        }
    }
    printf("%d",res.size());
    for(int i=0;i<res.size();i++)
        {
            printf(" %d %.1f",res[i].first,res[i].second);
        }
}
```





