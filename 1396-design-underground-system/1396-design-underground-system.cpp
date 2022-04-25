class UndergroundSystem {
    
public:
    
    unordered_map<int, pair<string, int>> m1;
    unordered_map<string, vector<long long>>m2;
    UndergroundSystem(){
        m1.clear();
        m2.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(m1.find(id)!=m1.end()) return;
        pair<string, int>p={stationName, t};
        m1[id]=p;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p1= m1[id];
        int t2= t-p1.second;
        string aad=p1.first+ ":"+ stationName;
        // pair<string,string>p={p1.first, stationName};
        if(m2.find(aad)!=m2.end()){
            m2[aad].push_back(t2);
        }
        else{
            vector<long long >temp;
            temp.push_back(t2);
            m2[aad]=temp;
        }         
        m1.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        // pair<string, string>p={startStation, endStation};
        string aad=startStation+ ":"+ endStation;
        vector<long long>temp=m2[aad];
        int n= temp.size();
        double sum=0.0;
        for(int i=0;i<n;i++){
            sum+=temp[i];
        }
        return (double)sum/(double)n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */