#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class order{
	public:
	int action,target;
	order(int action,int target):action(action),target(target){};
};

class linked{
	public:
	linked *next_by_value=nullptr,*next_by_order=nullptr,*last_by_value=nullptr,*last_by_order=nullptr;
	int value;
	linked(int value):value(value){};
};

void add(linked *header,linked *target){
	linked *pointer=header->next_by_value;
	linked *last=header;
	if(pointer==nullptr){
		//cout<<"empty\n";
		header->next_by_value=target;
		target->last_by_value=header;
		return;
	}
	while(pointer!=nullptr&&pointer->value<=target->value){
		//cout<<target->value<<" bigger than: "<<pointer->value<<"\n";
		last=pointer;
		pointer=pointer->next_by_value;
	}
	last->next_by_value=target;
	target->last_by_value=last;
	target->next_by_value=pointer;
	if(pointer!=nullptr){
		pointer->last_by_order=target;
	}

}

void remove(linked *header,int target){
	linked *pointer=header->next_by_value;
	linked *last=header;
	while (pointer!=nullptr)
	{
		if(pointer->value==target){
			if(pointer->next_by_value!=nullptr)
			pointer->next_by_value->last_by_value=last;
			if(pointer!=nullptr)
			last->next_by_value=pointer->next_by_value;
			free(pointer);
			return;
		}
		pointer=pointer->next_by_value;
	}
}

int getMid(linked* header,int size){
	//cout<<"size: "<<size<<"  mid: "<<(size+1)/2<<"\n";
	int target=(size+1)/2;
	linked *pointer=header;
	while(target!=0){
		pointer=pointer->next_by_value;
		target--;
	}
	return pointer->value;
}

void show(stack<int> nums){
	cout<<"stack size: "<<nums.size()<<"\n";
	vector<int> temp;
	while(!nums.empty()){
		temp.push_back(nums.top());
		nums.pop();
	}
	for(int i=temp.size()-1;i>=0;i--){
		cout<<temp[i]<<" ";
	}
	cout<<"\n";
}

void show_vec(linked* header){
	int count=0;
	linked *pointer=header->next_by_value;
	while(pointer!=nullptr&&count<10){
		count++;
		cout<<pointer->value<<" ";
		pointer=pointer->next_by_value;
	}
	cout<<"\n";
}

int main(){
	int num_orders;
	cin>>num_orders;
	vector<order> orders;
	stack<int> nums;
	int count=0;
	for(int i=0;i<num_orders;i++){
		string act;
		int target;
		cin>>act;
		if(act=="Push"){
			cin>>target;
			order temp_order(0,target);
			orders.push_back(temp_order);
		}
		else{
			if(act=="Pop"){
				order temp_order(1,-1);
				orders.push_back(temp_order);
			}
			else{
				order temp_order(2,-1);
				orders.push_back(temp_order);
			}
		}
	}

	linked header(-1);
	header.next_by_value=nullptr;
	linked *tail=&header;
	for(int i=0;i<num_orders;i++){
		if(orders[i].action==0){
			count++;
			//cout<<"adding "<<orders[i].target<<"\n";
			linked *temp=new linked(orders[i].target);
			add(&header,temp);
			nums.push(orders[i].target);
		}
		else if(orders[i].action==1){
			if(nums.empty()){
				cout<<"Invalid\n";
				continue;
			}
			count--;
			cout<<nums.top()<<"\n";
			remove(&header,nums.top());
			nums.pop();
		}
		else{
			if(nums.empty()){
				cout<<"Invalid\n";
				continue;
			}
			cout<<getMid(&header,count)<<"\n";
		}

		//show_vec(&header);
	}
}