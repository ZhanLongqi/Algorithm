#include<iostream>
#include<map>
using namespace std;
class student{
    public:
    int grade[4];
    string best_course="N/A";
    string ID;
    student(){};
    student(string I,int Ci,int Mi,int Ei){
        grade[0]=Ci;
        grade[1]=Mi;
        grade[2]=Ei;
        ID=I;
        grade[3]=(int)(grade[0]+grade[1]+grade[2])/3;
    };
};
int main(){
    map<string,student> students;
    int N,M;
    scanf("%d %d",&N,&M);
    int bestRank[4]{0},bestRankIndex[4]{0};
    string ID;
    for(int i=0;i<N;i++){
        int C,M,E;
        cin>>ID;
        //scanf("%d%d%d",&C,&M,&E);
        cin>>C>>M>>E;
        student temp(ID,C,M,E);
        students[ID]=temp;
    }
    char dic[4]{'C','M','E','A'};
    string list[M];
    for(int i=0;i<M;i++){
        string ID;
        cin>>ID;
        list[i]=ID;
    }
    for(int i=0;i<M;i++){
        int count[4]{0,0,0,0};
        if(students.find(list[i])==students.cend()){
            if(i!=0)cout<<endl;
            printf("N/A");
            continue;
        }
        student temp=students[list[i]];
        auto it=students.cbegin();
        while(it!=students.cend()){
            for(int j=0;j<4;j++){
                if(it->second.grade[j]>temp.grade[j]){
                    count[j]++;
                }
            }
            it++;
        }
        int min=INT32_MAX,min_index=0;
        for(int j=0;j<4;j++){
            if(count[j]<=min){
                if(count[j]==min&&(j+1)%4>(min_index+1)%4){
                    continue;
                }
                min=count[j];
                min_index=j;
            }
        }
        if(i!=0){
            cout<<endl;
        }
        printf("%d %c",min+1,dic[min_index]);
    }
}