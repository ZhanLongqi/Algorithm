#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_price=INT32_MAX;

class gas_station{
    public:
    float price;
    int dis;
    gas_station(float price,int dis):price(price),dis(dis){};
};

class car{
    public:
    float gas,tank_capatity,dpg,cost=0;
    int pos=0,dis=0;
    car(float gas,float tank_capatity,float dpg):gas(gas),tank_capatity(tank_capatity),dpg(dpg){};
    float left(){
        return gas*dpg;
    }
    float max(){
        return tank_capatity*dpg;
    }
};

int cmp(gas_station g1,gas_station g2){
    return g1.dis<g2.dis;
}

int ga(vector<gas_station> &stations,car c);

int main(){
    int tank,distance,adpg,num_gas_stations;
    cin>>tank>>distance>>adpg>>num_gas_stations;
    vector<gas_station> stations;
    for(int i=0;i<num_gas_stations;i++){
        float temp_price;
        int temp_dis;
        cin>>temp_price>>temp_dis;
        gas_station temp_station(temp_price,temp_dis);
        stations.push_back(temp_station);
    }
    gas_station temp(-1,distance);
    stations.push_back(temp);
    sort(stations.begin(),stations.end(),cmp);
    car c(0.0,tank,adpg);
    ga(stations,c);
}

int ga(vector<gas_station> &stations,car c){
    if(stations[0].dis>0){
    printf("The maximum travel distance = 0.00");
    return 0;
    }
    //cout<<"car at: "<<c.pos<<" gas: "<<c.gas<<" cost: "<<c.cost<<endl;;
    if(c.pos==stations.size()-1){
        printf("%.2f",c.cost);
        return 0;
    }
    if(stations[c.pos].dis+c.max()<stations[c.pos+1].dis){
        printf("The maximum travel distance = %.2f",c.dis+c.max());
        return 0;
    }
    bool cheapest=true;
    int index=c.pos+1;
    for(int i=c.pos+1;i<stations.size();i++){
        if(stations[i].dis>stations[c.pos].dis+c.max()){
            break;
        }
        if(stations[i].price<stations[c.pos].price){
            cheapest=false;
            index=i;
            break;
        }
    }
    if(!cheapest){ 
        //cout<<"getting to the cheapest station: "<<index<<endl;
        int distance=stations[index].dis-stations[c.pos].dis;
        c.cost+=(max(distance/c.dpg-c.gas,(float)0.0))*stations[c.pos].price;
        c.gas=max(c.gas,distance/c.dpg);
    }
    else{
        //cout<<"full the gas"<<endl;
        float need=min(stations[stations.size()-1].dis-c.dis,(int)c.max());
        need=need/c.dpg;
        c.cost+=(need-c.gas)*stations[c.pos].price;
        c.gas=need;
    }
    c.gas-=(stations[c.pos+1].dis-stations[c.pos].dis)/c.dpg;
    c.pos++;
    c.dis=stations[c.pos].dis;
    ga(stations,c);
    return 0;
}