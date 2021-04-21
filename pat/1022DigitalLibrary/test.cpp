#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
const int num=6;
using namespace std;

vector<string> split(string target,char spl){
    vector<string> result;
    result.push_back("");
    int count=0;
    for(int i=0;i<target.size();i++){
        if(target[i]==' '){
            count++;
            result.push_back("");
            continue;
        }
        result[count]+=target[i];
    }
    return result;
}

     set<string> con(string query,map<string,set<string>> maps[6]){
        for(int i=0;i<6;i++){
            auto iterator=maps[i].find(query);
            if(iterator!=maps[i].end()){
               return (*iterator).second;
            }
        }
        set<string> temp;
        return temp;
    }
class book{
    public:
    static map<string,set<string>> maps[6];

    string ID,published_year;
    string title,author,publisher;
    vector<string> data;
    vector<string> key_words;
    book(){
        for(int i=0;i<6;i++){
            string temp;
            getline(cin,temp);
            data.push_back(temp);
            if(i==3){
                key_words=split(temp,' ');
                for(int j=0;j<key_words.size();j++){
                    auto iterator=maps[3].find(key_words[j]);
                    if(iterator==maps[3].end()){
                        set<string> temp;
                        temp.insert(data[0]);
                        maps[3].insert(make_pair(key_words[j],temp));
                    }
                    else{
                        (*maps[3].find(key_words[j])).second.insert(data[0]);
                    }
                }
            }

            else{
                auto iterator=maps[i].find(data[i]);
                if(iterator==maps[i].end()){
                    set<string> temp;
                    temp.insert(data[0]);
                    maps[i].insert(make_pair(data[i],temp));
                }
                else{
                    (*iterator).second.insert(data[0]);
                }
            }
        }
    }
    
};
map<string,set<string>> book::maps[6];

int main(){
    int num_books,num_query;
    cin>>num_books;
    cin.ignore();
    vector<book> books;
    for(int i=0;i<num_books;i++){
        book temp;
        books.push_back(temp);
    }
    cin>>num_query;
    cin.ignore();

    vector<pair<string,string>> queries;
    
    for(int i=0;i<num_query;i++){
        string temp,temp2;
        string temp_str;
        getline(cin,temp);
        temp2=split(temp,' ')[0];
        temp_str=temp.substr(temp2.size()+1);
        queries.push_back(make_pair(temp2,temp_str));
    }
    vector<pair<int,set<string>>> fault;
    for(int i=0;i<num_query;i++){
    cout<<queries[i].first<<queries[i].second<<endl;
        set<string> temp;
        temp=con(queries[i].second,book::maps);
        
        if(temp.size()==0){
            cout<<"Not Found"<<endl;
        }
        else{
            for(auto j=temp.begin();j!=temp.end();j++){
                cout<<(*j)<<endl;
            }
        }
    }

}