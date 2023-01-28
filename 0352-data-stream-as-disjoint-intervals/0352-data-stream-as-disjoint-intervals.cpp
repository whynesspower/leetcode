class SummaryRanges {
public:
    map<int,int>mp;
    // we need to insert and delete a lot of things simultaneously hence we will
    // use map, and not any other DS like 2D Matrix of anything
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        bool merge=false;
        auto it=mp.lower_bound(value);
        if(it!=mp.begin()){
            auto prev= it;
            prev--;
            if(prev->second+1>=value){
                merge=true;
                prev->second=max(prev->second, value);
            }     
        }
        
        if(it!=mp.end()){
            if(it->first-1<=value){

                if(merge){
                    auto prev=it;
                    prev--;
                    if(prev->second >= it->first - 1) {
                        prev->second=max(prev->second, it->second);
                        mp.erase(it);
                    }
                }
                else{
                    merge=true;
                    if(it->first!=value){
                        pair<int,int>p=*it;
                        p.first=min(value, p.first);
                        it= mp.insert(it, p);
                        it++;
                        if(it!=mp.end()){
                            mp.erase(it);
                        }
                    }
                    
                }
            }
        }
        if(!merge){
            mp.insert(it, {value, value});
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto &it:mp){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

